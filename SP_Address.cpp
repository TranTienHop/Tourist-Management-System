#include"SP_Address.h"

DiaChi::DiaChi() {
    this->so_nha = "";
    this->ten_duong = "";
    this->ten_tinh = "";
}

DiaChi::DiaChi(string so_nha, string ten_duong, string ten_tinh) {
    this->so_nha = so_nha;
    this->ten_duong = ten_duong;
    this->ten_tinh = ten_tinh;
}

DiaChi::DiaChi(const DiaChi& dia_chi) {
    this->so_nha = dia_chi.so_nha;
    this->ten_duong = dia_chi.ten_duong;
    this->ten_tinh = dia_chi.ten_tinh;
}

DiaChi::~DiaChi() {}

istream& operator>>(istream& is, DiaChi& dia_chi) {
    cout << "\tNhap so nha: ";
    getline(is, dia_chi.so_nha);

    cout << "\tNhap ten duong: ";
    getline(is, dia_chi.ten_duong);

    cout << "\tNhap ten tinh: ";
    getline(is, dia_chi.ten_tinh);

    return is;
}

ostream& operator<<(ostream& os, const DiaChi& dia_chi) {
    os << dia_chi.so_nha << " " << dia_chi.ten_duong << ", " << dia_chi.ten_tinh;
    return os;
}

string DiaChi::get_so_nha() {
    return this->so_nha;
}

string DiaChi::get_ten_duong() {
    return this->ten_duong;
}

string DiaChi::get_ten_tinh() {
    return this->ten_tinh;
}

string DiaChi::get_dia_chi_day_du() {
    return this->so_nha + " " + this->ten_duong + ", " + this->ten_tinh;
}

void DiaChi::set_so_nha(string so_nha) {
    this->so_nha = so_nha;
}

void DiaChi::set_ten_duong(string ten_duong) {
    this->ten_duong = ten_duong;
}

void DiaChi::set_ten_tinh(string ten_tinh) {
    this->ten_tinh = ten_tinh;
}

void DiaChi::set_dia_chi_day_du(string& so_nha, string& ten_duong, string& ten_tinh) {
    this->so_nha = so_nha;
    this->ten_duong = ten_duong;
    this->ten_tinh = ten_tinh;
}

