#include "Person.h"

Person::Person() : mobile(0) {}

Person::Person(const CName& name, int mobile, const CDate& dob, const std::string& email)
    : name(name), mobile(mobile), dob(dob), email(email) {}

Person::Person(const Person& other)
    : name(other.name), mobile(other.mobile), dob(other.dob), email(other.email) {}

Person::~Person() = default;

void Person::set_name(const CName& name) {
    this->name = name;
}

void Person::set_mobile(int mobile) {
    this->mobile = mobile;
}

void Person::set_dob(const CDate& dob) {
    this->dob = dob;
}

void Person::set_email(const std::string& email) {
    this->email = email;
}

CName Person::get_name() const {
    return name;
}

int Person::get_mobile() const {
    return mobile;
}

CDate Person::get_dob() const {
    return dob;
}

std::string Person::get_email() const {
    return email;
}

