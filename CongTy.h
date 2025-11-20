#pragma once
#include"KhachHang.h"
#include"NhanVien.h"
#include"PhuongTien.h"
#include"ThanhToan.h"
#include"DiaDanh.h"
#include"LuuTru.h"
#include"DatDichVu.h"
#include"DoanhThu.h"
#include"ThongKe.h"
#include <iostream>
#include <string>
using namespace std;

class CongTy {
private:
	DanhSachKhachHang ds_khach_hang;
	DanhSachNhanVien ds_nhan_vien;
	DanhSachPhuongTien ds_phuong_tien;
	DanhSachDiaDanh ds_dia_danh;
	DanhSachLuuTru ds_luu_tru;
	DanhSachThanhToan ds_thanh_toan;
	DanhSachDichVu ds_dich_vu;

public:
	CongTy();
	~CongTy();

	void nhap();
	void hien_thi();
	void tim_kiem();
	void sap_xep();
	void chinh_sua();
	void doc_file();

	void hien_thi_menu_admin();
	void hien_thi_menu_khach_hang();
	void hien_thi_menu_nhan_vien();
	void hien_thi_menu_phuong_tien();
	void hien_thi_menu_dia_danh();
	void hien_thi_menu_luu_tru();
	void hien_thi_menu_thanh_toan();
	void hien_thi_menu_dich_vu();
	void hien_thi_menu_doanh_thu();
	void hien_thi_menu_thong_ke();
};
