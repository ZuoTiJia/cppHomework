//
// Created by ccx on 2020/10/9.
//
#include "condition.h"
#include "my_time.h"
#include <fstream>
#include <string>
#include <sstream>
double ConditionMap::Hospitalize::each_day_price = 200.0;
ConditionMap conditionMap;
ConditionMap::ConditionMap() {
    std::ifstream f_check("./check"), f_medicine("./medicine"), f_hospitalize("./hospitalize");
    std::string a, registration, name;
    std::stringstream line;
    double b;
    int c;
    Check check;
    Medicine medicine;
    Hospitalize hospitalize;

    while(getline(f_check, a)) {
        line << a;
        line >> registration;
        while(line >> name >> b) {
            check.check_vector.push_back(Check::eachCheck(name, b));
        }
        check_map[registration] = new Check(check);
        check.check_vector.clear();
        line.clear();
    }
    while(getline(f_medicine, a)) {
        line << a;
        line >> registration;
        while(line >> name >> b >> c) {
            medicine.medicine_vector.push_back(Medicine::eachMedicine(c, name, b));
        }
        medicine_map[registration] = new Medicine(medicine);
        medicine.medicine_vector.clear();
        line.clear();
    }
    while(getline(f_hospitalize, a)) {
        line << a;
        std::string begin, end;
        line >> registration >> begin >> end >> c;
        hospitalize.begin = stringToTime(begin);
        hospitalize.end = stringToTime(end);
        hospitalize.deposit = c;
        hospitalize_map[registration] = new Hospitalize(hospitalize);
        line.clear();
    }
    f_check.close();
    f_hospitalize.close();
    f_medicine.close();
}
ConditionMap::~ConditionMap() {
    std::ofstream f_check("./check", std::ios::out),
                  f_medicine("./medicine",std::ios::out),
                  f_hospitalize("./hospitalize", std::ios::out);
    for(auto i:check_map) {
        f_check << i.first << " ";
        for(auto j:i.second->check_vector)
            f_check << j.name << " "
                    << j.price << " ";
        f_check << "\n";
        delete i.second;
    }

    for(auto i:medicine_map) {
        f_medicine << i.first << " ";
        for(auto j:i.second->medicine_vector)
            f_medicine << j.medicine_name << " "
                       << j.price << " "
                       << j.number << " ";
        f_medicine << "\n";
        delete i.second;
    }
    for(auto i:hospitalize_map) {
        f_hospitalize << i.first << " "
                      << i.second->begin.timeString() << " "
                      << i.second->end.timeString() << " "
                      << i.second->deposit << " ";
        f_hospitalize << "\n";
        delete i.second;
    }
}

double ConditionMap::Price(int condition, std::string registration) const {
    switch (condition) {
        case CHECK:
            return check_map.at(registration)->Price();
        case MEDICINE:
            return medicine_map.at(registration)->Price();
        case HOSPITALIZE:
            return hospitalize_map.at(registration)->Price();
    }
    return 0.0;
}
bool ConditionMap::Erase(int condition, std::string registration) {
    switch (condition) {
        case 0:
            return true;
        case CHECK:
            check_map.erase(registration);
            return true;
        case MEDICINE:
            medicine_map.erase(registration);
            return true;
        case HOSPITALIZE:
            medicine_map.erase(registration);
            return true;
    }
    return true;
}
bool ConditionMap::Print(int condition, std::string registration) const {
    switch (condition) {
        case CHECK:
            check_map.at(registration)->Print();
            return true;
        case MEDICINE:
            medicine_map.at(registration)->Print();
            return true;
        case HOSPITALIZE:
            hospitalize_map.at(registration)->Print();
            return true;
    }
    return true;
}
bool ConditionMap::Change(int condition, std::string registration) {
    switch (condition) {
        case CHECK: {
            Check check;
            check.Scan();
            check_map[registration] = new Check(check);
            break;
        }
        case MEDICINE: {
            Medicine medicine;
            medicine.Scan();
            medicine_map[registration] = new Medicine(medicine);
            break;
        }
        case HOSPITALIZE: {
            Hospitalize hospitalize;
            hospitalize.Scan();
            hospitalize_map[registration] = new Hospitalize(hospitalize);
            break;
        }
    }
    return true;
}
bool ConditionMap::outHospital(std::string registration) {
    hospitalize_map[registration]->end = getNowTime();
    return true;
}
double ConditionMap::Check::Price() const{
    double ret(0.0);
    for(auto i:check_vector)
        ret += i.price;
    return ret;
}
bool ConditionMap::Check::Scan() {
    std::string name;
    double a;
    while(1) {
        std::cout << "please enter name\n";
        std::cin >> name;
        while(1) {
            std::cout << "please enter price\n";
            std::cin >> a;
            if(a>0)
                break;
            std::cout << "error";
        }
        int choice;
        check_vector.push_back(eachCheck(name, a));
        std::cout << "do you want to continue?\n"
                  << "1.yes\n";
        std::cin >> choice;
        if(choice != 1)
            break;
    }
    return true;
}
double ConditionMap::Medicine::Price() const {
    double ret(0.0);
    for(auto i:medicine_vector)
        ret += i.price * i.number;
    return ret;
}
bool ConditionMap::Medicine::Scan() {
    std::string name;
    double a;
    int number;
    while(1) {
        std::cout << "please enter medicine name:\n";
        std::cin >> name;
        while(1) {
            std::cout << "please enter price:\n";
            std::cin >> a;
            if(a > 0)
                break;
        }
        while(1) {
            std::cout << "please enter number\n";
            std::cin >> number;
            if(number > 0)
                break;
        }
        medicine_vector.push_back(eachMedicine(number, name, a));
        int choice;
        std::cout << "do you want to continue?\n"
                  << "1.yes\n";
        if(choice != 1)
            break;
    }
    return true;
}
double ConditionMap::Hospitalize::Price() const {
    if(getNowTime()>begin && getNowTime()<end)
        return deposit;
    return (end - begin)*each_day_price;
}
bool ConditionMap::Hospitalize::Scan() {
    std::cout << "begin time:\n";
    begin.Change();
    int day;
    while(1) {
        std::cout << "please enter how much day?";
        std::cin >> day;
        if(day > 0) {
            end = begin + day;
            break;
        }
        std::cout << "please reenter day\n";
    }
    while(1) {
        double a;
        std::cout << "please enter deposit"
                  << "(at lease " << day*each_day_price << "):\n";
        std::cin >> a;
        if(a > each_day_price*day) {
            deposit = a;
            break;
        }
        std::cout << "error deposit is too small\n";
    }
    return true;
}
bool ConditionMap::Check::Print() {
    std::cout << "check:\n";
    for(auto i:check_vector)
        std:: cout << "\t" << i.name << ":" << i.price << "\n";
    return true;
}
bool ConditionMap::Medicine::Print() {
    std::cout << "medicine:\n";
    for(auto i:medicine_vector)
        std:: cout << "\t" << "name:" << i.medicine_name
                   << " price:" << i.price
                   << " number" << i.number << "\n";
    return true;
}
bool ConditionMap::Hospitalize::Print() {
    std::cout << "hospitalize:\n"
              << "\tbegin time:" << begin.timeString() << "\n"
              << "\tend time:" << end.timeString() << "\n"
              << "\tdeposit:" << deposit << "\n";
    return true;
}