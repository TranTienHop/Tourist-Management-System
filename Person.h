#pragma once

#include <string>

#include "CName.h"
#include "CDate.h"

class Person {
protected:
    CName name;
    int mobile;
    CDate dob;
    std::string email;

public:
    Person();
    Person(const CName& name, int mobile, const CDate& dob, const std::string& email);
    Person(const Person& other);
    virtual ~Person();

    void set_name(const CName& name);
    void set_mobile(int mobile);
    void set_dob(const CDate& dob);
    void set_email(const std::string& email);

    CName get_name() const;
    int get_mobile() const;
    CDate get_dob() const;
    std::string get_email() const;

    virtual void input() = 0;
    virtual void display() = 0;
    virtual void update() = 0;
    virtual void edit() = 0;
    virtual void remove() = 0;
    virtual void save() = 0;
};

