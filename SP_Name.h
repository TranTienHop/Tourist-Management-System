#pragma once
#include <iostream>
#include <string>
using namespace std;

class Name {
private:
    string ho;
    string ten;
    string ten_dem;
    string ho_ten; // lưu full tên

public:
    Name();
    Name(string, string, string);
    Name(const Name&);
    ~Name();

    friend istream& operator>>(istream&, Name&);
    friend ostream& operator<<(ostream&, const Name&);

    string get_ho();
    string get_ten_dem();
    string get_ten();
    string get_ho_ten();

    void set_ho(string);
    void set_ten_dem(string);
    void set_ten(string);
    void set_hoten(string full_name); // chỉ gán full name, không tách
};
