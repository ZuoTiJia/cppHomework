//
// Created by ccx on 2020/10/6.
//

#include <string>
#include <ctime>
#include <iostream>
#include <cstdio>
#include "my_time.h"


std::string MyTime::timeString() const {
    char buffer[20];
    sprintf(buffer, "%02d-%02d,%02d:%02d",
             month, month_day, hour, minutes);
    std::string ret(buffer);
    return ret;
}

MyTime getNowTime() {
    time_t timer;
    time(&timer);
    tm *tm_time;
    tm_time = localtime(&timer);
    MyTime ret;
    ret.month = tm_time->tm_mon+1;
    ret.month_day = tm_time->tm_mday;
    ret.hour = tm_time->tm_hour;
    ret.minutes = tm_time->tm_min;
    return ret;
}
bool MyTime::isToday() const {
    MyTime a= getNowTime();
    return a.month == month && a.month_day == month_day;
}
MyTime operator +(const MyTime& time, const int& day) {
    MyTime ret(time);
    ret.month_day += day;
    if(ret.month_day>31) {
        ret.month += ret.month_day/31;
        ret.month_day %= 31;
    }
    return ret;
}
bool operator > (const MyTime& myTime1, const MyTime& myTime2) {
    return myTime1.month > myTime2.month ||
           myTime1.month_day > myTime2.month_day ||
           myTime1.hour > myTime2.hour ||
           myTime1.minutes > myTime2.minutes;
}

bool operator < (const MyTime& myTime1, const MyTime& myTime2) {
    return myTime1.month < myTime2.month ||
           myTime1.month_day < myTime2.month_day ||
           myTime1.hour < myTime2.hour ||
           myTime1.minutes < myTime2.minutes;
}
int operator-(const MyTime& myTime1, const MyTime& myTime2) {
    MyTime ret;
    int time1 = myTime1.month*31 + myTime1.month_day;
    int time2 = myTime2.month*31 + myTime2.month_day;
    if(myTime1>myTime2) {
        return time1 - time2;
    } else {
        return time2 - time1;
    }
}
void MyTime::Change() {
    int t_month;
    int t_month_day;
    int t_hour;
    int t_minutes;
    std::cout << "please enter time\n";
    while (1) {
        std::cout << "please enter month";
        std::cin >> t_month;
        if(t_month <= 12 && t_month >=1)
            break;
        std::cout << "error ";
    }
    while(1) {
        std::cout << "please enter month day";
        std::cin >> t_month_day;
        if(t_month_day <= 31 && t_month_day >=1)
            break;
        std::cout <<"error";
    }
    while(1) {
        std::cout << "please enter hour(24h)";
        std::cin >> t_hour;
        if(t_hour <=23 && t_hour >=0)
            break;
        std::cout << "error";
    }
    while(1) {
        std::cout << "please enter minutes";
        std::cin >> t_minutes;
        if(t_minutes <=59 && t_minutes >=0)
            break;
        std::cout << "error";
    }
    month = t_month;
    month_day = t_month_day;
    hour = t_hour;
    minutes = t_minutes;
}
MyTime stringToTime(std::string time) {
    int month;
    int month_day;
    int hour;
    int minutes;
    sscanf(time.c_str(), "%d-%d,%d:%d", &month, &month_day, &hour, &minutes);
    MyTime ret;
    ret.month = month;
    ret.month_day = month_day;
    ret.hour = hour;
    ret.minutes = minutes;
    return ret;
}