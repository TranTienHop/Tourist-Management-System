#pragma once
#include"KhachHang.h"
#include "validator.h"
using namespace std;

// class nguoi da co o file khach hang
class NhanVien : public Nguoi {
protected:
    int ma_nhan_vien;
    string phong_ban;
    double luong_co_ban;
    double luong;
    float he_so_luong;
    int kinh_nghiem;

public:
    NhanVien();
    virtual ~NhanVien();

    void set_ma_nhan_vien(int ma_nhan_vien);
    void set_phong_ban(const string& phong_ban);
    void set_luong_co_ban(double luong_co_ban);
    void set_he_so_luong(float he_so_luong);
    void set_kinh_nghiem(int kinh_nghiem);

    int get_ma_nhan_vien();
    string get_phong_ban();
    double get_luong_co_ban();
    float get_he_so_luong();
    int get_kinh_nghiem();

    // Lớp nhân viên là lớp abstract kế thừa từ lớp abstract Nguoi
    virtual void nhap() = 0;
    virtual void hien_thi() = 0;
    virtual void cap_nhat() = 0;
    virtual void chinh_sua() = 0;
    //virtual void luu() = 0;
    virtual double tinh_luong() = 0;
    virtual void doc_file(string ) = 0;

};

class NhanVienChamSoc : public NhanVien {
private:
    int so_khach_phu_trach;
    double thuong;  

public:
    NhanVienChamSoc();
    ~NhanVienChamSoc();

    void set_so_khach_phu_trach(int so_khach_phu_trach);
    void set_thuong(double thuong);

    int get_so_khach_phu_trach();
    double get_thuong();


    void nhap();
    void hien_thi();
    void cap_nhat();
    void chinh_sua();
   // void luu();
    double tinh_luong();
    void doc_file(string);
    void ghi_file(ofstream& file);
};

class HuongDanVien : public NhanVien {
private:
    string ngon_ngu;
    int so_tour_da_dan;

public:
    HuongDanVien();
    ~HuongDanVien();

    void set_ngon_ngu(const string& ngon_ngu);
    void set_so_tour_da_dan(int so_tour_da_dan);

    string get_ngon_ngu();
    int get_so_tour_da_dan();

    void nhap();
    void hien_thi();
    void cap_nhat();
    void chinh_sua();
    //void luu();
    double tinh_luong();
    void doc_file(string);
    void ghi_file(ofstream& file);
};

struct NodeNhanVien {
    NhanVien* data;
    NodeNhanVien* next;
};

class DanhSachNhanVien {
private:
    NodeNhanVien* head;

public:
    DanhSachNhanVien();
    ~DanhSachNhanVien();

    void them(NhanVien*);
    void hien_thi();
    void xoa(int ma_nv);
    NhanVien* tim_kiem(int );
    void chinh_sua(int );
    void insertion_sort_luong();
    void bubble_sort_ten();
    void doc_file(); 
    void ghi_file();
    void giai_phong();
    void hien_thi_menu_nhan_vien();
	NodeNhanVien* getHead() { return head; }


};

