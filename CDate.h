#include<iostream>
using namespace std;

class CDate {
private:
	int day, month, year;
public:
	CDate();
	CDate(int, int, int);
	CDate(const CDate&);
	friend istream& operator>>(istream&, CDate&);
	friend ostream& operator<<(ostream&, CDate&);

	int getDay();
	int getMonth();
	int getYear();
	void setDay(int);
	void setMonth(int);
	void setYear(int);

	~CDate();
};
#pragma once
