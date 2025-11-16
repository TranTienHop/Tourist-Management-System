#include "SP_Time.h"
Time::Time() {
    this->gio = 0;
    this->phut = 0;
    this->giay = 0;
}

Time::Time(int gio, int phut, int giay) {
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

Time::Time(const Time& time) {
    this->gio = time.gio;
    this->phut = time.phut;
    this->giay = time.giay;
}

Time::~Time() {}

int Time::get_gio() {
    return this->gio;
}

int Time::get_phut() {
    return this->phut;
}

int Time::get_giay() {
    return this->giay;
}

void Time::set_gio(int gio) {
    this->gio = gio;
}

void Time::set_phut(int phut) {
    this->phut = phut;
}

void Time::set_giay(int giay) {
    this->giay = giay;
}

istream& operator>>(istream& is, Time& time) {
    cout << "Nhap gio: ";
    do {
        is >> time.gio;
        if (time.gio < 0 || time.gio > 23)
            cout << "Gio khong hop le! Nhap lai: ";
    } while (time.gio < 0 || time.gio > 23);

    cout << "Nhap phut: ";
    do {
        is >> time.phut;
        if (time.phut < 0 || time.phut > 59)
            cout << "Phut khong hop le! Nhap lai: ";
    } while (time.phut < 0 || time.phut > 59);

    cout << "Nhap giay: ";
    do {
        is >> time.giay;
        if (time.giay < 0 || time.giay > 59)
            cout << "Giay khong hop le! Nhap lai: ";
    } while (time.giay < 0 || time.giay > 59);

    return is;
}

ostream& operator<<(ostream& os, const Time& time) {
    os << (time.gio < 10 ? "0" : "") << time.gio << ":"
        << (time.phut < 10 ? "0" : "") << time.phut << ":"
        << (time.giay < 10 ? "0" : "") << time.giay;
    return os;
}

void Time::phan_tich_chuoi_thoi_gian(const string& chuoi) {
    sscanf_s(chuoi.c_str(), "%d:%d:%d", &this->gio, &this->phut, &this->giay);
}

string Time::chuoi_thoi_gian() {
    char buffer[9];
    sprintf_s(buffer, "%02d:%02d:%02d", this->gio, this->phut, this->giay);
    return string(buffer);
}
