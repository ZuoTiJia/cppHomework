//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_MY_TIME_H
#define RE_PROJECT_MY_TIME_H
#include <string>
class MyTime {
public:
    std::string timeString() const;
    bool isToday() const;
    void Change();
    friend MyTime getNowTime();
    friend MyTime stringToTime(std::string);
    friend std::string makeRegistration(int work_number, MyTime time);
    friend MyTime operator+(const MyTime&, const int& day);
    friend bool operator<(const MyTime&, const MyTime&);
    friend bool operator>(const MyTime&, const MyTime&);
    friend int operator-(const MyTime&, const MyTime&);
private:
    int month;
    int month_day;
    int hour;
    int minutes;
};
MyTime getNowTime();
MyTime stringToTime(std::string);
#endif //RE_PROJECT_MY_TIME_H
