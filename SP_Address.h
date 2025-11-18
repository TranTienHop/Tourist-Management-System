#pragma once
#include <iostream>
#include <string>
using namespace std;

class DiaChi {
private:
    string so_nha;
    string ten_duong;
    string ten_tinh;

public:
    DiaChi();
    DiaChi(string, string, string);
    DiaChi(const DiaChi&);
    ~DiaChi();

    friend istream& operator>>(istream& , DiaChi& );
    friend ostream& operator<<(ostream& , const DiaChi&);

    string get_so_nha();
    string get_ten_duong();
    string get_ten_tinh();
    string get_dia_chi_day_du();

    void set_so_nha(string);
    void set_ten_duong(string);
    void set_ten_tinh(string);
    void set_dia_chi_day_du(string&, string&, string&);
};
