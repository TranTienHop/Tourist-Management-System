#pragma once
#include "SP_Date.h"
#include <iostream>
#include <string>
using namespace std;

// Forward declarations
class DanhSachKhachHang;
class DanhSachNhanVien;
class DanhSachPhuongTien;
class DanhSachDiaDanh;
class DanhSachLuuTru;
class DanhSachDichVu;

class ThongKe {
private:
    int tong_khach_hang;
    int tong_dia_danh;
    int so_lan_dia_danh_dat;
    double tong_tien;
    Date ngay_thong_ke;

public:
    ThongKe();
    ~ThongKe();

    int get_tong_khach_hang();
    int get_tong_dia_danh();
    int get_so_lan_dia_danh_dat();
    double get_tong_tien();
    Date get_ngay_thong_ke();

    void set_ngay_thong_ke(Date ngay);

    void them();
    void hien_thi();
    void cap_nhat();
    void sua();
    void xoa();
    void tim_kiem();

    void tinh_toan_thong_ke(DanhSachKhachHang& ds_khach_hang,
        DanhSachDiaDanh& ds_dia_danh,
        DanhSachDichVu& ds_dich_vu);
    void thong_ke_theo_ngay(Date ngay, DanhSachDichVu& ds_dich_vu);
    void thong_ke_theo_tour(string ma_tour, DanhSachDichVu& ds_dich_vu);
    void thong_ke_theo_khach_hang(string ma_kh, DanhSachDichVu& ds_dich_vu);

    static void hien_thi_menu_thong_ke(DanhSachKhachHang& ds_khach_hang,
        DanhSachNhanVien& ds_nhan_vien,
        DanhSachPhuongTien& ds_phuong_tien,
        DanhSachDiaDanh& ds_dia_danh,
        DanhSachLuuTru& ds_luu_tru,
        DanhSachDichVu& ds_dich_vu);
};
#pragma once
