#include "CDate.h"

CDate::CDate() {
	day = month = year = 1;
}
CDate::CDate(int x, int y, int z) {
	day = x;
	month = y;
	year = z;
}
CDate::CDate(const CDate& a) {
	day = a.day;
	month = a.month;
	year = a.year;
}
CDate::~CDate() {

}
istream& operator>>(istream& is, CDate& a) {
	cout << "Nhap ngay:";
	do {
		is >> a.day;
		if (a.day > 31 || a.day < 0) {
			cout << "khong hop le\n";
		}
	} while (a.day > 31 || a.day < 0);

	cout << "Nhap thang:";
	do {
		is >> a.month;
		if (a.month > 12 || a.month < 0) {
			cout << "khong hop le\n";
		}
	} while (a.month > 12 || a.month < 0);

	cout << "Nhap nam:";
	do {
		is >> a.year;
		if (a.year < 0 || a.year >3000) {
			cout << "khong hop le\n";
		}
	} while (a.year < 0 || a.year>3000);
	return is;
}
ostream& operator << (ostream& os, CDate& a) {
	os << a.day << "/" << a.month << "/" << a.year;
	return os;
}
int CDate::getDay() {
	return day;
}
int CDate::getMonth() {
	return month;
}
int CDate::getYear() {
	return year;
}
void CDate::setDay(int x) {
	day = x;
}
void CDate::setMonth(int x) {
	month = x;
}
void CDate::setYear(int x) {
	year = x;
}