#include "CName.h"

CName::CName() = default;

CName::CName(const std::string& last, const std::string& middle, const std::string& first)
    : ho(last), ten(first), tenDem(middle) {}

CName::CName(const CName& other) = default;

std::istream& operator>>(std::istream& is, CName& n) {
    std::cout << "\nNhap ho: ";
    is >> n.ho;
    std::cout << "Nhap ten dem: ";
    is >> n.tenDem;
    std::cout << "Nhap ten: ";
    is >> n.ten;
    return is;
}

std::ostream& operator<<(std::ostream& os, const CName& n) {
    os << n.get_fullname();
    return os;
}

std::string CName::getHo() const {
    return ho;
}

std::string CName::getTenDem() const {
    return tenDem;
}

std::string CName::getTen() const {
    return ten;
}

void CName::setHo(const std::string& value) {
    ho = value;
}

void CName::setTenDem(const std::string& value) {
    tenDem = value;
}

void CName::setTen(const std::string& value) {
    ten = value;
}

void CName::set_fullname(const std::string& last, const std::string& middle, const std::string& first) {
    ho = last;
    tenDem = middle;
    ten = first;
}

std::string CName::get_fullname() const {
    std::string result;
    if (!ho.empty()) {
        result += ho;
    }
    if (!tenDem.empty()) {
        if (!result.empty()) {
            result += " ";
        }
        result += tenDem;
    }
    if (!ten.empty()) {
        if (!result.empty()) {
            result += " ";
        }
        result += ten;
    }
    return result;
}

std::string CName::to_string() const {
    return get_fullname();
}

