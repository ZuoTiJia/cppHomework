//
// Created by ccx on 2020/10/6.
//
#include "record.h"
#include "doctor.h"
#include "my_time.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

RecordList recordList;
double Hospitalize::each_day_price = 200.0;
//=================================
Record::Record() {
    patient = new Patient;
    condition = 0;
}
void Record::ChangeDoctor() {
    extern DoctorVector doctorVector;
    doctor = &doctorVector.Select();
}
void Record::ChangePatient() {
    std::cin >> *patient;
}
Doctor& Record::GetDoctor() const {
    return *doctor;
}

Patient& Record::GetPatient() const {
    return *patient;
}
bool operator == (const Record& record1, const Record& record2) {
    return record1.registration == record2.registration;
}
std::string Record::GetRegistration() const {
    return registration;
}
Record::~Record() {
    delete patient;
}
MyTime Record::GetTime() const {
    return time;
}

std::ostream& operator << (std::ostream& os, const Record& record) {
    os << "registration:";
    os << record.GetRegistration() << "\n";
    os << record.GetDoctor();
    os << record.GetPatient();
    os << "time:";
    os << record.GetTime().TimeString() << "\n";
    if(record.getCondition() == CHECK)
        os << recordList.returnCheck(record.GetRegistration());
    if(record.getCondition() == MEDICINE)
        os << recordList.returnMedicine(record.GetRegistration());
    if(record.getCondition() == HOSPITALIZE)
        os << recordList.returnHospitalize(record.GetRegistration());
    os << std::endl;
    return os;
}
std::istream& operator >>(std::istream& is, Record& record) {
    std::string name;
    int age;
    int work_number;
    std::string time;
    is  >> record.registration
        >> name
        >> age
        >> work_number
        >> time
        >> record.condition;
    extern DoctorVector doctorVector;
    record.doctor = &doctorVector.getDoctor(work_number);
    record.time = stringToTime(time);
    Patient* patient = new Patient(age, name);
    record.patient = patient;
    return is;
}
double Record::GetPrice() const {
    if(condition == CHECK)
        return recordList.returnCheck(registration).price();
    if(condition == MEDICINE)
        return recordList.returnMedicine(registration).price();
    if(condition == HOSPITALIZE)
        return recordList.returnHospitalize(registration).price();
    return 0.0;
}
void Record::ChangeTime() {
    time.changeTime();
}
void Record::ChangeCondition(std::string registration) {
    int choice;
    extern RecordList recordList1;
    std::cout << "what condition?\n"
              << "1.check\n"
              << "2.medicine\n"
              << "3.hospitalize\n"
              << "4.back\n";
    while(1) {
        std::cin >> choice;
        if(choice >=1 && choice <=4)
            break;
        std::cout << "error";
    }
    switch (condition) {
        case 1:
            recordList.check_map.erase(registration);
            break;
        case 2:
            recordList.medicine_map.erase(registration);
            break;
        case 3:
            recordList.hospitalize_map.erase(registration);
            break;
        case 0:
            break;
    }
    switch (choice) {
        case 1: {
            condition = CHECK;
            Check *check = new Check;
            check->scan();
            recordList.check_map[registration] = check;
            break;
        }
        case 2: {
            condition = MEDICINE;
            Medicine *medicine = new Medicine;
            medicine->scan();
            recordList.medicine_map[registration] = medicine;
            break;
        }
        case 3: {
            condition = HOSPITALIZE;
            Hospitalize *hospitalize = new Hospitalize;
            hospitalize->scan();
            recordList.hospitalize_map[registration] = hospitalize;
            break;
        }
        case 4:
            break;
    }
}
int Record::getCondition() const {
    return condition;
}
//==============================================
double Check::price() const{
    double ret(0.0);
    for(auto i:check_vector)
        ret += i.price;
    return ret;
}
void Check::scan() {
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
}
std::istream& operator >> (std::istream& is, Check& check) {
    std::string name;
    double price;
    while(is >> name >> price)
        check.check_vector.push_back(Check::eachCheck(name, price));
    return is;
}
std::ostream& operator << (std::ostream& os, const Check& check) {
    os << "check:\n";
    for(auto i:check.check_vector)
        os << "\t" << i.name <<":" << i.price <<"\n";
    return os;
}
double Medicine::price() const {
    double ret(0.0);
    for(auto i:medicine_vector)
        ret += i.price * i.number;
    return ret;
}
void Medicine::scan() {
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
        std::cout << "do yout want to continue?\n"
                  << "1.yes\n";
        if(choice != 1)
            break;
    }
}
std::istream& operator >> (std::istream& is, Medicine& medicine) {
    std::string name;
    double price;
    int number;
    while(is >> name >> price >> number)
        medicine.medicine_vector.push_back(Medicine::eachMedicine(number, name, price));
    return is;
}
std::ostream& operator << (std::ostream& os, const Medicine& medicine) {
    os << "medicine:\n";
    for(auto i:medicine.medicine_vector)
        os << "\t"
           << "name:" << i.medicine_name << " "
           << "price:"<< i.price << " "
           << "number:" <<i.price << "\n";
    return os;

}
double Hospitalize::price() const {
    if(GetNowTime()>begin && GetNowTime() <end)
        return deposit;
    return (end - begin)*each_day_price;
}
void Hospitalize::scan() {
    std::cout << "begin time:\n";
    begin.changeTime();
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
        }
        std::cout << "error deposit is too small\n";
    }
}
std::istream& operator >> (std::istream& is, Hospitalize& hospitalize) {
    std::string begin;
    std::string end;
    double deposit;
    is >> begin >> end >> deposit;
    hospitalize.begin = stringToTime(begin);
    hospitalize.end = stringToTime(end);
    hospitalize.deposit = deposit;
    return is;
}
std::ostream& operator << (std::ostream& os, const Hospitalize& hospitalize) {
    os << "hospitalize:\n"
       << "\t"
       << "begin:"
       << hospitalize.begin.TimeString() << "\n"
       << "\t"
       << "end:"
       << hospitalize.end.TimeString() << "\n"
       << "\t"
       << "deposit"
       << hospitalize.deposit << "\n";
    return os;
}
// ===========================================
RecordList::RecordList() {
    std::fstream f_record;
    Record record;
    f_record.open("./record");
    while(f_record >> record) {
        Record* p_record = new Record(record);
        PushRecord(*p_record);
    }
    f_record.close();
    checkInit();
    medicineInit();
    hospitalizeInit();
}
Record* RecordList::SearchRecord(const std::string &registration) {
    for(auto i:record_list)
        if(registration == i->GetRegistration())
            return i;
    std::cout << "don,t have" << std::endl;
    return nullptr;
}
std::list<Record*>* RecordList::SearchDoctor() const {
    extern DoctorVector doctorVector;
    int work_number = doctorVector.Select().GetWorkNumber();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(work_number == i->GetDoctor().GetWorkNumber())
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::SearchDepartment() const {
    extern DoctorVector doctorVector;
    int department = doctorVector.selectDepartment();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(department == i->GetDoctor().GetDepartment())
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::SearchPatient() const {
    Patient patient;
    std::cin >> patient;
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(patient == i->GetPatient())
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::SearchTimeSlot() const {
    MyTime begin, end;
    begin.changeTime();
    end.changeTime();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(i->GetTime()>begin && i->GetTime()<end)
            ret->push_back(i);
    return ret;
}
void RecordList::PushRecord(Record& record) {
    record_list.push_back(&record);
}
void RecordList::EraseRecord(const std::string registration) {
    for(auto i=record_list.begin(); i!=record_list.end(); i++)
        if( (*i)->GetRegistration() == registration) {
            if((*i)->getCondition() == CHECK)
                check_map.erase(registration);
            if((*i)->getCondition() == MEDICINE)
                medicine_map.erase(registration);
            if((*i)->getCondition() == HOSPITALIZE)
                hospitalize_map.erase(registration);
            record_list.erase(i);
        }

}
int RecordList::DepartmentRegistration(int department) const {
    int ret = 0;
    for(auto i:record_list)
        if(i->GetTime().isToday() && i->GetDoctor().GetDepartment() == department)
            ret++;
    return ret;
}
int RecordList::AllRegistration() const {
    int ret = 0;
    for(auto i:record_list)
        if(i->GetTime().isToday())
            ret++;
    return ret;
}
void RecordList::checkInit() {
    std::fstream f_check("./check");
    std::string a;
    std::stringstream line;
    std::string registration;
    Check check;
    while(getline(f_check, a)) {
        line << a;
        line >> registration
             >> check;
        check_map[registration] = new Check(check);
        check.check_vector.clear();
        line.clear();
    }
    f_check.close();
}
void RecordList::medicineInit() {
    std::fstream f_medicine("./medicine");
    std::string a;
    std::stringstream  line;
    std::string registration;
    Medicine medicine;
    while(getline(f_medicine, a)) {
        line << a;
        line >> registration
             >> medicine;
        medicine_map[registration] = new Medicine(medicine);
        medicine.medicine_vector.clear();
        line.clear();
    }
    f_medicine.close();
}
void RecordList::hospitalizeInit() {
    std::fstream f_hospitalize("./hospitalize");
    std::string a;
    std::stringstream  line;
    std::string registration;
    Hospitalize hospitalize;
    while(getline(f_hospitalize, a)) {
        line << a;
        line >> registration
             >> hospitalize;
        hospitalize_map[registration] = new Hospitalize(hospitalize);
        line.clear();
    }
}
Check& RecordList::returnCheck(std::string registration) {
    return *check_map[registration];
}
Medicine& RecordList::returnMedicine(std::string registration) {
    return *medicine_map[registration];
}
Hospitalize& RecordList::returnHospitalize(std::string registration) {
    return *hospitalize_map[registration];
}
void RecordList::Print() {
    for(auto i:record_list)
        std::cout << *i;
}
RecordList::~RecordList() noexcept {
    std::ofstream f_record("./record", std::ios::out);
    std::ofstream f_check("./check", std::ios::out);
    std::ofstream f_medicine("./medicine", std::ios::out);
    std::ofstream f_hospitalize("./hospitalize", std::ios::out);
    for(auto i:record_list) {
        f_record << i->GetRegistration() << " "
                 << i->GetPatient().GetName() << " "
                 << i->GetPatient().GetAge() << " "
                 << i->GetDoctor().GetWorkNumber() << " "
                 << i->GetTime().TimeString() << " "
                 << i->getCondition() << "\n";
        delete i;
    }
    for(auto i:check_map) {
        f_check << i.first << " ";
        for(auto j:i.second->check_vector)
            f_check << j.name << " "
                    << j.price << " "
                    << "\n";
        delete i.second;
    }
    for(auto i:medicine_map) {
        f_medicine << i.first << " ";
        for(auto j:i.second->medicine_vector)
            f_medicine << j.medicine_name << " "
                       << j.price << " "
                       << j.number << " ";
        delete i.second;
        f_medicine << "\n";
    }
    for(auto i:hospitalize_map) {
        f_hospitalize << i.first << " "
                      << i.second->begin.TimeString() << " "
                      << i.second->end.TimeString() << " "
                      << i.second->deposit << " ";
        delete i.second;
        f_hospitalize << "\n";
    }
    f_hospitalize.close();
    f_record.close();
    f_medicine.close();
    f_check.close();
}
void printRecordList(std::list<Record*> *list) {
    for(auto i:(*list))
        std::cout << *i;
}
double RecordList::Turnover() {
    double ret(0.0);
    for(auto i:record_list)
        ret +=i->GetPrice();
    return ret;
}

void registration() {
    extern RecordList recordList;
    extern DoctorVector doctorVector;
    if(recordList.AllRegistration() >= 500) {
        std::cout << "you can't registration" << std::endl;
        return;
    }
    Record* record = new Record;
    record->ChangePatient();
    record->ChangeDoctor();
    if(record->doctor->GetTodayWorkStatus() > 20) {
        std::cout << "you can't select this doctor" <<std::endl;
        delete record;
        return;
    }
    record->time = GetNowTime();
    record->registration =
        makeRegistration(record->GetDoctor().GetWorkNumber(), record->time);
    doctorVector.add(record->GetDoctor().GetWorkNumber());
    record->ChangeCondition(record->registration);
    recordList.PushRecord(*record);
}

std::string makeRegistration(int work_number, MyTime time) {
    extern DoctorVector doctorVector;
    char a[10];
    sprintf(a, "%d%02d%02d%02d", work_number,
            time.month, time.month_day,
            doctorVector.GetWorkStatus(work_number));
    return std::string(a);
}
void outHospital() {
    std::string registration;
    std::cout << "please enter registration:\n";
    std::cin >> registration;
    extern RecordList recordList;
    Record *record = new Record;
    record = recordList.SearchRecord(registration);
    if(record == nullptr || record->getCondition() != HOSPITALIZE) {
        std::cout << "don't exit"<< std::endl;
        return;
    }
    recordList.returnHospitalize(registration).end = GetNowTime();
    std::cout <<"sucuss!!" <<std::endl;
}