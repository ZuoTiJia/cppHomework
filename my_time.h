//
// Created by ccx on 2020/10/5.
//

#ifndef RE_PROJECT_MY_TIME_H
#define RE_PROJECT_MY_TIME_H
#include <string>
std::string WeekString(int week_day);
enum weekDay {
    Mon = 0, TUE, WED, THU, FRI, SAT, SUN
};
class MyTime {
public:
    std::string TimeString() const;
    bool isToday() const;
    MyTime(int month, int month_day, int hour, int minutes);
    MyTime() = default;
    void changeTime();
    friend MyTime operator+(const MyTime&, const int& day);
    friend bool operator<(const MyTime&, const MyTime&);
    friend bool operator>(const MyTime&, const MyTime&);
    friend int operator-(const MyTime&, const MyTime&);
    friend std::string makeRegistration(int work_number, MyTime time);
private:
    int month;
    int month_day;
    int hour;
    int minutes;
};
MyTime GetNowTime();
int GetTodayWeek();
MyTime stringToTime(std::string);
#endif //RE_PROJECT_MY_TIME_H
