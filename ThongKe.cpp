#include "KhachHang.h"
#include "NhanVien.h"
#include "PhuongTien.h"
#include "DiaDanh.h"
#include "LuuTru.h"
#include "DatDichVu.h"
#include "ThongKe.h"

void ThongKe::hien_thi_menu_thong_ke(DanhSachKhachHang& ds_khach_hang,
    DanhSachNhanVien& ds_nhan_vien,
    DanhSachPhuongTien& ds_phuong_tien,
    DanhSachDiaDanh& ds_dia_danh,
    DanhSachLuuTru& ds_luu_tru,
    DanhSachDichVu& ds_dich_vu) {
    int choice;
    do {
        cout << "\n=============== MENU THONG KE ===============\n";
        cout << "1. Thong ke khach hang\n";
        cout << "2. Thong ke nhan vien\n";
        cout << "3. Thong ke phuong tien\n";
        cout << "4. Thong ke dia danh\n";
        cout << "5. Thong ke luu tru\n";
        cout << "6. Thong ke dich vu\n";
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
            int dem = 0;
            for (NodeKhachHang* p = ds_khach_hang.getHead(); p; p = p->next) dem++;
            cout << "\n=== THONG KE KHACH HANG ===\n";
            cout << "Tong so khach hang: " << dem << "\n";
            if (dem > 0) ds_khach_hang.hien_thi();
            break;
        }
        case 2: {
            int dem = 0, cham_soc = 0, huong_dan = 0;
            double tong_luong = 0;
            for (NodeNhanVien* p = ds_nhan_vien.getHead(); p; p = p->next) {
                if (p->data) {
                    dem++;
                    tong_luong += p->data->tinh_luong();
                    if (dynamic_cast<NhanVienChamSoc*>(p->data)) cham_soc++;
                    else if (dynamic_cast<HuongDanVien*>(p->data)) huong_dan++;
                }
            }
            cout << "\n=== THONG KE NHAN VIEN ===\n";
            cout << "Tong so nhan vien: " << dem << "\n";
            cout << "- Nhan vien cham soc: " << cham_soc << "\n";
            cout << "- Huong dan vien: " << huong_dan << "\n";
            if (dem > 0) {
                cout << "Tong luong: " << fixed << setprecision(0) << tong_luong << " VND\n";
                cout << "Luong trung binh: " << fixed << setprecision(0) << (tong_luong / dem) << " VND\n";
            }
            break;
        }
        case 3: {
            int dem = 0, con_trong = 0, da_dat = 0, bao_tri = 0;
            for (NodePhuongTien* p = ds_phuong_tien.getHead(); p; p = p->next) {
                if (p->data) {
                    dem++;
                    switch (p->data->get_trang_thai()) {
                    case PhuongTien::CON_TRONG: con_trong++; break;
                    case PhuongTien::DA_DAT: da_dat++; break;
                    case PhuongTien::DANG_BAO_TRI: bao_tri++; break;
                    }
                }
            }
            cout << "\n=== THONG KE PHUONG TIEN ===\n";
            cout << "Tong so phuong tien: " << dem << "\n";
            cout << "- Con trong: " << con_trong << "\n";
            cout << "- Da dat: " << da_dat << "\n";
            cout << "- Dang bao tri: " << bao_tri << "\n";
            break;
        }
        case 4: {
            int dem = 0;
            double tong_gia = 0, gia_max = 0, gia_min = 999999999;
            for (NodeDiaDanh* p = ds_dia_danh.getHead(); p; p = p->next) {
                if (p->data) {
                    dem++;
                    float gia = p->data->get_gia();
                    tong_gia += gia;
                    if (gia > gia_max) gia_max = gia;
                    if (gia < gia_min) gia_min = gia;
                }
            }
            cout << "\n=== THONG KE DIA DANH ===\n";
            cout << "Tong so dia danh: " << dem << "\n";
            if (dem > 0) {
                cout << "Gia trung binh: " << fixed << setprecision(0) << (tong_gia / dem) << " VND\n";
                cout << "Gia cao nhat: " << fixed << setprecision(0) << gia_max << " VND\n";
                cout << "Gia thap nhat: " << fixed << setprecision(0) << gia_min << " VND\n";
            }
            break;
        }
        case 5: {
            int dem = 0, khach_san = 0, nha_nghi = 0, con_trong = 0, da_dat = 0, bao_tri = 0;
            NodeLuuTru* p = ds_luu_tru.getHead();
            while (p) {
                if (p->luu_tru) {
                    dem++;
                    if (dynamic_cast<KhachSan*>(p->luu_tru)) khach_san++;
                    else if (dynamic_cast<NhaNghi*>(p->luu_tru)) nha_nghi++;
                    switch (p->luu_tru->get_trang_thai()) {
                    case CON_TRONG: con_trong++; break;
                    case DA_DAT: da_dat++; break;
                    case DANG_BAO_TRI: bao_tri++; break;
                    }
                }
                p = p->next;
            }
            cout << "\n=== THONG KE LUU TRU ===\n";
            cout << "Tong so luu tru: " << dem << "\n";
            cout << "- Khach san: " << khach_san << "\n";
            cout << "- Nha nghi: " << nha_nghi << "\n";
            cout << "- Con trong: " << con_trong << "\n";
            cout << "- Da dat: " << da_dat << "\n";
            cout << "- Dang bao tri: " << bao_tri << "\n";
            break;
        }
        case 6: {
            int dem = 0;
            double tong_tien = 0;
            for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
                if (p->data) {
                    dem++;
                    tong_tien += p->data->get_tong_tien();
                }
            }
            cout << "\n=== THONG KE DICH VU ===\n";
            cout << "Tong so dich vu: " << dem << "\n";
            if (dem > 0) {
                cout << "Tong gia tri: " << fixed << setprecision(0) << tong_tien << " VND\n";
                cout << "Gia tri trung binh: " << fixed << setprecision(0) << (tong_tien / dem) << " VND\n";
            }
            break;
        }
        case 0:
            cout << "Thoat menu thong ke.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

// ============== IMPLEMENTATION CÁC PHƯƠNG THỨC MỚI ==============

ThongKe::ThongKe() {
    tong_khach_hang = 0;
    tong_dia_danh = 0;
    so_lan_dia_danh_dat = 0;
    tong_tien = 0;
}

ThongKe::~ThongKe() {}

int ThongKe::get_tong_khach_hang() { return tong_khach_hang; }
int ThongKe::get_tong_dia_danh() { return tong_dia_danh; }
int ThongKe::get_so_lan_dia_danh_dat() { return so_lan_dia_danh_dat; }
double ThongKe::get_tong_tien() { return tong_tien; }
Date ThongKe::get_ngay_thong_ke() { return ngay_thong_ke; }

void ThongKe::set_ngay_thong_ke(Date ngay) { ngay_thong_ke = ngay; }

void ThongKe::tinh_toan_thong_ke(DanhSachKhachHang& ds_khach_hang,
    DanhSachDiaDanh& ds_dia_danh,
    DanhSachDichVu& ds_dich_vu) {
    // Tính tổng khách hàng
    tong_khach_hang = 0;
    for (NodeKhachHang* p = ds_khach_hang.getHead(); p; p = p->next) tong_khach_hang++;

    // Tính tổng địa danh
    tong_dia_danh = 0;
    for (NodeDiaDanh* p = ds_dia_danh.getHead(); p; p = p->next) tong_dia_danh++;

    // Tính số lần địa danh được đặt
    so_lan_dia_danh_dat = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data && p->data->get_dia_danh()) so_lan_dia_danh_dat++;
    }

    // Tính tổng tiền
    tong_tien = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data) tong_tien += p->data->get_tong_tien();
    }
}

void ThongKe::thong_ke_theo_ngay(Date ngay, DanhSachDichVu& ds_dich_vu) {
    cout << "\n=== THONG KE THEO NGAY: " << ngay << " ===\n";
    int dem = 0;
    double tong = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data) {
            // Giả sử có ngày đặt dịch vụ (cần thêm vào DatDichVu)
            dem++;
            tong += p->data->get_tong_tien();
        }
    }
    cout << "So dich vu: " << dem << "\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tong << " VND\n";
}

void ThongKe::thong_ke_theo_tour(string ma_tour, DanhSachDichVu& ds_dich_vu) {
    cout << "\n=== THONG KE THEO TOUR: " << ma_tour << " ===\n";
    int dem = 0;
    double tong = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data && p->data->get_ma_dich_vu() == ma_tour) {
            dem++;
            tong += p->data->get_tong_tien();
        }
    }
    cout << "So dich vu: " << dem << "\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tong << " VND\n";
}

void ThongKe::thong_ke_theo_khach_hang(string ma_kh, DanhSachDichVu& ds_dich_vu) {
    cout << "\n=== THONG KE THEO KHACH HANG: " << ma_kh << " ===\n";
    int dem = 0;
    double tong = 0;
    for (NodeDichVu* p = ds_dich_vu.getHead(); p; p = p->next) {
        if (p->data && p->data->get_khach_hang() &&
            p->data->get_khach_hang()->get_ma_khach_hang() == ma_kh) {
            dem++;
            tong += p->data->get_tong_tien();
        }
    }
    cout << "So dich vu: " << dem << "\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tong << " VND\n";
}

void ThongKe::them() {
    cout << "Nhap ngay thong ke:\n";
    cin >> ngay_thong_ke;
    cout << "Da luu thong ke ngay " << ngay_thong_ke << "\n";
}

void ThongKe::hien_thi() {
    cout << "\n=== THONG KE ===\n";
    cout << "Ngay thong ke: " << ngay_thong_ke << "\n";
    cout << "Tong khach hang: " << tong_khach_hang << "\n";
    cout << "Tong dia danh: " << tong_dia_danh << "\n";
    cout << "So lan dia danh dat: " << so_lan_dia_danh_dat << "\n";
    cout << "Tong tien: " << fixed << setprecision(0) << tong_tien << " VND\n";
}

void ThongKe::cap_nhat() {
    cout << "Nhap ngay thong ke moi:\n";
    cin >> ngay_thong_ke;
    cout << "Da cap nhat ngay thong ke!\n";
}

void ThongKe::sua() {
    cout << "Sua thong tin thong ke:\n";
    them();
}

void ThongKe::xoa() {
    tong_khach_hang = 0;
    tong_dia_danh = 0;
    so_lan_dia_danh_dat = 0;
    tong_tien = 0;
    cout << "Da xoa thong ke!\n";
}

void ThongKe::tim_kiem() {
    cout << "Tim kiem thong ke theo ngay:\n";
    Date ngay;
    cin >> ngay;
    if (ngay_thong_ke == ngay) {
        hien_thi();
    }
    else {
        cout << "Khong tim thay thong ke ngay " << ngay << "\n";
    }
}
