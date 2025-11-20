#pragma once
#include <iostream>
#include <string>
#include <sstream>  
#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include "SP_Address.h"
#include "validator.h"

using namespace std;

enum TrangThai { CON_TRONG, DA_DAT, DANG_BAO_TRI };
TrangThai chuyen_str_thanh_trang_thai(const string& str);


class LuuTru {
protected:
    string ma_luu_tru;
    string ten_luu_tru;
    DiaChi dia_chi;
    string so_dien_thoai;
    double gia;
    TrangThai trang_thai;
    static string trang_thai_to_string(TrangThai tt);

public:
    LuuTru();
    virtual ~LuuTru();

    void set_ma_luu_tru(string);
    void set_ten_luu_tru(string);
    void set_dia_chi(DiaChi);
    void set_so_dien_thoai(string);
    void set_gia(double);
    void set_trang_thai(TrangThai);

    string get_ma_luu_tru();
    string get_ten_luu_tru();
    DiaChi get_dia_chi();
    string get_so_dien_thoai();
    double get_gia();
    TrangThai get_trang_thai();

    virtual void nhap() = 0;
    virtual void hien_thi() = 0;
    virtual void cap_nhat() = 0;
    virtual void sua() = 0;

    virtual void dat_phong() = 0;
    virtual void kt_trang_thai() = 0;
    virtual void cap_nhat_trang_thai() = 0;

    virtual void doc_file(string line) = 0;
    virtual void ghi_file(ofstream& file) = 0;
};

class KhachSan : public LuuTru {
private:
    int sao;
    int tong_so_phong;

public:
    KhachSan();
    ~KhachSan();

    void set_sao(int);
    void set_tong_so_phong(int);

    int get_sao();
    int get_tong_so_phong();

    void nhap();
    void hien_thi();
    void cap_nhat();
    void sua();

    void dat_phong();
    void kt_trang_thai();
    void cap_nhat_trang_thai();

    void doc_file(string line);
    void ghi_file(ofstream& file);
};

class NhaNghi : public LuuTru {
private:
    string gio_hoat_dong;
    int so_xe;
    TrangThai tinh_trang_xe; 

public:
    NhaNghi();
    ~NhaNghi();

    void set_gio_hoat_dong(string);
    void set_so_xe(int);
    void set_tinh_trang_xe(TrangThai);

    string get_gio_hoat_dong();
    int get_so_xe();
    TrangThai get_tinh_trang_xe();

    void nhap();
    void hien_thi();
    void cap_nhat();
    void sua();
    void dat_phong();


    void dat_xe();
    void kt_trang_thai();
    void cap_nhat_trang_thai();

    void doc_file(string line);
    void ghi_file(ofstream& file);
};

struct NodeLuuTru {
    LuuTru* luu_tru;     
    NodeLuuTru* next;

    NodeLuuTru(LuuTru* lt) : luu_tru(lt), next(nullptr) {}
};

class DanhSachLuuTru {
private:
    NodeLuuTru* head;

public:
    DanhSachLuuTru();
    ~DanhSachLuuTru();

    void them(LuuTru* luu_tru);
    void xoa(string ma_luu_tru);
    void chinh_sua(string ma_luu_tru);
    LuuTru* tim_kiem(string ma_luu_tru);
    void hien_thi();

    void ghi_file();
    void doc_file();

    void insertion_sort_theo_gia();
    void bubble_sort_theo_trang_thai();
    void kt_trang_thai_theo_ma(string);
    void hien_thi_menu_luu_tru();
	NodeLuuTru* getHead() { return head; }

};



