#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>  
#include <fstream>
#include "SP_Date.h"

using namespace std;

class DiaDanh {
private:
	string ma_dia_danh;
	string ten_dia_danh;
	Date ngay_khoi_hanh;
	float gia_du_lich;

public:
	DiaDanh();
	~DiaDanh();

	void set_ma_dia_danh(string);
	void set_ten_dia_danh(string);
	void set_ngay_khoi_hanh(Date);
	void set_gia(float);

	string get_ma_dia_danh();
	string get_ten_dia_danh();
	Date get_ngay_khoi_hanh();
	float get_gia();

	void nhap();
	void chinh_sua();
	void hien_thi();
	void cap_nhat();

};

struct NodeDiaDanh {
	DiaDanh* data;
	NodeDiaDanh* next;
};

class DanhSachDiaDanh {
private:
	NodeDiaDanh* head;
public:
	DanhSachDiaDanh();
	~DanhSachDiaDanh();
	void them();
	void xoa(string);
	void cap_nhat(string);
	void chinh_sua(string);
	void hien_thi();
	DiaDanh* tim_kiem(string);
	void insertion_sort_gia();
	void selection_sort_dia_danh();
	void bubble_sort_ngay();
	void doc_file();
	void hien_thi_menu_dia_danh();

};






