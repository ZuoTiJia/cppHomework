//
// Created by ccx on 2020/10/8.
//
#include "start.h"
#include "record.h"
#include <iostream>
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
            ret = recordList.SearchDepartment();
            printRecordList(ret);
            delete ret;
            break;
        case 2:
            ret = recordList.SearchDoctor();
            printRecordList(ret);
            delete ret;
            break;
        case 3:
            ret = recordList.SearchPatient();
            printRecordList(ret);
            delete ret;
            break;
        case 4:
            ret = recordList.SearchTimeSlot();
            printRecordList(ret);
            delete ret;
            break;
        case 5: {
            std::string registration;
            std::cin >> registration;
            Record *record;
            record = recordList.SearchRecord(registration);
            if(record != nullptr)
                std::cout << *record;
            break;
        }
        case 6:
            break;
    }
}
void statistics() {
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
            std::cout << "today registration:" << recordList.AllRegistration() << "\n";
            break;
        case 2:
            std::cout << "today department registration number:";
            for(int i=1; i<=5; i++) {
                std::cout << "\t" << recordList.DepartmentRegistration(i) << "\n";
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
    std::string registration;
    std::cout << "please enter regsitration\n";
    std::cin >> registration;
    Record *record;
    record = recordList.SearchRecord(registration);
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
        std::cout << "erro please reenter4\n";
    }
    switch (choice) {
        case 1:
            change(record);
            break;
        case 2:
            recordList.EraseRecord(registration);
            break;
        case 3:
            break;
    }
}
void change(Record *record) {
    extern RecordList recordList;
    std::cout << "what do you want to change?\n"
              << "1.change doctor\n"
              << "2.change patient\n"
              << "3.change time\n"
              << "4.change condition\n"
              << "5.back";
    int choice;
    while(1) {
        std::cin >> choice;
        if(choice>=1 && choice<=5)
            break;
        std::cout << "error please reenter5\n";
    }
    switch (choice) {
        case 1:
            record->ChangeDoctor();
            break;
        case 2:
            record->ChangePatient();
            break;
        case 3:
            record->ChangeTime();
            break;
        case 4:
            record->ChangeCondition(record->GetRegistration());
            break;
        case 5:
            break;
    }
}
void end() {
    return;
}