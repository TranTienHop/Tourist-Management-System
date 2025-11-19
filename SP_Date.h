#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

class Date {
private:
    int ngay;
    int thang;
    int nam;
    bool xetNamNhuan(int y);
	bool xetNgayHopLe(int d, int m, int y);

public:
    Date();
    Date(int, int, int);
    Date(const Date&);
    ~Date();

    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, const  Date&);

    int get_ngay();
    int get_thang();
    int get_nam();

    void set_ngay(int);
    void set_thang(int);
    void set_nam(int);
    void set_ngay_thang_nam(Date);

    void phan_tich_chuoi_ngay(const string&);
    string chuoi_ngay_thang_nam();

    bool operator>(const Date&);
    bool operator<(const Date&);
    bool operator==(const Date&);
};
