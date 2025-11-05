#pragma once

#include <iostream>
#include <string>

class CDate {
private:
    int day;
    int month;
    int year;

public:
    CDate();
    CDate(int day, int month, int year);
    CDate(const CDate& other);

    friend std::istream& operator>>(std::istream& is, CDate& date);
    friend std::ostream& operator<<(std::ostream& os, const CDate& date);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    int get_day() const;
    int get_month() const;
    int get_year() const;

    void setDay(int value);
    void setMonth(int value);
    void setYear(int value);

    void set_day(int value);
    void set_month(int value);
    void set_year(int value);

    void parse_date(const std::string& date_string);
    std::string to_string() const;

    ~CDate();
};
