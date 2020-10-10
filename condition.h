//
// Created by ccx on 2020/10/9.
//

#ifndef RE_PROJECT_CONDITION_H
#define RE_PROJECT_CONDITION_H
#include <string>
#include <iostream>
#include <map>
#include "my_time.h"
#include <vector>
enum condition {
    CHECK = 1, MEDICINE, HOSPITALIZE
};
class ConditionMap {
    class Check;
    class Medicine;
    class Hospitalize;
    std::map<std::string, Check*> check_map;
    std::map<std::string, Medicine*> medicine_map;
    std::map<std::string, Hospitalize*> hospitalize_map;
public:
    ConditionMap();
    ~ConditionMap();
    bool Change(int, std::string registration);
    bool Erase(int, std::string registration);
    bool Print(int, std::string registration) const;
    double Price(int, std::string registration) const;
    bool outHospital(std::string registration);
};

class ConditionMap::Check {
public:
    double Price() const;
    bool Scan();
    bool Print();
private:
    friend class ConditionMap;
    struct eachCheck {
        eachCheck(std::string name, double price) {
            this->name = name;
            this->price = price;
        }
        std::string name;
        double price;
    };
    std::vector<eachCheck> check_vector;
};
class ConditionMap::Medicine {
public:
    double Price() const;
    bool Print();
    bool Scan();
private:
    friend class ConditionMap;
    struct eachMedicine {
        eachMedicine(int number, std::string medicine_name, double price) {
            this->number = number;
            this->medicine_name = medicine_name;
            this->price = price;
        }
        int number;
        std::string medicine_name;
        double price;
    };
    std::vector<eachMedicine> medicine_vector;
};
class ConditionMap::Hospitalize {
public:
    double Price() const;
    bool Scan();
    bool Print();
private:
    friend class ConditionMap;
    MyTime begin;
    MyTime end;
    double deposit;
    static double each_day_price;
};
#endif //RE_PROJECT_CONDITION_H
