//
// Created by ccx on 2020/10/6.
//
#include "doctor.h"
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <ctime>
DoctorMap doctorMap;
DoctorMap::Doctor::Doctor(std::string name, std::string work_time) {
    this->name = name;
    this->work_time = std::bitset<7>(work_time);
    this->today_work = 0;
}


DoctorMap::DoctorMap() {
    std::ifstream f_doctor("./doctor");
    int work_number;
    std::string name;
    std::string work_time;
    while(f_doctor >> work_number >> name >> work_time)
        doctor_map[work_number] = Doctor(name, work_time);
    f_doctor.close();
}
std::string DoctorMap::getName(int work_number) const {
    return (doctor_map.at(work_number).name);
}
int DoctorMap::getTodayWorkStatus(int work_number) const {
    return doctor_map.at(work_number).today_work;
}
int DoctorMap::getDepartment(int work_number) const {
    return work_number/100;
}
int DoctorMap::getRank(int work_number) const {
    int t=work_number;
    t /= 10;
    return t%10;
}
bool DoctorMap::isHave(int work_number) const {
    return doctor_map.count(work_number);
}
bool DoctorMap::isWork(int work_number) const {
    if(doctor_map.at(work_number).today_work>=20)
        return false;
    if(doctor_map.at(work_number).work_time[getTodayWeek()] == 0)
        return false;
    return true;
}
bool DoctorMap::addWorkStatus(int work_number) {
    doctor_map[work_number].today_work++;
    return true;
}
bool DoctorMap::printDoctor(int work_number) const {
    std::cout << "doctor:\n"
    << "\t" << "doctor name:" << getName(work_number) << "\n"
    << "\t" << "department:" << departmentString(getDepartment(work_number)) << "\n"
    << "\t" << "rank:" << rankString(getRank(work_number)) << "\n"
    << "\t" << "work number:" << work_number << "\n"
    << "\t" << "work time:" << workTimeString(doctor_map.at(work_number).work_time) << "\n"
    << "\t" << "today work status:" << getTodayWorkStatus(work_number) <<"\n";
    return true;
}
std::string DoctorMap::departmentString(int department) const {
    std::string ret;
    if(department == SURGERY)
        ret = "surgery";
    if(department == INTERNAL)
        ret = "internal";
    if(department == PHARMACY)
        ret = "pharmacy";
    if(department == PEDIATRIC)
        ret = "pediatric";
    if(department == GYNECOLOGY)
        ret = "gynecology";
    return ret;
}
std::string DoctorMap::rankString(int rank) const {
    std::string ret;
    if(rank == CHIEF_PHYSICIAN)
        ret = "chief physician";
    if(rank == ASSOCIATE_CHIEF_PHYSICIAN)
        ret = "associate chief physician";
    if(rank == ATTENDING_PHYSICIAN)
        ret = "attending physician";
    if(rank == RESIDENT_PHYSICIAN)
        ret = "resident physician";
    return ret;
}
std::string DoctorMap::workTimeString(std::bitset<7> work_time) const {
    std::string ret;
    for(int i=0; i<7; i++)
        if(work_time[i]) {
            ret += weekString(i);
            ret += " ";
        }
    return ret;
}
std::string DoctorMap::weekString(int week_day) const {
    switch (week_day) {
        case 0:
            return std::string("Mon");
        case 1:
            return std::string("Tue");
        case 2:
            return std::string("Wed");
        case 3:
            return std::string("Thu");
        case 4:
            return std::string("Fri");
        case 5:
            return std::string("Sat");
        case 6:
            return std::string("Sun");
    }
    return std::string(" ");
}
int DoctorMap::selectDepartment() const {
    std::cout << "please enter department:\n"
              << "\t1." << departmentString(1) << "\n"
              << "\t2." << departmentString(2) << "\n"
              << "\t3." << departmentString(3) << "\n"
              << "\t4." << departmentString(4) << "\n"
              << "\t5." << departmentString(5) << "\n";
    int choice;
    while(1) {
        std::cin >> choice;
        if(choice>=1 && choice<=5)
            break;
        std::cout << "error please reenter";
    }
    return choice;
}
bool DoctorMap::printDepartmentDoctor(int department) const {
    for(auto i:doctor_map)
        if(getDepartment(i.first) == department)
            printDoctor(i.first);
    return true;
}
int DoctorMap::selectDoctor() const {
    int department;
    department = selectDepartment();
    printDepartmentDoctor(department);
    std::cout << std::endl;
    std::cout << "please enter work number\n";
    int work_number;
    while(1) {
        std::cin >> work_number;
        if(isHave(work_number))
            break;
        std::cout << "error please reenter\n";
    }
    return work_number;
}
int getTodayWeek() {
    time_t timer;
    time(&timer);
    tm *tm_time;
    tm_time = localtime(&timer);
    if(tm_time->tm_wday == 0)
        return 6;
    return tm_time->tm_wday-1;
}
