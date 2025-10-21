#include"CName.h"

CName::CName() {
    ho = "";
    tenDem = "";
    ten = "";
}

CName::CName(string h, string tenDem, string t) {
    ho = h;
    tenDem= tenDem;
    ten = t;
}

CName::CName(const CName& k) {
    ho = k.ho;
    tenDem = k.tenDem;
    ten = k.ten;
}

istream& operator>>(istream& is, CName& n) {
    cout << "\nNhap ho: ";
    is >> n.ho;
    cout << "Nhap ten dem: ";
    is >> n.tenDem;
    cout << "Nhap ten: ";
    is >> n.ten;
    return is;
}

ostream& operator<<(ostream& os, const CName& n) {
    os << n.ho << " " << n.tenDem << " " << n.ten;
    return os;
}

string CName::getHo() {
    return ho;
}

string CName::getTenDem() {
    return tenDem;
}

string CName::getTen() {
    return ten;
}

void CName::setHo(string h) {
    ho = h;
}

void CName::setTenDem(string td) {
    tenDem = td;
}

void CName::setTen(string t) {
    ten = t;
}

