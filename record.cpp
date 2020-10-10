//
// Created by ccx on 2020/10/6.
//
#include "record.h"
#include "doctor.h"
#include "my_time.h"
#include "condition.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>

RecordList recordList;

//=================================
Record::Record() {
    condition = 0;
}
Record::Record(std::string registration, std::string name, int age, int doctor_number, std::string time, int condition) {
    this->doctor_number = doctor_number;
    this->registration = registration;
    this->patient.name = name;
    this->patient.age = age;
    this->time = stringToTime(time);
    this->condition = condition;
}

int Record::getDoctorNumber() const{
    return doctor_number;
}
Patient Record::getPatient() const {
    return patient;
}
std::string Record::getRegistration() const {
    return registration;
}
MyTime Record::getTime() const {
    return time;
}
int Record::getCondition() const {
    return condition;
}
bool Record::Change() {
    extern DoctorMap doctorMap;
    std::cout << "what do you want to change?\n"
              << "1.change doctor\n"
              << "2.change patient\n"
              << "3.change time\n"
              << "4.change condition\n"
              << "5.back";
    int choice;
    while(1) {
        std::cin >> choice;
        if(choice>=1 && choice<=5)
            break;
        std::cout << "error please reenter5\n";
    }
    switch (choice) {
        case 1:
            doctor_number = doctorMap.selectDoctor();
            break;
        case 2:
            patient.Change();
            break;
        case 3:
            time.Change();
            break;
        case 4:
            changeCondition();
            break;
        case 5:
            break;
    }
    return true;
}
bool operator == (const Record& record1, const Record& record2) {
    return record1.registration == record2.registration;
}

bool Record::Print() const {
    extern DoctorMap doctorMap;
    extern ConditionMap conditionMap;
    std::cout << "registration:" << getRegistration() << "\n";
    doctorMap.printDoctor(doctor_number);
    patient.Print();
    std::cout << "time:" << time.timeString() << "\n";
    conditionMap.Print(condition, registration);
    return true;
}
double Record::getPrice() const {
    extern ConditionMap conditionMap;
    if(condition == CHECK)
        return conditionMap.Price(CHECK, registration);
    if(condition == MEDICINE)
        return conditionMap.Price(MEDICINE, registration);
    if(condition == HOSPITALIZE)
        return conditionMap.Price(HOSPITALIZE, registration);
    return 0.0;
}
bool Record::changeCondition() {
    int choice;
    extern ConditionMap conditionMap;
    std::cout << "what condition?\n"
              << "1.check\n"
              << "2.medicine\n"
              << "3.hospitalize\n";
    while(1) {
        std::cin >> choice;
        if(choice >=1 && choice <=3)
            break;
        std::cout << "error";
    }
    conditionMap.Erase(condition, registration);
    switch (choice) {
        case 1: {
            condition = CHECK;
            conditionMap.Change(condition, registration);
            break;
        }
        case 2: {
            condition = MEDICINE;
            conditionMap.Change(condition, registration);
            break;
        }
        case 3: {
            condition = HOSPITALIZE;
            conditionMap.Change(condition, registration);
            break;
        }
    }
    return true;
}


// ===========================================
RecordList::RecordList() {
    std::fstream f_record;
    Record record;
    f_record.open("./record");
    std::string registration, time, name;
    int doctor_number, age, condition;
    while(f_record >> registration >> name >> age >> doctor_number >> time >> condition) {
        Record* p_record = new Record(registration, name, age, doctor_number, time, condition);
        pushRecord(p_record);
    }
    f_record.close();
}
Record* RecordList::searchRecord(const std::string &registration) {
    for(auto i:record_list)
        if(registration == i->getRegistration())
            return i;
    std::cout << "don,t have" << std::endl;
    return nullptr;
}
std::list<Record*>* RecordList::searchDoctor() const {
    extern DoctorMap doctorMap;
    int work_number = doctorMap.selectDoctor();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(work_number == i->getDoctorNumber())
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::searchDepartment() const {
    extern DoctorMap doctorMap;
    int department = doctorMap.selectDepartment();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(department == doctorMap.getDepartment(i->getDoctorNumber()))
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::searchPatient() const {
    Patient patient;
    patient.Change();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(patient == i->getPatient())
            ret->push_back(i);
    return ret;
}
std::list<Record*>* RecordList::searchTimeSlot() const {
    MyTime begin, end;
    begin.Change();
    end.Change();
    std::list<Record*>* ret;
    ret = new std::list<Record*>();
    for(auto i:record_list)
        if(i->getTime()>begin && i->getTime()<end)
            ret->push_back(i);
    return ret;
}
void RecordList::pushRecord(Record* record) {
    record_list.push_back(record);
}
void RecordList::eraseRecord(const std::string registration) {
    Record *record;
    for(auto i=record_list.begin(); i!=record_list.end(); i++) {
        searchRecord(registration);

    }

}
int RecordList::departmentRegistration(int department) const {
    extern DoctorMap doctorMap;
    int ret = 0;
    for(auto i:record_list)
        if(i->getTime().isToday()  && doctorMap.getDepartment(i->getDoctorNumber()) == department)
            ret++;
    return ret;
}
int RecordList::allRegistration() const {
    int ret = 0;
    for(auto i:record_list)
        if(i->getTime().isToday())
            ret++;
    return ret;
}
RecordList::~RecordList() noexcept {
    std::ofstream f_record("./record", std::ios::out);
    for(auto i:record_list) {
        f_record << i->getRegistration() << " "
                 << i->getPatient().Name() << " "
                 << i->getPatient().Age() << " "
                 << i->getDoctorNumber() << " "
                 << i->getTime().timeString() << " "
                 << i->getCondition() << "\n";
        delete i;
    }
    f_record.close();
}
bool printRecordList(std::list<Record*> *list) {
    for(auto i:(*list))
        i->Print();
    return true;
}
double RecordList::Turnover() {
    double ret(0.0);
    for(auto i:record_list)
        ret +=i->getPrice();
    return ret;
}

void registration() {
    extern RecordList recordList;
    extern ConditionMap conditionMap;
    extern DoctorMap doctorMap;
    if(recordList.allRegistration() >= 500) {
        std::cout << "you can't registration" << std::endl;
        return;
    }
    Record* record = new Record;
    record->patient.Change();
    record->doctor_number = doctorMap.selectDoctor();
    if(doctorMap.getTodayWorkStatus(record->doctor_number) > 20) {
        std::cout << "you can't select this doctor" <<std::endl;
        delete record;
        return;
    }
    record->time = getNowTime();
    record->registration =
        makeRegistration(record->doctor_number, record->time);
    doctorMap.addWorkStatus(record->doctor_number);
    record->changeCondition();
    recordList.pushRecord(record);
    record->Print();
}

std::string makeRegistration(int work_number, MyTime time) {
    extern DoctorMap doctorMap;
    char a[10];
    sprintf(a, "%d%02d%02d%02d", work_number,
            time.month, time.month_day,
            doctorMap.getTodayWorkStatus(work_number));
    return std::string(a);
}
void outHospital() {
    extern ConditionMap conditionMap;
    std::string registration;
    std::cout << "please enter registration:\n";
    std::cin >> registration;
    extern RecordList recordList;
    Record* record;
    record = recordList.searchRecord(registration);
    if(record == nullptr || record->getCondition() != HOSPITALIZE) {
        std::cout << "don't exit"<< std::endl;
        return;
    }
    conditionMap.outHospital(registration);
    std::cout <<"sucuss!!" <<std::endl;
}