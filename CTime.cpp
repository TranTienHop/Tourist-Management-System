#include "CTime.h"
CTime::CTime() {
    gio = phut = giay = 0;
}

CTime::CTime(int h, int m, int s) {
    gio = h;
    phut = m;
    giay = s;
}

CTime::CTime(const CTime &t) {
    gio = t.gio;
    phut = t.phut;
    giay = t.giay;
}

int CTime::getGio() { return gio; }
int CTime::getPhut() { return phut; }
int CTime::getGiay() { return giay; }

void CTime::setGio(int h) { gio = h; }
void CTime::setPhut(int m) { phut = m; }
void CTime::setGiay(int s) { giay = s; }

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio, phut, giay: ";
    is >> t.gio >> t.phut >> t.giay;
    return is;
}

ostream& operator<<(ostream& os, CTime& t) {
    os << t.gio << ":" << t.phut << ":" << t.giay;
    return os;
}

CTime::~CTime() {
   
}
