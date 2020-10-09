//
// Created by ccx on 2020/10/6.
//
#include "doctor.h"
#include "my_time.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
//

DoctorVector doctorVector;
std::string Doctor::GetWorkTimeString() const {
    std::string ret;
    for(int i=0; i<7; i++)
        if(work_time[i]) {
            ret += WeekString(i);
            ret += " ";
        }
    return ret;
}
Doctor::Doctor(std::string name, std::bitset<7> work_time, int work_number)
    :name(name), work_time(work_time), work_number(work_number)
    {}
std::string Doctor::GetDepartmentString() const {
    int department = GetDepartment();
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
std::string Doctor::GetRankString() const {
    int rank = GetRank();
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
int Doctor::GetRank() const {
    int t=work_number;
    t /= 10;
    return t%10;
}
int Doctor::GetDepartment() const {
    return work_number/100;
}
int Doctor::GetTodayWorkStatus() const {
    extern DoctorVector doctorVector;
    return doctorVector.GetWorkStatus(work_number);
}
Doctor::Doctor(const Doctor &doctor) {
    name = doctor.name;
    work_number = doctor.work_number;
    work_time = doctor.work_time;
}
std::ostream& operator << (std::ostream& os, const Doctor& doctor) {
    os << "doctor:\n";
    os << "\t" << "doctor name:" << doctor.name << "\n";
    os << "\t" << "department:" << doctor.GetDepartmentString() << "\n";
    os << "\t" << "rank:" <<doctor.GetRankString() << "\n";
    os << "\t" << "work number:" << doctor.work_number << "\n";
    os << "\t" << "work time:" << doctor.GetWorkTimeString() << "\n";
    os << "\t" << "today work status:" << doctor.GetTodayWorkStatus() <<"\n";
    return os;

}
std::istream& operator >> (std::istream& is, Doctor& doctor) {
    std::string work_time;
    is >> doctor.work_number >> doctor.name >> work_time;
    doctor.work_time = std::bitset<7>(work_time);
    return is;
}
bool operator == (const Doctor& doctor1, const Doctor& doctor2) {
    return doctor1.work_number == doctor2.work_number;
}
bool Doctor::isWorkDay() {
    if(GetTodayWorkStatus() > 20)
        return false;
    if(work_time[GetTodayWeek()] == 0)
        return false;
    return true;
}

//====================================
DoctorVector::DoctorVector() {
    Doctor doctor;
    std::ifstream f_doctor;
    f_doctor.open("./doctor", std::ios::in);
    while(f_doctor >> doctor) {
        Doctor *p;
        p = new Doctor(doctor);
        doctor_vector.push_back(p);
    }
    //map 初始化
    for(auto i:doctor_vector)
        work_status[i->GetWorkNumber()] = 0;
}

void DoctorVector::Print() {
    for(auto i:doctor_vector) {
        std::cout << *i;
    }
}
void DoctorVector::add(int work_number) {
    work_status[work_number]++;
}

int DoctorVector::GetWorkStatus(int work_number) {
    return work_status[work_number];
}
int DoctorVector::selectDepartment() const {
    int department;
    std::cout << "please enter department\n";
    printDepartment();
    while(1) {
        std::cin >> department;
        if(department>=1 && department<=5)
            break;
        std::cout << "error please reenter department";
    }
    return department;
}
void DoctorVector::printDepartment() const {
    std::cout
    << "1.surgery\n"
    << "2.internal\n"
    << "3.pharmacy\n"
    << "4.pediatric\n"
    << "5.gynecology\n";
}
void DoctorVector::printDepartmentDoctor(int department) const {
    for(auto i:doctor_vector)
        if(i->GetDepartment()==department)
            std::cout << *i;
}
bool DoctorVector::isHave(int work_number) {
    for(auto i:doctor_vector)
        if(i->GetWorkNumber()  == work_number)
            return 1;
    return 0;
}
Doctor& DoctorVector::getDoctor(int work_number) {
    for(auto i:doctor_vector)
        if(i->GetWorkNumber() == work_number)
            return (*i);
}
Doctor& DoctorVector::Select() {
    int department;
    int work_number;
    department = selectDepartment();
    printDepartmentDoctor(department);

    while (1) {
    std::cout << "please enter work number";
        std::cin >> work_number;
        if (
                isHave(work_number)
                )
            break;
        std::cout << "don't have this doctor";
    }
    return getDoctor(work_number);
..}