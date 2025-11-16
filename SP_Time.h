#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int gio;
    int phut;
    int giay;

public:
    Time();
    Time(int, int, int);
    Time(const Time&);
    ~Time();

    friend istream& operator>>(istream&, Time&);
    friend ostream& operator<<(ostream&, const Time&);

    int get_gio();
    int get_phut();
    int get_giay();

    void set_gio(int);
    void set_phut(int);
    void set_giay(int);

    void phan_tich_chuoi_thoi_gian(const string&);
    string chuoi_thoi_gian();
};
