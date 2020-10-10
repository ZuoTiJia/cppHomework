//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_PATIENT_H
#define RE_PROJECT_PATIENT_H
#include <string>
#include <iostream>
class Patient {
public:
    bool Print() const ;
    bool Change();
    std::string Name() const;
    int Age() const;
    friend bool operator == (const Patient& patient1, const Patient& patient2);
private:
    friend class Record;
    std::string name;
    int age;
};


#endif //RE_PROJECT_PATIENT_H
