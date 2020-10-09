//
// Created by ccx on 2020/10/5.
//
#include "patient.h"
#include <iostream>
Patient::Patient(int age, std::string name):age(age), name(name) {}

void Patient::ChangeName(std::string name) {
    this->name = name;
}

void Patient::ChangeAge(int age) {
    this->age = age;
}

std::ostream& operator << (std::ostream &os, const Patient &patient) {
    os << "patient:\n";
    os << "\t" << "patient name:" << patient.GetName() << "\n";
    os << "\t" << "patient age:" << patient.GetAge() << "\n";
    return os;
}

std::istream& operator >> (std::istream &is, Patient &patient) {
    std::cout << "please enter patient name:" << std::endl;
    is >> patient.name;
    std::cout << "please enter patient age:" << std::endl;
    is >> patient.age;
    return is;
}
bool operator == (const Patient& patient1, const Patient& patient2) {
    return patient1.name == patient2.name && patient1.age == patient2.age;
}
