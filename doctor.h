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

class DoctorMap {
public:
    DoctorMap();
    int getRank(int work_number) const;
    int getDepartment(int work_number) const;
    int getTodayWorkStatus(int work_number) const;
    std::string getName(int work_number) const;
    bool isWork(int work_number) const;
    bool isHave(int work_number) const;
    bool addWorkStatus(int work_number);
    bool printDoctor(int work_number) const;
    int selectDoctor() const;
    int selectDepartment() const;
    std::string departmentString(int department) const;
private:
    struct Doctor {
        Doctor() = default;
        Doctor(std::string name, std::string work_time);
        std::string name;
        std::bitset<7> work_time;
        int today_work;
    };
    std::string rankString(int rank) const;
    std::string workTimeString(std::bitset<7>) const;
    std::string weekString(int week_day) const;
    bool printDepartmentDoctor(int department) const;
    std::map<int, DoctorMap::Doctor> doctor_map;
};
int getTodayWeek();
#endif //RE_PROJECT_DOCTOR_H
