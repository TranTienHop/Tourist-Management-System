#include<iostream>
#include<string>
using namespace std;
class CAddress {
private:
	string soNha;
	string tenDuong;
	string tenTinh;
public:
	CAddress();
	CAddress(string, string, string);
	CAddress(const CAddress&);
	friend istream& operator>>(istream&, CAddress&);
	friend ostream& operator<<(ostream&, const CAddress&);
	string getSoNha();
	string getTenDuong();
	string getTenTinh();
	void setSoNha(string);
	void setTenDuong(string);
	void setTenTinh(string);
	~CAddress();
};
#pragma once
