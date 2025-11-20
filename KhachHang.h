#pragma once
#include <iostream>
#include <string>
#include <sstream>  
#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include "SP_Name.h"
#include "SP_Date.h"
#include "validator.h"
using namespace std;

class Nguoi {
protected:
    Name ten;
    string so_dien_thoai;
    Date ngay_sinh;
    string email;
public:
    Nguoi();
    virtual ~Nguoi();

    void set_ten(const Name& ten);
    void set_so_dien_thoai(string so_dien_thoai);
    void set_ngay_sinh(const Date& ngay_sinh);
    void set_email(const string& email);

    Name get_ten();
    string get_so_dien_thoai();
    Date get_ngay_sinh();
    string get_email();

    virtual void nhap()=0;
    virtual void hien_thi()=0;

    virtual void cap_nhat() = 0;
    virtual void chinh_sua() = 0;
};

class KhachHang : public Nguoi {
private:
    string ma_khach_hang;
    int so_nguoi;
    double tong_chi_tieu;

public:
    KhachHang();
    ~KhachHang();

    void set_ma_khach_hang(const string& ma_khach_hang);
    void set_so_nguoi(int so_nguoi);
    void set_tong_chi_tieu(double tong_chi_tieu);

    string get_ma_khach_hang();
    int get_so_nguoi();
    double get_tong_chi_tieu();

    void nhap();
    void hien_thi();

    void cap_nhat();
    void chinh_sua();

};
struct NodeKhachHang {
    KhachHang* data;
    NodeKhachHang* next;
    NodeKhachHang(KhachHang* kh) : data(kh), next(nullptr) {}
};


class DanhSachKhachHang {
private:
    NodeKhachHang* head;

public:
    DanhSachKhachHang();
    ~DanhSachKhachHang();

    void them(KhachHang*);
    void hien_thi();
    void xoa(const string&);
    KhachHang* tim_kiem(const string&);
    void chinh_sua(const string&);
    void cap_nhat(const string&);
    void merge_sort_chi_tieu();
    NodeKhachHang* chia_doi(NodeKhachHang* head);
    NodeKhachHang* tron(NodeKhachHang* a, NodeKhachHang* b);
    NodeKhachHang* merge_sort(NodeKhachHang* head);
    void bubble_sort_ten();
    void doc_file();
    void ghi_file();

    void giai_phong();
    void hien_thi_menu_khach_hang();
	NodeKhachHang* getHead() { return head; }


};



