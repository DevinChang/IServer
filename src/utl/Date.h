//
// Created by devinchang on 2019/8/25.
//

#ifndef INC_315SERVER_DATE_H
#define INC_315SERVER_DATE_H

#include "utl.h"

struct tm;

class Date{
public:
    struct YearMonthDay{
        int year;
        int month;
        int day;
    };
    static const int kDaysPerWeek = 7;
    // JulianDay:儒略日数的计算是从格林威治标准时间的中午开始
    static const int kJulianDayOf1970_01_01;

    Date() : julianDayNumber_(0){}
    Date(int year, int month, int day);
    explicit Date(const struct tm&);

public:
    void swap(Date &that){ std::swap(julianDayNumber_, that.julianDayNumber_); }

    bool valid() const { return julianDayNumber_ > 0; }

    std::string tolsoString() const;

    struct YearMonthDay yearMonthDay() const;

    int year() const{ return yearMonthDay().year; }
    int month() const{ return yearMonthDay().month; }
    int day() const{ return yearMonthDay().day; }

    int weekDay() const{ return (julianDayNumber_ + 1) % kDaysPerWeek; }

    int julianDayNumber() const { return julianDayNumber_; }
private:
    int julianDayNumber_;
};

inline bool operator <(Date x, Date y){ return x.julianDayNumber() < y.julianDayNumber(); }


inline bool operator ==(Date x, Date y){ return x.julianDayNumber() == y.julianDayNumber(); }


#endif //INC_315SERVER_DATE_H
