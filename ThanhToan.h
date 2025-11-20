#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  
#include <fstream>
#include "SP_Date.h"
using namespace std;

enum LoaiThanhToan {
    TIEN_MAT,
    THE,
    VI_DIEN_TU
};

union DuLieuThanhToan {
    double so_tien_mat;
    char so_the[20];
    char tai_khoan_vi[20];
};

class ThanhToan {
private:
    string ma_thanh_toan;
    string ma_dat_dich_vu;
    float so_tien;
    LoaiThanhToan loai;
    DuLieuThanhToan du_lieu;
    Date ngay_thanh_toan;
    bool da_thanh_toan;

public:
    ThanhToan();
    ~ThanhToan();

    void gan_ma_thanh_toan(string);
    void gan_ma_dat_dich_vu(string);
    void gan_so_tien(float);
    void gan_loai(LoaiThanhToan);
    void gan_du_lieu_tien_mat(double);
    void gan_du_lieu_the(const char*);
    void gan_du_lieu_vi(const char*);
    void gan_ngay_thanh_toan(Date);
    void gan_trang_thai(bool);

    string lay_ma_thanh_toan();
    string lay_ma_dat_dich_vu();
    float lay_so_tien();
    LoaiThanhToan lay_loai();
    DuLieuThanhToan lay_du_lieu();
    Date& lay_ngay_thanh_toan();
    bool lay_trang_thai();

    void nhap();
    void hien_thi();
    void chinh_sua();
    void cap_nhat();
};

struct NodeThanhToan {
    ThanhToan* data;
    NodeThanhToan* next;
};

class DanhSachThanhToan {
private:
    NodeThanhToan* head;
public:
    DanhSachThanhToan();
    ~DanhSachThanhToan();

    void them();
    void xoa(string);
    void cap_nhat(string);
    void chinh_sua(string);
    void hien_thi();
    ThanhToan* tim_kiem(string);
    ThanhToan* tim_kiem_theo_ma_dich_vu(string ma_dich_vu);
    void insertion_sort_ngay();
    void selection_sort_so_tien();
    void bubble_sort_loai();
    void doc_file();
    void ghi_file();
    void hien_thi_menu_thanh_toan();
	NodeThanhToan* getHead() { return head; }


};
