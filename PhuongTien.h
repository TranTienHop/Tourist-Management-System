#pragma once
#include <iostream>
#include <string>
#include <sstream>  
#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include "SP_Date.h"
#include "SP_Time.h"
using namespace std;

class PhuongTien {
public:
    enum TrangThai { CON_TRONG, DA_DAT, DANG_BAO_TRI }; 

protected:
    string ma_phuong_tien;
    string ten_phuong_tien;
    double gia_thue;
    string diem_den;
    int so_ngay_thue; // lớp máy bay không kế thừa thuộc tính này
    TrangThai trang_thai;

public:
    PhuongTien();
    virtual ~PhuongTien();

    void set_ma_phuong_tien(string ma_phuong_tien);
    void set_ten_phuong_tien(string ten_phuong_tien);
    void set_gia_thue(double gia_thue);
    void set_diem_den(string diem_den);
    void set_so_ngay_thue(int so_ngay_thue);
    void set_trang_thai(TrangThai trang_thai);

    string get_ma_phuong_tien();
    string get_ten_phuong_tien();
    double get_gia_thue();
    string get_diem_den();
    int get_so_ngay_thue();
    TrangThai get_trang_thai();
    string trang_thai_to_string();


    virtual void nhap() = 0;
    virtual void hien_thi() = 0;
    virtual void cap_nhat() = 0;
    virtual void chinh_sua() = 0;
    virtual void dat_phuong_tien() = 0;
    virtual void kiem_tra_trang_thai() = 0;
    virtual void cap_nhat_trang_thai() = 0;
    virtual void doc_file(string ) = 0;
};

class MayBay : public PhuongTien {
private:
    string hang_hang_khong;
    Date ngay_khoi_hanh;

public:
    MayBay();
    virtual ~MayBay();

    void set_hang_hang_khong(string hang_hang_khong);
    void set_ngay_khoi_hanh(Date ngay_khoi_hanh);

    string get_hang_hang_khong();
    Date get_ngay_khoi_hanh();

    void nhap();
    void hien_thi();
    void cap_nhat(); 
    void chinh_sua();
    void dat_phuong_tien();
    void kiem_tra_trang_thai();
    void cap_nhat_trang_thai();
    void doc_file(string);
};

class XeKhach : public PhuongTien {
public:
    enum LoaiXeKhach { XE_16_CHO, XE_45_CHO };

private:
    string ten_tai_xe;
    LoaiXeKhach loai_xe;

public:
    XeKhach();
    virtual ~XeKhach();

    void set_ten_tai_xe(string ten_tai_xe);
    void set_loai_xe(LoaiXeKhach loai_xe);

    string get_ten_tai_xe();
    LoaiXeKhach get_loai_xe();

    void nhap();
    void hien_thi();
    void cap_nhat(); 
    void chinh_sua();
    void dat_phuong_tien();
    void kiem_tra_trang_thai();
    void cap_nhat_trang_thai();
    void doc_file(string);
};

class XeHoi : public PhuongTien {

public:
    enum LoaiXeHoi { XE_DIEN, XE_XANG };       
    enum SoGhe { XE_5_CHO, XE_7_CHO }; 

private:
    LoaiXeHoi loai_xe;       
    SoGhe so_ghe;  

public:
    XeHoi();
    virtual ~XeHoi();

    void set_loai_xe(LoaiXeHoi loai_xe_enum);
    void set_suc_chua(SoGhe suc_chua_enum);

    LoaiXeHoi get_loai_xe_enum();
    SoGhe get_suc_chua_enum();

    void nhap();
    void hien_thi();
    void cap_nhat(); 
    void chinh_sua();
    void dat_phuong_tien();
    void kiem_tra_trang_thai();
    void cap_nhat_trang_thai();
    void doc_file(string);
};

struct NodePhuongTien {
    PhuongTien* data;
    NodePhuongTien* next;
};

class DanhSachPhuongTien {
private:
    NodePhuongTien* head;

public:
    DanhSachPhuongTien();
    ~DanhSachPhuongTien();

    void them(PhuongTien* phuong_tien);
    void xoa(string ma_phuong_tien);
    void hien_thi();
    void chinh_sua(string ma_phuong_tien);
    PhuongTien* tim_kiem(string ma_phuong_tien);
    void insertion_sort_theo_gia();
    void bubble_sort_theo_trang_thai();
    void doc_file();
    void hien_thi_menu_phuong_tien();
	NodePhuongTien getHead() { return head; }


};


