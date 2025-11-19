#include"SP_Date.h"
Date::Date() {
    this->ngay =1;
    this->thang = 1;
    this->nam = 2000;
}

Date::Date(int ngay, int thang, int nam) {
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

Date::Date(const Date& date) {
    this->ngay = date.ngay;
    this->thang = date.thang;
    this->nam = date.nam;
}

Date::~Date() {

}

bool Date::xetNamNhuan(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::xetNgayHopLe(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12 || d < 1) return false;

    int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (m == 2 && xetNamNhuan(y)) 
        return d <= 29;

    return d <= ngayTrongThang[m];
}

istream& operator>>(istream& is, Date& a) {
     while (true) {
        cout << "Nhap ngay: ";
        is >> a.ngay;
        
        if (is.fail()) {
            is.clear();
            is.ignore(1000, '\n');
            cout << "Sai dinh dang!\n";
            continue;
        }

        if (a.xetNgayHopLe(a.ngay, a.thang, a.nam)) break;

        cout << "Ngay vua nhap KHONG hop le!\n";
    }
    
    while (true) {
        cout << "\nNhap thang: ";
        is >> a.thang;
        
        if (is.fail()) {
            is.clear();
            is.ignore(1000, '\n');
            cout << "Sai dinh dang!\n";
            continue;
        }

        if (a.xetNgayHopLe(a.ngay, a.thang, a.nam)) break;

        cout << "Thang vua nhap KHONG hop le!\n";
    }

	while (true) {
        cout << "\nNhap nam: ";
        is >> a.nam;
        
        if (is.fail()) {
            is.clear();
            is.ignore(1000, '\n');
            cout << "Sai dinh dang!\n";
            continue;
        }

        if (a.xetNgayHopLe(a.ngay, a.thang, a.nam)) break;

        cout << "Nam vua nhap KHONG hop le!\n";
    }
    return is;
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(2) << setfill('0') << date.ngay << "/"
        << setw(2) << setfill('0') << date.thang << "/"
        << date.nam;
    os << setfill(' '); // reset về mặc định
    return os;
}

int Date::get_ngay() {
    return this->ngay;
}

int Date::get_thang() {
    return this->thang;
}

int Date::get_nam() {
    return this->nam;
}

void Date::set_ngay(int ngay) {
    this->ngay = ngay;
}

void Date::set_thang(int thang) {
    this->thang = thang;
}

void Date::set_nam(int nam) {
    this->nam = nam;
}

void Date::set_ngay_thang_nam(Date date) {
    this->ngay = date.ngay;
    this->thang = date.thang;
    this->nam = date.nam;
}

void Date::phan_tich_chuoi_ngay(const string& str) {
    int d, m, y;
    sscanf_s(str.c_str(), "%d/%d/%d", &d, &m, &y);
    this->ngay = d;
    this->thang = m;
    this->nam = y;
}

bool Date::operator>(const Date& date) {
    if (this->nam > date.nam) return true;
    if (this->nam == date.nam && this->thang > date.thang) return true;
    if (this->nam == date.nam && this->thang == date.thang && this->ngay > date.ngay) return true;
    return false;
}

bool Date::operator<(const Date& date) {
    if (this->nam < date.nam) return true;
    if (this->nam == date.nam && this->thang < date.thang) return true;
    if (this->nam == date.nam && this->thang == date.thang && this->ngay < date.ngay) return true;
    return false;
}

bool Date::operator==(const Date& date) {
    return (this->ngay == date.ngay && this->thang == date.thang && this->nam == date.nam);
}

string Date::chuoi_ngay_thang_nam() {
    return to_string(this->ngay) + "/" + to_string(this->thang) + "/" + to_string(this->nam);
}

