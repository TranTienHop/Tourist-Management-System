#include "CTime.h"
#include <iomanip>  

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
    while (true) {
        cout << "Nhap gio, phut, giay: ";
        if (!(is >> t.gio >> t.phut >> t.giay)) {
            is.clear();
            string bad;
            getline(is, bad);
            cout << "khong hop le" << endl;
            continue;
        }

        bool hopLe = true;
        if (t.gio < 0 || t.gio > 23) hopLe = false;
        if (t.phut < 0 || t.phut > 59) hopLe = false;
        if (t.giay < 0 || t.giay > 59) hopLe = false;

        if (!hopLe) {
            cout << "khong hop le" << endl;
            continue; 
        }

        break; 
    }
    return is;
}

ostream& operator<<(ostream& os, CTime& t) {
    os << setw(2) << setfill('0') << t.gio << ":"
       << setw(2) << setfill('0') << t.phut << ":"
       << setw(2) << setfill('0') << t.giay;
    return os;
}

CTime::~CTime() {

}
