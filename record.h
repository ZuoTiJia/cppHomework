//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_RECORD_H
#define RE_PROJECT_RECORD_H
#include "doctor.h"
#include "patient.h"
#include "my_time.h"
#include <string>
#include <list>
#include <utility>
#include <map>
enum condition {
    CHECK = 1, MEDICINE, HOSPITALIZE
};
class Check {
public:
    double price() const;
    friend std::istream& operator >> (std::istream& is, Check&);
    friend std::ostream& operator << (std::ostream& os, const Check&);
    friend class RecordList;
    void scan();
private:
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
class Medicine {
public:
    double price() const;
    friend std::istream& operator >> (std::istream& is, Medicine&);
    friend std::ostream& operator << (std::ostream& os, const Medicine&);
    friend class RecordList;
    void scan();
private:
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
class Hospitalize {
public:
    double price() const;
    friend std::istream& operator >> (std::istream& is, Hospitalize&);
    friend std::ostream& operator << (std::ostream& os, const Hospitalize&);
    friend class RecordList;
    friend void outHospital();
    void scan();
private:
    MyTime begin;
    MyTime end;
    double deposit;
    static double each_day_price;
};
class Record {
public:
    Record();
    ~Record();
    void ChangeDoctor();
    void ChangeTime();
    void ChangePatient();
    void ChangeCondition(std::string registration);
    Doctor& GetDoctor() const;
    Patient& GetPatient() const;
    std::string GetRegistration()const;
    MyTime GetTime() const;
    double GetPrice() const;
    int getCondition() const;
    friend bool operator == (const Record& record1, const Record& record2);
    friend std::ostream& operator << (std::ostream&, const Record&);
    friend std::istream& operator >> (std::istream&, Record&);
    friend void registration();
private:
    Patient* patient;
    MyTime time;
    Doctor *doctor;
    std::string registration;
    int condition;

};
void registration();
void outHospital();

class RecordList {
public:
    void Print();
    RecordList();
    ~RecordList();
    void PushRecord(Record&);
    void EraseRecord(const std::string registration);
    double Turnover();
    //搜索情况函数
    Check& returnCheck(std::string registration);
    Medicine& returnMedicine(std::string registration);
    Hospitalize& returnHospitalize(std::string registration);
    //搜索函数
    std::list<Record*>* SearchDepartment() const;
    std::list<Record*>* SearchDoctor() const;
    std::list<Record*>* SearchPatient() const;
    std::list<Record*>* SearchTimeSlot() const;
    Record* SearchRecord(const std::string& registration);
    //挂号数
    int DepartmentRegistration(int department) const;
    int AllRegistration() const;
    friend void Record::ChangeCondition(std::string registration);
private:
    void checkInit();
    void medicineInit();
    void hospitalizeInit();

    std::list<Record*> record_list;
    std::map<std::string, Check*> check_map;
    std::map<std::string, Medicine*> medicine_map;
    std::map<std::string, Hospitalize*> hospitalize_map;
};
void printRecordList(std::list<Record*> *list);

#endif //RE_PROJECT_RECORD_H
