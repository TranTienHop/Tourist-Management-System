#include "CTourPayment.h"
#include <fstream>
#include <iomanip>
#include <cstring>

// ========== CTOURPAYMENT CLASS ==========

// Constructor mac dinh - khoi tao gia tri ban dau
CTourPayment::CTourPayment() {
    payment_id = "P000";
    booking_id = "B000";
    amount = 0.0f;
    method = CASH;
    payment_date = CDate();
    is_paid = false;
    details.cash_placeholder = 0;
}

// Constructor co tham so
CTourPayment::CTourPayment(string pid, string bid, float amt, PaymentMethod pm, CDate date) {
    payment_id = pid;
    booking_id = bid;
    amount = amt;
    method = pm;
    payment_date = date;
    is_paid = false;
    details.cash_placeholder = 0;
}

// Copy constructor - sao chep doi tuong
CTourPayment::CTourPayment(const CTourPayment& p) {
    payment_id = p.payment_id;
    booking_id = p.booking_id;
    amount = p.amount;
    method = p.method;
    payment_date = p.payment_date;
    is_paid = p.is_paid;
    
    // Sao chep union dua theo phuong thuc thanh toan
    if (method == BANK_TRANSFER) {
        strcpy(details.transfer.bank_name, p.details.transfer.bank_name);
        strcpy(details.transfer.account_number, p.details.transfer.account_number);
    } else if (method == CREDIT_CARD) {
        strcpy(details.card.card_last4, p.details.card.card_last4);
        strcpy(details.card.card_type, p.details.card.card_type);
    } else {
        details.cash_placeholder = p.details.cash_placeholder;
    }
}

// Destructor
CTourPayment::~CTourPayment() {}

// ===== SETTERS =====
void CTourPayment::set_payment_id(string id) { payment_id = id; }
void CTourPayment::set_booking_id(string bid) { booking_id = bid; }
void CTourPayment::set_amount(float amt) { amount = amt; }
void CTourPayment::set_method(PaymentMethod pm) { method = pm; }
void CTourPayment::set_payment_date(CDate date) { payment_date = date; }
void CTourPayment::set_paid_status(bool status) { is_paid = status; }

// Thiet lap thong tin chuyen khoan
void CTourPayment::set_transfer_details(string bank, string account) {
    strcpy(details.transfer.bank_name, bank.c_str());
    strcpy(details.transfer.account_number, account.c_str());
}

// Thiet lap thong tin the
void CTourPayment::set_card_details(string last4, string card_type) {
    strcpy(details.card.card_last4, last4.c_str());
    strcpy(details.card.card_type, card_type.c_str());
}

// ===== GETTERS =====
string CTourPayment::get_payment_id() const { return payment_id; }
string CTourPayment::get_booking_id() const { return booking_id; }
float CTourPayment::get_amount() const { return amount; }
PaymentMethod CTourPayment::get_method() const { return method; }
CDate CTourPayment::get_payment_date() const { return payment_date; }
bool CTourPayment::get_paid_status() const { return is_paid; }
PaymentDetails CTourPayment::get_details() const { return details; }

// ===== NHAP THONG TIN THANH TOAN =====
void CTourPayment::input_payment() {
    cout << "\n===== NHAP THONG TIN THANH TOAN =====\n";
    
    // Nhap ma thanh toan
    cout << "Nhap ma thanh toan: ";
    cin.ignore();
    getline(cin, payment_id);
    
    // Nhap ma booking
    cout << "Nhap ma booking: ";
    getline(cin, booking_id);
    
    // Nhap so tien
    cout << "Nhap so tien thanh toan (VND): ";
    cin >> amount;
    
    // Nhap phuong thuc thanh toan
    int choice;
    cout << "\nChon phuong thuc thanh toan:\n";
    cout << "1. Tien mat\n";
    cout << "2. Chuyen khoan\n";
    cout << "3. The tin dung/ghi no\n";
    cout << "Lua chon: ";
    cin >> choice;
    
    method = static_cast<PaymentMethod>(choice);
    
    // Nhap chi tiet tuy theo phuong thuc
    cin.ignore();
    if (method == BANK_TRANSFER) {
        string bank, account;
        cout << "Nhap ten ngan hang: ";
        getline(cin, bank);
        cout << "Nhap so tai khoan: ";
        getline(cin, account);
        set_transfer_details(bank, account);
    } 
    else if (method == CREDIT_CARD) {
        string last4, card_type;
        cout << "Nhap 4 so cuoi cua the: ";
        getline(cin, last4);
        cout << "Nhap loai the (Visa/Mastercard/...): ";
        getline(cin, card_type);
        set_card_details(last4, card_type);
    }
    
    // Nhap ngay thanh toan
    cout << "\nNhap ngay thanh toan:\n";
    cin >> payment_date;
    
    // Nhap trang thai
    char status;
    cout << "Da thanh toan? (y/n): ";
    cin >> status;
    is_paid = (status == 'y' || status == 'Y');
    
    cout << "Nhap thanh cong!\n";
}

// ===== HIEN THI THONG TIN THANH TOAN =====
void CTourPayment::print_payment() const {
    cout << "\n===== THONG TIN THANH TOAN =====\n";
    cout << "Ma thanh toan: " << payment_id << endl;
    cout << "Ma booking: " << booking_id << endl;
    cout << "So tien: " << fixed << setprecision(0) << amount << " VND" << endl;
    
    // Hien thi phuong thuc
    cout << "Phuong thuc: ";
    switch (method) {
        case CASH:
            cout << "Tien mat\n";
            break;
        case BANK_TRANSFER:
            cout << "Chuyen khoan\n";
            cout << "  - Ngan hang: " << details.transfer.bank_name << endl;
            cout << "  - So TK: " << details.transfer.account_number << endl;
            break;
        case CREDIT_CARD:
            cout << "The tin dung/ghi no\n";
            cout << "  - Loai the: " << details.card.card_type << endl;
            cout << "  - 4 so cuoi: " << details.card.card_last4 << endl;
            break;
    }
    
    cout << "Ngay thanh toan: " << payment_date << endl;
    cout << "Trang thai: " << (is_paid ? "Da thanh toan" : "Chua thanh toan") << endl;
    cout << "================================\n";
}

// ===== CHINH SUA THONG TIN =====
void CTourPayment::edit_payment() {
    int choice;
    do {
        cout << "\n===== CHINH SUA THANH TOAN " << payment_id << " =====\n";
        cout << "1. Sua so tien\n";
        cout << "2. Sua phuong thuc thanh toan\n";
        cout << "3. Sua ngay thanh toan\n";
        cout << "4. Thay doi trang thai\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Nhap so tien moi: ";
                cin >> amount;
                break;
                
            case 2: {
                int new_method;
                cout << "Chon phuong thuc moi (1-Tien mat, 2-Chuyen khoan, 3-The): ";
                cin >> new_method;
                method = static_cast<PaymentMethod>(new_method);
                
                cin.ignore();
                if (method == BANK_TRANSFER) {
                    string bank, account;
                    cout << "Nhap ten ngan hang: ";
                    getline(cin, bank);
                    cout << "Nhap so tai khoan: ";
                    getline(cin, account);
                    set_transfer_details(bank, account);
                } 
                else if (method == CREDIT_CARD) {
                    string last4, card_type;
                    cout << "Nhap 4 so cuoi: ";
                    getline(cin, last4);
                    cout << "Nhap loai the: ";
                    getline(cin, card_type);
                    set_card_details(last4, card_type);
                }
                break;
            }
                
            case 3:
                cout << "Nhap ngay moi:\n";
                cin >> payment_date;
                break;
                
            case 4:
                is_paid = !is_paid;
                cout << "Trang thai: " << (is_paid ? "Da thanh toan" : "Chua thanh toan") << endl;
                break;
                
            case 0:
                cout << "Thoat chinh sua.\n";
                break;
                
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

// ===== LUU VAO FILE =====
void CTourPayment::save_payment() const {
    ofstream out("payment.txt", ios::app);
    if (!out.is_open()) {
        cout << "Khong mo duoc file payment.txt!\n";
        return;
    }
    
    // Format: payment_id;booking_id;amount;method;date;is_paid;details
    out << payment_id << ";"
        << booking_id << ";"
        << amount << ";"
        << method << ";"
        << payment_date.get_day() << "/" 
        << payment_date.get_month() << "/" 
        << payment_date.get_year() << ";"
        << is_paid << ";";
    
    // Luu chi tiet tuy theo phuong thuc
    if (method == BANK_TRANSFER) {
        out << details.transfer.bank_name << ";"
            << details.transfer.account_number;
    } else if (method == CREDIT_CARD) {
        out << details.card.card_type << ";"
            << details.card.card_last4;
    } else {
        out << "CASH;NONE";
    }
    
    out << "\n";
    out.close();
    cout << "Luu thanh cong!\n";
}

// ========== PAYMENTLIST CLASS ==========

// Constructor
PaymentList::PaymentList() {
    head = NULL;
}

// Destructor - giai phong bo nho
PaymentList::~PaymentList() {
    PaymentNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// ===== THEM THANH TOAN =====
void PaymentList::add_payment(const CTourPayment& p) {
    PaymentNode* newNode = new PaymentNode;
    newNode->data = p;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        PaymentNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    cout << "Da them thanh toan vao danh sach!\n";
}

// ===== XOA THANH TOAN =====
void PaymentList::delete_payment(string payment_id) {
    if (head == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }
    
    PaymentNode* temp = head;
    PaymentNode* prev = NULL;
    
    // Tim node can xoa
    while (temp != NULL && temp->data.get_payment_id() != payment_id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Khong tim thay thanh toan voi ID: " << payment_id << endl;
        return;
    }
    
    // Xoa node
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    
    delete temp;
    cout << "Da xoa thanh toan!\n";
}

// ===== CAP NHAT THANH TOAN =====
void PaymentList::update_payment(string payment_id) {
    CTourPayment* found = search_payment(payment_id);
    if (found != NULL) {
        found->edit_payment();
        cout << "Cap nhat thanh cong!\n";
    } else {
        cout << "Khong tim thay thanh toan!\n";
    }
}

// ===== TIM KIEM THEO PAYMENT ID =====
CTourPayment* PaymentList::search_payment(string payment_id) {
    PaymentNode* temp = head;
    while (temp != NULL) {
        if (temp->data.get_payment_id() == payment_id) {
            return &temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

// ===== TIM KIEM THEO BOOKING ID =====
CTourPayment* PaymentList::search_by_booking_id(string booking_id) {
    PaymentNode* temp = head;
    while (temp != NULL) {
        if (temp->data.get_booking_id() == booking_id) {
            return &temp->data;
        }
        temp = temp->next;
    }
    return NULL;
}

// ===== HIEN THI TAT CA =====
void PaymentList::print_all_payments() const {
    if (head == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }
    
    cout << "\n===== DANH SACH THANH TOAN =====\n";
    PaymentNode* temp = head;
    while (temp != NULL) {
        temp->data.print_payment();
        temp = temp->next;
    }
}

// ===== LUU TAT CA VAO FILE =====
void PaymentList::save_all_payments(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }
    
    PaymentNode* temp = head;
    while (temp != NULL) {
        out << temp->data.get_payment_id() << ";"
            << temp->data.get_booking_id() << ";"
            << temp->data.get_amount() << ";"
            << temp->data.get_method() << ";"
            << temp->data.get_payment_date().get_day() << "/"
            << temp->data.get_payment_date().get_month() << "/"
            << temp->data.get_payment_date().get_year() << ";"
            << temp->data.get_paid_status() << ";";
        
        PaymentMethod m = temp->data.get_method();
        PaymentDetails d = temp->data.get_details();
        
        if (m == BANK_TRANSFER) {
            out << d.transfer.bank_name << ";" << d.transfer.account_number;
        } else if (m == CREDIT_CARD) {
            out << d.card.card_type << ";" << d.card.card_last4;
        } else {
            out << "CASH;NONE";
        }
        
        out << "\n";
        temp = temp->next;
    }
    
    out.close();
    cout << "Da luu tat ca thanh toan vao file!\n";
}

// ===== DOC TU FILE =====
void PaymentList::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Khong tim thay file " << filename << endl;
        return;
    }
    
    string line;
    while (getline(in, line)) {
        // Parse du lieu tu file (can implement day du)
        // Day la phan don gian hoa
        cout << "Doc du lieu tu file...\n";
    }
    
    in.close();
    cout << "Tai du lieu thanh cong!\n";
}

// ===== SAP XEP THEO NGAY =====
void PaymentList::sort_by_date() {
    if (head == NULL || head->next == NULL) return;
    
    for (PaymentNode* i = head; i != NULL; i = i->next) {
        for (PaymentNode* j = i->next; j != NULL; j = j->next) {
            CDate d1 = i->data.get_payment_date();
            CDate d2 = j->data.get_payment_date();
            
            // So sanh ngay (nam -> thang -> ngay)
            if (d1.get_year() > d2.get_year() ||
                (d1.get_year() == d2.get_year() && d1.get_month() > d2.get_month()) ||
                (d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month() && d1.get_day() > d2.get_day())) {
                swap(i->data, j->data);
            }
        }
    }
    
    cout << "Da sap xep theo ngay!\n";
}

// ===== SAP XEP THEO SO TIEN =====
void PaymentList::sort_by_amount() {
    if (head == NULL || head->next == NULL) return;
    
    for (PaymentNode* i = head; i != NULL; i = i->next) {
        for (PaymentNode* j = i->next; j != NULL; j = j->next) {
            if (i->data.get_amount() > j->data.get_amount()) {
                swap(i->data, j->data);
            }
        }
    }
    
    cout << "Da sap xep theo so tien!\n";
}

// ===== TINH TONG DOANH THU =====
float PaymentList::calculate_total_revenue() const {
    float total = 0.0f;
    PaymentNode* temp = head;
    
    while (temp != NULL) {
        if (temp->data.get_paid_status()) {
            total += temp->data.get_amount();
        }
        temp = temp->next;
    }
    
    return total;
}

// ===== DEM THEO PHUONG THUC =====
int PaymentList::count_by_method(PaymentMethod method) const {
    int count = 0;
    PaymentNode* temp = head;
    
    while (temp != NULL) {
        if (temp->data.get_method() == method) {
            count++;
        }
        temp = temp->next;
    }
    
    return count;
}

// ===== CHON PAYMENT ID (dung cho booking) =====
string PaymentList::select_payment_id() {
    if (head == NULL) {
        cout << "Chua co thanh toan nao!\n";
        return "P000";
    }
    
    cout << "\n===== DANH SACH PAYMENT ID =====\n";
    PaymentNode* temp = head;
    int i = 1;
    
    while (temp != NULL) {
        cout << i++ << ". " << temp->data.get_payment_id() 
             << " - " << temp->data.get_amount() << " VND\n";
        temp = temp->next;
    }
    
    string selected_id;
    cout << "Nhap payment ID: ";
    cin.ignore();
    getline(cin, selected_id);
    
    return selected_id;
}
