#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>  
#include <fstream>
#include "SP_Date.h"
#include "KhachHang.h"
#include "NhanVien.h"
#include "PhuongTien.h"
#include "ThanhToan.h"
#include "DiaDanh.h"
#include "LuuTru.h"

using namespace std;

class DatDichVu {
private:
    string ma_dich_vu;
    KhachHang* khach_hang;
    NhanVien* nhan_vien_hd;
    PhuongTien* phuong_tien;
    DiaDanh* dia_danh;
    LuuTru* luu_tru;

    float tong_tien;
    Date ngay_dat_dich_vu;

public:
    DatDichVu();
    ~DatDichVu();

    void set_ma_dich_vu(string);
    string get_ma_dich_vu();


    void set_khach_hang(KhachHang*);
    void set_nhan_vien_hd(NhanVien*);
    void set_phuong_tien(PhuongTien*);
    void set_dia_danh(DiaDanh*);
    void set_luu_tru(LuuTru*);

    KhachHang* get_khach_hang();
    NhanVien* get_nhan_vien_hd();
    PhuongTien* get_phuong_tien();
    DiaDanh* get_dia_danh();
    LuuTru* get_luu_tru();

    float get_tong_tien();
    void tinh_tong_tien();

    void hien_thi();
    void nhap();
    void cap_nhat();
};

struct NodeDichVu {
    DatDichVu* data;
    NodeDichVu* next;
};

class DanhSachDichVu {
private:
    NodeDichVu* head;

public:
    DanhSachDichVu();
    ~DanhSachDichVu();

    void them();
    void hien_thi();
    void xoa(string);
    void chinh_sua(string);
    void cap_nhat(string);
    DatDichVu* tim_kiem(string);
    void hien_thi_menu_dich_vu();
	NodeDichVu* getHead() { return head; }


    void doc_file(DanhSachKhachHang& dsKH,
        DanhSachNhanVien& dsNV,
        DanhSachPhuongTien& dsPT,
        DanhSachDiaDanh& dsDD,
        DanhSachLuuTru& dsLT,
        DanhSachThanhToan& dsTT);
};

