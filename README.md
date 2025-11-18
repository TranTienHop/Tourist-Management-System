# Tourist-Management-System

Hệ thống Quản Lý Du Lịch được xây dựng bằng ngôn ngữ C++, áp dụng mô hình hướng đối tượng (OOP).
Dự án mô phỏng việc quản lý các thành phần trong một hệ thống du lịch.

Chức năng chính
1. Quản lý công ty.
2. Quản lý người dùng (khách hàng, nhân viên).
3. Quản lý địa danh.
4. Quản lý dịch vụ.
5. Quản lý thanh toán.
6. Quản lí phương tiện.
7. Quản lí lưu trú (chỗ ở: khách sạn, nhà nghỉ).
   
Kiểu dữ liệu hỗ trợ: Name, Date, Time, Address. 

Hệ thống sử dụng **"LINKED LIST"** để quản lý dữ liệu trong quá trình chạy chương trình và lưu trữ vào file .txt để đảm bảo dữ liệu không bị mất khi thoát chương trình.
Dữ liệu được tổ chức thành các danh sách: dịch vụ, nhân viên, khách hàng, địa danh, phương tiện, lưu trú.
```
Sơ đồ phân cấp thư mục & file
 ├─> CôngTy
 │     ├─> CongTy.h
 │     └─> CongTy.cpp
 │
 ├─> ĐịaDanh
 │     ├─> DiaDanh.h
 │     └─> DiaDanh.cpp
 │
 ├─> Người
 │     ├─> KháchHàng
 │     │      ├─> KhachHang.h
 │     │      └─> KhachHang.cpp
 │     └─> NhânViên
 │            ├─> NhanVien.h
 │            └─> NhanVien.cpp
 │
 ├─> DịchVụ
 │      ├─> ĐặtDịchVụ
 │      │      ├─> DatDichVu.h
 │      │      └> DatDichVu.cpp
 │      ├─> LưuTrú
 │      │      ├─> LuuTru.h
 │      │      └─> LuuTru.cpp
 │      ├─> PhươngTiện
 │      │      ├─> PhuongTien.h
 │      │      └─> PhuongTien.cpp
 │      └─> ThanhToán
 │             ├─> ThanhToan.h
 │             └─> ThanhToan.cpp
 │
 ├─> Kiểu dữ liệu tự hỗ trợ (Support)
 │      ├─> SP_Address.h  ──> SP_Address.cpp
 │      ├─> SP_Date.h     ──> SP_Date.cpp
 │      ├─> SP_Name.h     ──> SP_Name.cpp
 │      └─> SP_Time.h     ──> SP_Time.cpp
 │
 ├─> Data
 │      ├─> ds_dich_vu
 │      ├─> ds_luu_tru
 │      ├─> ds_nhan_vien
 │      └─> ...
 │
 └─> Main.cpp
```

