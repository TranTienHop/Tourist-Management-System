#include "ThanhToan.h"
#include "DatDichVu.h"
#include "KhachHang.h"
#include "DoanhThu.h"
#include "CongTy.h"

void DoanhThu::hien_thi_menu_doanh_thu(DanhSachDichVu& ds_dich_vu,
    DanhSachThanhToan& ds_thanh_toan,
    DanhSachKhachHang& ds_khach_hang) {
    int choice;
    do {
        cout << "\n=============== MENU DOANH THU ===============\n";
        cout << "1. Tong doanh thu\n";
        cout << "2. Doanh thu theo thang\n";
        cout << "3. Doanh thu theo loai thanh toan\n";
        cout << "4. Top khach hang chi tieu cao nhat\n";
        cout << "5. Doanh thu trung binh theo dich vu\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Lua chon khong hop le! Vui long nhap so.\n";
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1: {
            double tong = 0;
            for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
                if (p->data && p->data->get_tong_tien() > 0) {
                    // Kiểm tra xem có thanh toán tương ứng không
                    ThanhToan* tt = ds_thanh_toan.tim_kiem_theo_ma_dich_vu(p->data->get_ma_dich_vu());
                    if (tt && tt->lay_trang_thai()) {
                        tong += p->data->get_tong_tien();
                    }
                }
            }
            cout << "\n=== TONG DOANH THU ===\n";
            cout << "Tong doanh thu: " << fixed << setprecision(0) << tong << " VND\n";
            break;
        }
        case 2: {
            int thang, nam;
            cout << "Nhap thang (1-12): ";
            cin >> thang;
            if (cin.fail() || thang < 1 || thang > 12) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Thang khong hop le!\n";
                break;
            }
            cout << "Nhap nam: ";
            cin >> nam;
            if (cin.fail() || nam < 1) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Nam khong hop le!\n";
                break;
            }
            cin.ignore();

            double tong = 0;
            int dem = 0;
            for (NodeThanhToan* p = ds_thanh_toan.getHead(); p; p = p->next) {
                if (p->data && p->data->lay_trang_thai()) {
                    Date ngay = p->data->lay_ngay_thanh_toan();
                    if (ngay.get_thang() == thang && ngay.get_nam() == nam) {
                        tong += p->data->lay_so_tien();
                        dem++;
                    }
                }
            }
            cout << "\n=== DOANH THU THANG " << thang << "/" << nam << " ===\n";
            cout << "So giao dich: " << dem << "\n";
            cout << "Tong doanh thu: " << fixed << setprecision(0) << tong << " VND\n";
            break;
        }
        case 3: {
            cout << "\n=== DOANH THU THEO LOAI THANH TOAN ===\n";
            double tien_mat = 0, the = 0, vi = 0;
            int dem_tm = 0, dem_the = 0, dem_vi = 0;

            for (NodeThanhToan* p = ds_thanh_toan.getHead(); p; p = p->next) {
                if (p->data && p->data->lay_trang_thai()) {
                    switch (p->data->lay_loai()) {
                    case TIEN_MAT:
                        tien_mat += p->data->lay_so_tien();
                        dem_tm++;
                        break;
                    case THE:
                        the += p->data->lay_so_tien();
                        dem_the++;
                        break;
                    case VI_DIEN_TU:
                        vi += p->data->lay_so_tien();
                        dem_vi++;
                        break;
                    }
                }
            }

            cout << "Tien mat: " << fixed << setprecision(0) << tien_mat << " VND (" << dem_tm << " giao dich)\n";
            cout << "The: " << fixed << setprecision(0) << the << " VND (" << dem_the << " giao dich)\n";
            cout << "Vi dien tu: " << fixed << setprecision(0) << vi << " VND (" << dem_vi << " giao dich)\n";
            cout << "Tong: " << fixed << setprecision(0) << (tien_mat + the + vi) << " VND\n";
            break;
        }
        case 4: {
            cout << "\n=== TOP 5 KHACH HANG CHI TIEU CAO NHAT ===\n";
            // Sử dụng merge sort để sắp xếp theo chi tiêu
            ds_khach_hang.merge_sort_chi_tieu();
            ds_khach_hang.hien_thi();
            break;
        }
        case 5: {
            double tong = 0;
            int dem = 0;
            for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
                if (p->data) {
                    tong += p->data->get_tong_tien();
                    dem++;
                }
            }
            if (dem > 0) {
                double trung_binh = tong / dem;
                cout << "\n=== DOANH THU TRUNG BINH ===\n";
                cout << "So dich vu: " << dem << "\n";
                cout << "Tong doanh thu: " << fixed << setprecision(0) << tong << " VND\n";
                cout << "Trung binh moi dich vu: " << fixed << setprecision(0) << trung_binh << " VND\n";
            }
            else {
                cout << "Khong co dich vu nao!\n";
            }
            break;
        }
        case 0:
            cout << "Thoat menu doanh thu.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

// ============== IMPLEMENTATION CÁC PHƯƠNG THỨC MỚI ==============

DoanhThu::DoanhThu() {
    tong_doanh_thu = 0;
}

DoanhThu::DoanhThu(double tong, Date ngay) {
    tong_doanh_thu = tong;
    ngay_thong_ke = ngay;
}

DoanhThu::~DoanhThu() {}

double DoanhThu::get_tong_doanh_thu() { return tong_doanh_thu; }
Date DoanhThu::get_ngay_thong_ke() { return ngay_thong_ke; }

void DoanhThu::set_tong_doanh_thu(double tong) { tong_doanh_thu = tong; }
void DoanhThu::set_ngay_thong_ke(Date ngay) { ngay_thong_ke = ngay; }

void DoanhThu::tinh_tong_doanh_thu(DanhSachDichVu& ds_dich_vu, DanhSachThanhToan& ds_thanh_toan) {
    tong_doanh_thu = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data && p->data->get_tong_tien() > 0) {
            ThanhToan* tt = ds_thanh_toan.tim_kiem_theo_ma_dich_vu(p->data->get_ma_dich_vu());
            if (tt && tt->lay_trang_thai()) {
                tong_doanh_thu += p->data->get_tong_tien();
            }
        }
    }
}

void DoanhThu::tinh_doanh_thu_theo_thang(int thang, int nam, DanhSachThanhToan& ds_thanh_toan) {
    tong_doanh_thu = 0;
    for (NodeThanhToan* p = ds_thanh_toan.getHead(); p; p = p->next) {
        if (p->data && p->data->lay_trang_thai()) {
            Date ngay = p->data->lay_ngay_thanh_toan();
            if (ngay.get_thang() == thang && ngay.get_nam() == nam) {
                tong_doanh_thu += p->data->lay_so_tien();
            }
        }
    }
}

void DoanhThu::them() {
    cout << "Nhap ngay thong ke:\n";
    cin >> ngay_thong_ke;
    cout << "Nhap tong doanh thu: ";
    cin >> tong_doanh_thu;
    cin.ignore();
    cout << "Da luu bao cao doanh thu!\n";
}

void DoanhThu::hien_thi() {
    cout << "\n=== BAO CAO DOANH THU ===\n";
    cout << "Ngay thong ke: " << ngay_thong_ke << "\n";
    cout << "Tong doanh thu: " << fixed << setprecision(0) << tong_doanh_thu << " VND\n";
}

void DoanhThu::cap_nhat() {
    cout << "Nhap tong doanh thu moi: ";
    cin >> tong_doanh_thu;
    cin.ignore();
    cout << "Da cap nhat doanh thu!\n";
}

void DoanhThu::sua() {
    cout << "Sua thong tin doanh thu:\n";
    them();
}

void DoanhThu::xoa() {
    tong_doanh_thu = 0;
    cout << "Da xoa bao cao doanh thu!\n";
}

void DoanhThu::tim_kiem() {
    cout << "Tim kiem doanh thu theo ngay:\n";
    Date ngay;
    cin >> ngay;
    if (ngay_thong_ke == ngay) {
        hien_thi();
    }
    else {
        cout << "Khong tim thay bao cao doanh thu ngay " << ngay << "\n";
    }
}
