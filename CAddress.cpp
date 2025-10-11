#include "CAddress.h"

CAddress::CAddress() {
	soNha = "";
	tenDuong = "";
	tenTinh = "";
}

CAddress::CAddress(string sn, string td, string tt) {
	soNha = sn;
	tenDuong = td;
	tenTinh = tt;
}

CAddress::CAddress(const CAddress& a) {
	soNha = a.soNha;
	tenDuong = a.tenDuong;
	tenTinh = a.tenTinh;
}

CAddress::~CAddress() {
}

istream& operator>>(istream& is, CAddress& a) {
	cout << "Nhap so nha: ";
	getline(is, a.soNha);
	cout << "Nhap ten duong: ";
	getline(is, a.tenDuong);
	cout << "Nhap ten tinh: ";
	getline(is, a.tenTinh);
	return is;
}

ostream& operator<<(ostream& os, const CAddress& a) {
	os << a.soNha << " " << a.tenDuong << ", " << a.tenTinh;
	return os;
}

string CAddress::getSoNha() {
	return soNha;
}

string CAddress::getTenDuong() {
	return tenDuong;
}

string CAddress::getTenTinh() {
	return tenTinh;
}

void CAddress::setSoNha(string sn) {
	soNha = sn;
}

void CAddress::setTenDuong(string td) {
	tenDuong = td;
}

void CAddress::setTenTinh(string tt) {
	tenTinh = tt;
}
