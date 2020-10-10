//
// Created by ccx on 2020/10/5.
//
#include "patient.h"
#include <iostream>
std::string Patient::Name() const {
    return name;
}
int Patient::Age() const {
    return age;
}
bool Patient::Print() const {
    std::cout << "patient:\n"
              <<"\t" << "patient name:" << name << "\n"
              <<"\t" << "patient age:" << age << "\n";
    return true;
}
bool Patient::Change() {
    std::cout << "please enter patient name:\n";
    std::cin >> name;
    std::cout << "please enter patient age:\n";
    while(1) {
        std::cin >> age;
        if(age>=0 && age <=150)
            break;
        std::cout << "please enter correct age\n";
    }
    return true;
}
bool operator == (const Patient& patient1, const Patient& patient2) {
    return patient1.name == patient2.name && patient1.age == patient2.age;
}
