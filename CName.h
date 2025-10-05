#include<iostream>
using namespace std;

class CName {
private:
    string ho;
    string ten;
    string tenDem;

public:
    CName();
    CName(string, string, string);
    CName(const CName&);

    friend istream& operator>>(istream& is, CName& n);
    friend ostream& operator<<(ostream& os, const CName& n);

    string getHo();
    string getTenDem();
    string getTen();

    void setHo(string);
    void setTenDem(string);
    void setTen(string);
};
#pragma once
