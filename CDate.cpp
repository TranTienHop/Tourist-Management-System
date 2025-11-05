#include "CDate.h"

#include <iomanip>
#include <sstream>

CDate::CDate() : day(1), month(1), year(1) {}

CDate::CDate(int day, int month, int year)
    : day(day), month(month), year(year) {}

CDate::CDate(const CDate& other) = default;

CDate::~CDate() = default;

std::istream& operator>>(std::istream& is, CDate& date) {
    std::cout << "Nhap ngay:";
    do {
        is >> date.day;
        if (date.day > 31 || date.day < 1) {
            std::cout << "khong hop le\n";
        }
    } while (date.day > 31 || date.day < 1);

    std::cout << "Nhap thang:";
    do {
        is >> date.month;
        if (date.month > 12 || date.month < 1) {
            std::cout << "khong hop le\n";
        }
    } while (date.month > 12 || date.month < 1);

    std::cout << "Nhap nam:";
    do {
        is >> date.year;
        if (date.year < 0 || date.year > 3000) {
            std::cout << "khong hop le\n";
        }
    } while (date.year < 0 || date.year > 3000);
    return is;
}

std::ostream& operator<<(std::ostream& os, const CDate& date) {
    os << std::setw(2) << std::setfill('0') << date.day << '/'
       << std::setw(2) << std::setfill('0') << date.month << '/'
       << std::setw(4) << std::setfill('0') << date.year;
    os << std::setfill(' ');
    return os;
}

int CDate::getDay() const {
    return day;
}

int CDate::getMonth() const {
    return month;
}

int CDate::getYear() const {
    return year;
}

int CDate::get_day() const {
    return getDay();
}

int CDate::get_month() const {
    return getMonth();
}

int CDate::get_year() const {
    return getYear();
}

void CDate::setDay(int value) {
    day = value;
}

void CDate::setMonth(int value) {
    month = value;
}

void CDate::setYear(int value) {
    year = value;
}

void CDate::set_day(int value) {
    setDay(value);
}

void CDate::set_month(int value) {
    setMonth(value);
}

void CDate::set_year(int value) {
    setYear(value);
}

void CDate::parse_date(const std::string& date_string) {
    std::stringstream ss(date_string);
    char separator_1 = 0;
    char separator_2 = 0;
    int d = 1;
    int m = 1;
    int y = 1;

    if (ss >> d >> separator_1 >> m >> separator_2 >> y && separator_1 == '/' && separator_2 == '/') {
        day = d;
        month = m;
        year = y;
    }
}

std::string CDate::to_string() const {
    std::ostringstream builder;
    builder << std::setw(2) << std::setfill('0') << day << '/'
            << std::setw(2) << std::setfill('0') << month << '/'
            << std::setw(4) << std::setfill('0') << year;
    return builder.str();
}