#pragma once

#include <iostream>
#include <string>

class CName {
private:
    std::string ho;
    std::string ten;
    std::string tenDem;

public:
    CName();
    CName(const std::string& last, const std::string& middle, const std::string& first);
    CName(const CName& other);

    friend std::istream& operator>>(std::istream& is, CName& n);
    friend std::ostream& operator<<(std::ostream& os, const CName& n);

    std::string getHo() const;
    std::string getTenDem() const;
    std::string getTen() const;

    void setHo(const std::string& value);
    void setTenDem(const std::string& value);
    void setTen(const std::string& value);

    void set_fullname(const std::string& last, const std::string& middle, const std::string& first);
    std::string get_fullname() const;
    std::string to_string() const;
};
