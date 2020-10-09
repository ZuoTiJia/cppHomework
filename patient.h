//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_PATIENT_H
#define RE_PROJECT_PATIENT_H
#include <string>
#include <iostream>
class Patient {
public:
    Patient(int age, std::string name);
    Patient() = default;
    int GetAge() const {return this->age;};
    std::string GetName() const {return this->name;};
    //改变
    void ChangeName(std::string name);
    void ChangeAge(int age);
    //重载输入输出和 ==
    friend std::istream& operator >> (std::istream &is, Patient &patient);
    friend bool operator == (const Patient& patient1, const Patient& patient2);
private:
    std::string name;
    int age;
};

std::ostream& operator << (std::ostream &os, const Patient &patient);


#endif //RE_PROJECT_PATIENT_H
