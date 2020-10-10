//
// Created by ccx on 2020/10/8.
//
#include "start.h"
#include "record.h"
#include <iostream>
#include "condition.h"
bool start() {
    std::cout << "please enter a c" << std::endl;
    std::string a;
    std::cin >> a;
    int choice;
    system("clear");
    std::cout << "what do you want to do?\n"
              << "1.registration\n"
              << "2.change or delete\n"
              << "3.search\n"
              << "4.statistics\n"
              << "5.exit\n";
    while(1) {
        std::cin >> choice;
        if(choice >=1 && choice <=5)
            break;
        std::cout << "please reenter1\n";
    }
    switch (choice) {
        case 1:
            registrationMod();
            break;
        case 2:
            change_or_delete();
            break;
        case 3:
            search();
            break;
        case 4:
            statistics();
            break;
        case 5:
            return true;
    }
    return false;
}
void registrationMod() {
    int choice;
    std::cout << "what do you want to do?\n"
              << "1.registration\n"
              << "2.out hospital\n"
              << "3.back\n";
    while(1) {
        std::cin >> choice;
        if(choice>=1 && choice<=3)
            break;
        std::cout << "please reenter2\n";
    }
    switch (choice) {
        case 1:
            registration();
            break;
        case 2:
            outHospital();
            break;
        case 3:
            break;
    }
}

void search() {
    extern RecordList recordList;
    std::list<Record*>* ret;
    int choice;
    std::cout << "what do you want to search?\n"
              << "1.department record\n"
              << "2.doctor record\n"
              << "3.patient record\n"
              << "4.time segment record\n"
              << "5.one record\n"
              << "6.back";
    while(1) {
        std::cin >> choice;
        if(choice>=1 && choice<=6)
            break;
        std::cout << "please reenter3\n";
    }
    switch (choice) {
        case 1:
            ret = recordList.searchDepartment();
            printRecordList(ret);
            delete ret;
            break;
        case 2:
            ret = recordList.searchDoctor();
            printRecordList(ret);
            delete ret;
            break;
        case 3:
            ret = recordList.searchPatient();
            printRecordList(ret);
            delete ret;
            break;
        case 4:
            ret = recordList.searchTimeSlot();
            printRecordList(ret);
            delete ret;
            break;
        case 5: {
            std::string registration;
            std::cin >> registration;
            Record *record;
            record = recordList.searchRecord(registration);
            if(record != nullptr)
                record->Print();
            break;
        }
        case 6:
            break;
    }
}
void statistics() {
    extern DoctorMap doctorMap;
    extern RecordList recordList;
    std::cout << "what do you want to do?\n"
              << "1.today registration number\n"
              << "2.today department registration number\n"
              << "3.turnover\n"
              << "4.back\n";
    int choice;
    while(1) {
        std::cin >> choice;
        if(choice >=1 && choice <=4)
            break;
    }
    switch (choice) {
        case 1:
            std::cout << "today registration:" << recordList.allRegistration()<< "\n";
            break;
        case 2:
            std::cout << "today department registration number:\n";
            for(int i=1; i<=5; i++) {
                std::cout << doctorMap.departmentString(i) << ":";
                std::cout << recordList.departmentRegistration(i) << "\n";
            }
            break;
        case 3:
            std::cout << "today turnover:\n"  << recordList.Turnover() << "\n";
            break;
        case 4:
            break;
    }
}
void change_or_delete() {
    extern RecordList recordList;
    extern ConditionMap conditionMap;
    std::string registration;
    std::cout << "please enter registration\n";
    std::cin >> registration;
    Record *record;
    record = recordList.searchRecord(registration);
    if(record == nullptr)
        return;
    std::cout << "what do you want to do?\n"
              << "1.change\n"
              << "2.delete\n"
              << "3.back\n";
    int choice;
    while (1) {
        std::cin >> choice;
        if(choice>=1 && choice <=3)
            break;
        std::cout << "error please reenter4\n";
    }
    switch (choice) {
        case 1:
            record->Change();
            break;
        case 2:
            conditionMap.Erase(record->getCondition(), registration);
            recordList.eraseRecord(registration);
            break;
        case 3:
            break;
    }
}