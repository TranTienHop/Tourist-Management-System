#include "Employee.h"

#include <fstream>
#include <iomanip>
#include <iostream>

Employee::Employee()
    : employee_id(0), department(""), base_salary(0.0), salary(0.0),
      salary_coefficient(1.0f), experience(0) {}

Employee::Employee(int employee_id, const std::string& department, double base_salary,
                   float salary_coefficient, int experience)
    : employee_id(employee_id), department(department), base_salary(base_salary), salary(0.0),
      salary_coefficient(salary_coefficient), experience(experience) {}

Employee::~Employee() = default;

void Employee::set_employee_id(int employee_id) {
    this->employee_id = employee_id;
}

void Employee::set_department(const std::string& department) {
    this->department = department;
}

void Employee::set_base_salary(double base_salary) {
    this->base_salary = base_salary;
}

void Employee::set_salary_coefficient(float salary_coefficient) {
    this->salary_coefficient = salary_coefficient;
}

void Employee::set_experience(int experience) {
    this->experience = experience;
}

int Employee::get_employee_id() const {
    return employee_id;
}

std::string Employee::get_department() const {
    return department;
}

double Employee::get_base_salary() const {
    return base_salary;
}

double Employee::get_salary() const {
    return salary;
}

float Employee::get_salary_coefficient() const {
    return salary_coefficient;
}

int Employee::get_experience() const {
    return experience;
}

void Employee::input() {
    std::cout << "Nhap ma nhan vien: ";
    std::cin >> employee_id;
    std::cin.ignore();

    std::cout << "Nhap ho ten: ";
    std::string fullname;
    std::getline(std::cin, fullname);
    CName temp_name;
    temp_name.set_fullname(fullname, "", "");
    set_name(temp_name);

    std::cout << "Nhap so dien thoai: ";
    int mobile_number;
    std::cin >> mobile_number;
    std::cin.ignore();
    set_mobile(mobile_number);

    std::cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    std::string dob_string;
    std::getline(std::cin, dob_string);
    CDate temp_dob;
    temp_dob.parse_date(dob_string);
    set_dob(temp_dob);

    std::cout << "Nhap email: ";
    std::string email_address;
    std::getline(std::cin, email_address);
    set_email(email_address);

    std::cout << "Nhap phong ban: ";
    std::getline(std::cin, department);

    std::cout << "Nhap luong co ban: ";
    std::cin >> base_salary;
    std::cin.ignore();

    std::cout << "Nhap he so luong: ";
    std::cin >> salary_coefficient;
    std::cin.ignore();

    std::cout << "Nhap nam kinh nghiem: ";
    std::cin >> experience;
    std::cin.ignore();
}

void Employee::display() {
    std::cout << "| " << std::setw(6) << employee_id
              << " | " << std::setw(25) << get_name().get_fullname()
              << " | " << std::setw(12) << get_mobile()
              << " | " << std::setw(10) << get_dob().to_string()
              << " | " << std::setw(22) << get_email()
              << " | " << std::setw(12) << department
              << " | " << std::setw(10) << std::fixed << std::setprecision(0) << base_salary
              << " | " << std::setw(5) << std::setprecision(2) << salary_coefficient
              << " | " << std::setw(6) << experience
              << " | " << std::setw(10) << std::setprecision(0) << salary
              << " |" << std::endl;
    std::cout.unsetf(std::ios::floatfield);
}

void Employee::update() {
    std::cout << "Cap nhat nhan vien ma " << employee_id << std::endl;
    std::cout << "Nhap luong co ban moi: ";
    std::cin >> base_salary;
    std::cin.ignore();

    std::cout << "Nhap he so luong moi: ";
    std::cin >> salary_coefficient;
    std::cin.ignore();

    salary = calculate_salary();
}

void Employee::edit() {
    std::cout << "Chinh sua thong tin nhan vien ma " << employee_id << std::endl;

    std::cout << "Nhap phong ban moi (ENTER de giu nguyen): ";
    std::string new_department;
    std::getline(std::cin, new_department);
    if (!new_department.empty()) {
        department = new_department;
    }

    std::cout << "Nhap email moi (ENTER de giu nguyen): ";
    std::string new_email;
    std::getline(std::cin, new_email);
    if (!new_email.empty()) {
        set_email(new_email);
    }

    std::cout << "Nhap nam kinh nghiem moi: ";
    std::cin >> experience;
    std::cin.ignore();
}

void Employee::remove() {
    std::cout << "Da xoa nhan vien ma: " << employee_id << std::endl;
    employee_id = 0;
    department.clear();
    base_salary = 0.0;
    salary_coefficient = 1.0f;
    experience = 0;
    salary = 0.0;
}

void Employee::save() {
    std::ofstream fout("Employee.txt", std::ios::app);
    if (!fout.is_open()) {
        std::cout << "Khong the mo file Employee.txt de luu!" << std::endl;
        return;
    }

    fout << employee_id << ';'
         << get_name().get_fullname() << ';'
         << get_mobile() << ';'
         << get_dob().to_string() << ';'
         << get_email() << ';'
         << department << ';'
         << base_salary << ';'
         << salary_coefficient << ';'
         << experience << ';'
         << salary << std::endl;

    fout.close();
}

CustomerServiceEmployee::CustomerServiceEmployee()
    : clients_managed(0), bonus(0.0) {}

CustomerServiceEmployee::CustomerServiceEmployee(int employee_id, const std::string& department,
                                                 double base_salary, float salary_coefficient,
                                                 int experience, int clients_managed, double bonus)
    : Employee(employee_id, department, base_salary, salary_coefficient, experience),
      clients_managed(clients_managed), bonus(bonus) {}

CustomerServiceEmployee::~CustomerServiceEmployee() = default;

void CustomerServiceEmployee::set_clients_managed(int value) {
    clients_managed = value;
}

void CustomerServiceEmployee::set_bonus(double value) {
    bonus = value;
}

int CustomerServiceEmployee::get_clients_managed() const {
    return clients_managed;
}

double CustomerServiceEmployee::get_bonus() const {
    return bonus;
}

double CustomerServiceEmployee::calculate_salary() {
    salary = base_salary * salary_coefficient + bonus;
    return salary;
}

void CustomerServiceEmployee::input() {
    Employee::input();

    std::cout << "Nhap so khach phu trach: ";
    std::cin >> clients_managed;
    std::cin.ignore();

    std::cout << "Nhap tien thuong: ";
    std::cin >> bonus;
    std::cin.ignore();

    salary = calculate_salary();
}

void CustomerServiceEmployee::display() {
    Employee::display();
    std::cout << "   -> So khach phu trach: " << clients_managed
              << ", Thuong: " << bonus << std::endl;
}

void CustomerServiceEmployee::update() {
    Employee::update();

    std::cout << "Nhap so khach phu trach moi: ";
    std::cin >> clients_managed;
    std::cin.ignore();

    std::cout << "Nhap thuong moi: ";
    std::cin >> bonus;
    std::cin.ignore();

    salary = calculate_salary();
}

void CustomerServiceEmployee::edit() {
    Employee::edit();

    std::cout << "Nhap so khach phu trach moi: ";
    std::cin >> clients_managed;
    std::cin.ignore();

    std::cout << "Nhap thuong moi: ";
    std::cin >> bonus;
    std::cin.ignore();

    salary = calculate_salary();
}

void CustomerServiceEmployee::remove() {
    Employee::remove();
    clients_managed = 0;
    bonus = 0.0;
}

void CustomerServiceEmployee::save() {
    std::ofstream fout("Employee.txt", std::ios::app);
    if (!fout.is_open()) {
        std::cout << "Khong the mo file Employee.txt de luu!" << std::endl;
        return;
    }

    fout << "CustomerService" << ';'
         << employee_id << ';'
         << get_name().get_fullname() << ';'
         << get_mobile() << ';'
         << get_dob().to_string() << ';'
         << get_email() << ';'
         << department << ';'
         << base_salary << ';'
         << salary_coefficient << ';'
         << clients_managed << ';'
         << bonus << ';'
         << salary << std::endl;

    fout.close();
}

TourGuideEmployee::TourGuideEmployee()
    : languages(""), tours_led(0), tour_bonus_per_trip(50000.0) {}

TourGuideEmployee::TourGuideEmployee(int employee_id, const std::string& department, double base_salary,
                                     float salary_coefficient, int experience,
                                     const std::string& languages, int tours_led,
                                     double tour_bonus_per_trip)
    : Employee(employee_id, department, base_salary, salary_coefficient, experience),
      languages(languages), tours_led(tours_led), tour_bonus_per_trip(tour_bonus_per_trip) {}

TourGuideEmployee::~TourGuideEmployee() = default;

void TourGuideEmployee::set_languages(const std::string& value) {
    languages = value;
}

void TourGuideEmployee::set_tours_led(int value) {
    tours_led = value;
}

void TourGuideEmployee::set_tour_bonus_per_trip(double value) {
    tour_bonus_per_trip = value;
}

std::string TourGuideEmployee::get_languages() const {
    return languages;
}

int TourGuideEmployee::get_tours_led() const {
    return tours_led;
}

double TourGuideEmployee::get_tour_bonus_per_trip() const {
    return tour_bonus_per_trip;
}

double TourGuideEmployee::calculate_salary() {
    salary = base_salary * salary_coefficient + tours_led * tour_bonus_per_trip;
    return salary;
}

void TourGuideEmployee::input() {
    Employee::input();

    std::cout << "Nhap ngon ngu su dung: ";
    std::getline(std::cin, languages);

    std::cout << "Nhap so tour da dan: ";
    std::cin >> tours_led;
    std::cin.ignore();

    std::cout << "Nhap tien thuong moi tour: ";
    std::cin >> tour_bonus_per_trip;
    std::cin.ignore();

    salary = calculate_salary();
}

void TourGuideEmployee::display() {
    Employee::display();
    std::cout << "   -> Ngon ngu: " << languages
              << ", So tour da dan: " << tours_led
              << ", Thuong moi tour: " << tour_bonus_per_trip << std::endl;
}

void TourGuideEmployee::update() {
    Employee::update();

    std::cout << "Nhap so tour da dan moi: ";
    std::cin >> tours_led;
    std::cin.ignore();

    std::cout << "Nhap thuong moi tour: ";
    std::cin >> tour_bonus_per_trip;
    std::cin.ignore();

    salary = calculate_salary();
}

void TourGuideEmployee::edit() {
    Employee::edit();

    std::cout << "Nhap danh sach ngon ngu moi: ";
    std::getline(std::cin, languages);

    std::cout << "Nhap so tour da dan moi: ";
    std::cin >> tours_led;
    std::cin.ignore();

    std::cout << "Nhap thuong moi tour: ";
    std::cin >> tour_bonus_per_trip;
    std::cin.ignore();

    salary = calculate_salary();
}

void TourGuideEmployee::remove() {
    Employee::remove();
    languages.clear();
    tours_led = 0;
    tour_bonus_per_trip = 50000.0;
}

void TourGuideEmployee::save() {
    std::ofstream fout("Employee.txt", std::ios::app);
    if (!fout.is_open()) {
        std::cout << "Khong the mo file Employee.txt de luu!" << std::endl;
        return;
    }

    fout << "TourGuide" << ';'
         << employee_id << ';'
         << get_name().get_fullname() << ';'
         << get_mobile() << ';'
         << get_dob().to_string() << ';'
         << get_email() << ';'
         << department << ';'
         << base_salary << ';'
         << salary_coefficient << ';'
         << languages << ';'
         << tours_led << ';'
         << tour_bonus_per_trip << ';'
         << salary << std::endl;

    fout.close();
}

