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


class Record {
public:
    Record();
    Record(std::string registration, std::string name, int age, int doctor_number, std::string time, int condition);
    bool Change();
    int getDoctorNumber() const;
    bool Print() const;
    Patient getPatient() const;
    std::string getRegistration()const;
    MyTime getTime() const;
    double getPrice() const;
    int getCondition() const;
    friend bool operator == (const Record& record1, const Record& record2);
    friend void registration();
private:
    bool changeCondition();
    Patient patient;
    MyTime time;
    int doctor_number;
    std::string registration;
    int condition;

};
void registration();
void outHospital();

class RecordList {
public:
    RecordList();
    ~RecordList();
    void pushRecord(Record *);
    void eraseRecord(const std::string registration);
    double Turnover();
    //搜索函数
    std::list<Record*>* searchDepartment() const;
    std::list<Record*>* searchDoctor() const;
    std::list<Record*>* searchPatient() const;
    std::list<Record*>* searchTimeSlot() const;
    Record* searchRecord(const std::string& registration);
    //挂号数
    int departmentRegistration(int department) const;
    int allRegistration() const;
private:
    bool changeCondition(std::string registration);
    std::list<Record*> record_list;
};
bool printRecordList(std::list<Record*> *list);
#endif //RE_PROJECT_RECORD_H