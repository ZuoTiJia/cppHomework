//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_DOCTOR_H
#define RE_PROJECT_DOCTOR_H
#include <string>
#include <bitset>
#include <iostream>
#include <vector>
#include <map>
enum rank{
    CHIEF_PHYSICIAN = 1, ASSOCIATE_CHIEF_PHYSICIAN, ATTENDING_PHYSICIAN, RESIDENT_PHYSICIAN
};// 主任医师， 副主任医师， 主治医师， 住院医师
enum department {
    SURGERY = 1, INTERNAL, PHARMACY, PEDIATRIC, GYNECOLOGY
};//外科，内科，药剂科，儿科，妇产科
class Doctor{
public:
    Doctor(const Doctor& doctor);
    Doctor(std::string name = " ", std::bitset<7> work_time = std::bitset<7>("0000000"), int work_number = 0);
    int GetWorkNumber() const {return this->work_number;};
    int GetRank() const;
    int GetDepartment() const;
    int GetTodayWorkStatus() const;
    friend std::ostream& operator << (std::ostream& os, const Doctor&);
    friend std::istream& operator >> (std::istream& is, Doctor& doctor);
    bool isWorkDay();
    friend bool operator == (const Doctor& doctor1, const Doctor& doctor2);
private:
    std::string GetDepartmentString() const;
    std::string GetRankString() const;
    std::string GetWorkTimeString() const;
    const std::string GetName() const {return this->name;};
    std::string name;
    std::bitset<7> work_time;
    int work_number;
};
class DoctorVector{
public:
    DoctorVector();
    void add(int work_number);
    void Print();
    int GetWorkStatus(int work_number);
    Doctor& Select();
    int selectDepartment() const;
    Doctor& getDoctor(int work_number);
private:
    bool isHave(int work_number);
    void printDepartment() const;
    void printDepartmentDoctor(int department) const;
    std::map<int, int> work_status;
    std::vector<Doctor *> doctor_vector;
};
#endif //RE_PROJECT_DOCTOR_H
