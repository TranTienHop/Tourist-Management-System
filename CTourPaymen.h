#ifndef CTOURPAYMENT_H
#define CTOURPAYMENT_H

#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class CDate {
private:
    int day, month, year;
public:
    CDate() : day(1), month(1), year(2024) {}
    CDate(int d, int m, int y) : day(d), month(m), year(y) {}
    
    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }
    
    void set_day(int d) { day = d; }
    void set_month(int m) { month = m; }
    void set_year(int y) { year = y; }
    
    friend ostream& operator<<(ostream& os, const CDate& d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
    
    friend istream& operator>>(istream& is, CDate& d) {
        cout << "Ngay: "; is >> d.day;
        cout << "Thang: "; is >> d.month;
        cout << "Nam: "; is >> d.year;
        return is;
    }
};

// Enum phuong thuc thanh toan
enum PaymentMethod {
    CASH = 1,
    BANK_TRANSFER = 2,
    CREDIT_CARD = 3
};

// Union chua chi tiet thanh toan
union PaymentDetails {
    struct {
        char bank_name[100];
        char account_number[50];
    } transfer;
    
    struct {
        char card_last4[5];
        char card_type[20];
    } card;
    
    int cash_placeholder;
};

// ========== CTOURPAYMENT CLASS ==========
class CTourPayment {
private:
    string payment_id;
    string booking_id;
    float amount;
    PaymentMethod method;
    CDate payment_date;
    bool is_paid;
    PaymentDetails details;

public:
    // Constructors & Destructor
    CTourPayment();
    CTourPayment(string pid, string bid, float amt, PaymentMethod pm, CDate date);
    CTourPayment(const CTourPayment& p);
    ~CTourPayment();
    
    // Setters
    void set_payment_id(string id);
    void set_booking_id(string bid);
    void set_amount(float amt);
    void set_method(PaymentMethod pm);
    void set_payment_date(CDate date);
    void set_paid_status(bool status);
    void set_transfer_details(string bank, string account);
    void set_card_details(string last4, string card_type);
    
    // Getters
    string get_payment_id() const;
    string get_booking_id() const;
    float get_amount() const;
    PaymentMethod get_method() const;
    CDate get_payment_date() const;
    bool get_paid_status() const;
    PaymentDetails get_details() const;
    
    // Methods
    void input_payment();
    void print_payment() const;
    void edit_payment();
    void save_payment() const;
};

// ========== PAYMENTLIST CLASS ==========
struct PaymentNode {
    CTourPayment data;
    PaymentNode* next;
};

class PaymentList {
private:
    PaymentNode* head;

public:
    // Constructor & Destructor
    PaymentList();
    ~PaymentList();
    
    // Basic operations
    void add_payment(const CTourPayment& p);
    void delete_payment(string payment_id);
    void update_payment(string payment_id);
    
    // Search operations
    CTourPayment* search_payment(string payment_id);
    CTourPayment* search_by_booking_id(string booking_id);
    
    // Display & File operations
    void print_all_payments() const;
    void save_all_payments(const string& filename) const;
    void load_from_file(const string& filename);
    
    // Sort operations
    void sort_by_date();
    void sort_by_amount();
    
    // Statistics
    float calculate_total_revenue() const;
    int count_by_method(PaymentMethod method) const;
    
    // Utility
    string select_payment_id();
};

#endif
