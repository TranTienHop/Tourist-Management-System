#pragma once

#include <string>

#include "Person.h"

class Employee : public Person {
protected:
    int employee_id;
    std::string department;
    double base_salary;
    double salary;
    float salary_coefficient;
    int experience;

public:
    Employee();
    Employee(int employee_id, const std::string& department, double base_salary,
             float salary_coefficient, int experience);
    virtual ~Employee();

    void set_employee_id(int employee_id);
    void set_department(const std::string& department);
    void set_base_salary(double base_salary);
    void set_salary_coefficient(float salary_coefficient);
    void set_experience(int experience);

    int get_employee_id() const;
    std::string get_department() const;
    double get_base_salary() const;
    double get_salary() const;
    float get_salary_coefficient() const;
    int get_experience() const;

    virtual double calculate_salary() = 0;

    void input() override;
    void display() override;
    void update() override;
    void edit() override;
    void remove() override;
    void save() override;
};

class CustomerServiceEmployee : public Employee {
private:
    int clients_managed;
    double bonus;

public:
    CustomerServiceEmployee();
    CustomerServiceEmployee(int employee_id, const std::string& department, double base_salary,
                            float salary_coefficient, int experience, int clients_managed,
                            double bonus);
    ~CustomerServiceEmployee() override;

    void set_clients_managed(int value);
    void set_bonus(double value);

    int get_clients_managed() const;
    double get_bonus() const;

    double calculate_salary() override;

    void input() override;
    void display() override;
    void update() override;
    void edit() override;
    void remove() override;
    void save() override;
};

class TourGuideEmployee : public Employee {
private:
    std::string languages;
    int tours_led;
    double tour_bonus_per_trip;

public:
    TourGuideEmployee();
    TourGuideEmployee(int employee_id, const std::string& department, double base_salary,
                      float salary_coefficient, int experience, const std::string& languages,
                      int tours_led, double tour_bonus_per_trip = 50000.0);
    ~TourGuideEmployee() override;

    void set_languages(const std::string& value);
    void set_tours_led(int value);
    void set_tour_bonus_per_trip(double value);

    std::string get_languages() const;
    int get_tours_led() const;
    double get_tour_bonus_per_trip() const;

    double calculate_salary() override;

    void input() override;
    void display() override;
    void update() override;
    void edit() override;
    void remove() override;
    void save() override;
};

