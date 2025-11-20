#pragma once
#include "SP_Date.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Forward declarations
class DanhSachDichVu;
class DanhSachThanhToan;
class DanhSachKhachHang;

class DoanhThu {
private:
    double tong_doanh_thu;     // tổng doanh thu
    Date ngay_thong_ke;        // ngày thống kê

public:
    DoanhThu();
    DoanhThu(double tong, Date ngay);
    ~DoanhThu();

    // Getter/Setter
    double get_tong_doanh_thu();
    Date get_ngay_thong_ke();

    void set_tong_doanh_thu(double tong);
    void set_ngay_thong_ke(Date ngay);

    // CRUD cơ bản
    void them();  // Lưu báo cáo doanh thu
    void hien_thi();
    void cap_nhat();
    void sua();
    void xoa();
    void tim_kiem();

    // Phương thức tính toán doanh thu
    void tinh_tong_doanh_thu(DanhSachDichVu& ds_dich_vu, DanhSachThanhToan& ds_thanh_toan);
    void tinh_doanh_thu_theo_thang(int thang, int nam, DanhSachThanhToan& ds_thanh_toan);

    // Menu
    static void hien_thi_menu_doanh_thu(DanhSachDichVu& ds_dich_vu,
        DanhSachThanhToan& ds_thanh_toan,
        DanhSachKhachHang& ds_khach_hang);
};

