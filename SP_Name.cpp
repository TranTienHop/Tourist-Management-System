#include "SP_Name.h"
#include <sstream>  

Name::Name() {
    ho = "";
    ten_dem = "";
    ten = "";
    ho_ten = "";
}

Name::Name(string ho, string ten_dem, string ten) {
    this->ho = ho;
    this->ten_dem = ten_dem;
    this->ten = ten;
    this->ho_ten = ho + " " + ten_dem + " " + ten;
}

Name::Name(const Name& other) {
    ho = other.ho;
    ten_dem = other.ten_dem;
    ten = other.ten;
    ho_ten = other.ho_ten;
}

Name::~Name() {}

istream& operator>>(istream& is, Name& n) {
    cout << "\tNhap ho: ";
    is >> n.ho;
    cout << "\tNhap ten dem: ";
    is >> n.ten_dem;
    cout << "\tNhap ten: ";
    is >> n.ten;
    n.ho_ten = n.ho + " " + n.ten_dem + " " + n.ten;
    return is;
}

ostream& operator<<(ostream& os, const Name& n) {
    os << n.ho_ten;
    return os;
}

string Name::get_ho() {
    return ho;
}

string Name::get_ten_dem() {
    return ten_dem;
}

string Name::get_ten() {
    return ten;
}

string Name::get_ho_ten() {
    return ho_ten;
}



void Name::set_ho(string ho) {
    this->ho = ho;
}

void Name::set_ten_dem(string ten_dem) {
    this->ten_dem = ten_dem;
}

void Name::set_ten(string ten) {
    this->ten = ten;
}

void Name::set_hoten(string full_name) {
    ho_ten = full_name;

    stringstream ss(full_name);
    string parts[10]; // mảng tạm chứa từng từ
    int count = 0;
    while (ss >> parts[count]) count++;

    if (count == 1) {
        ho = "";
        ten_dem = "";
        ten = parts[0];
    }
    else if (count == 2) {
        ho = parts[0];
        ten_dem = "";
        ten = parts[1];
    }
    else if (count >= 3) {
        ho = parts[0];
        ten = parts[count - 1];
        ten_dem = "";
        for (int i = 1; i < count - 1; i++) {
            ten_dem += parts[i];
            if (i < count - 2) ten_dem += " ";
        }
    }
}
