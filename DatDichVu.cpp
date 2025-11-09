#include "DatDichVu.h"
#include <fstream>
#include <sstream>

DatDichVu::DatDichVu() {
    ma_dich_vu = "";
    khach_hang = nullptr;
    nhan_vien_hd = nullptr;
    phuong_tien = nullptr;
    dia_danh = nullptr;
    luu_tru = nullptr;
    tong_tien = 0;
}

DatDichVu::~DatDichVu() {}

void DatDichVu::set_ma_dich_vu(string s) { ma_dich_vu = s; }
string DatDichVu::get_ma_dich_vu() { return ma_dich_vu; }

void DatDichVu::set_khach_hang(KhachHang* p) { khach_hang = p; }
void DatDichVu::set_nhan_vien_hd(NhanVien* p) { nhan_vien_hd = p; }
void DatDichVu::set_phuong_tien(PhuongTien* p) { phuong_tien = p; }
void DatDichVu::set_dia_danh(DiaDanh* p) { dia_danh = p; }
void DatDichVu::set_luu_tru(LuuTru* p) { luu_tru = p; }

KhachHang* DatDichVu::get_khach_hang() { return khach_hang; }
NhanVien* DatDichVu::get_nhan_vien_hd() { return nhan_vien_hd; }
PhuongTien* DatDichVu::get_phuong_tien() { return phuong_tien; }
DiaDanh* DatDichVu::get_dia_danh() { return dia_danh; }
LuuTru* DatDichVu::get_luu_tru() { return luu_tru; }

float DatDichVu::get_tong_tien() { return tong_tien; }

void DatDichVu::tinh_tong_tien() {
    tong_tien = 0;
    if (phuong_tien) tong_tien += phuong_tien->get_gia_thue();
    if (dia_danh) tong_tien += dia_danh->get_gia();
    if (luu_tru) tong_tien += luu_tru->get_gia();
}
void DatDichVu::nhap() {
    cout << "Nhap ma dich vu: ";
    getline(cin, ma_dich_vu);

    string id_kh, id_nv, id_pt, id_dd, id_lt;

    cout << "Nhap ma khach hang: ";
    getline(cin, id_kh);

    cout << "Nhap ma nhan vien: ";
    getline(cin, id_nv);

    cout << "Nhap ma phuong tien: ";
    getline(cin, id_pt);

    cout << "Nhap ma dia danh: ";
    getline(cin, id_dd);

    cout << "Nhap ma luu tru: ";
    getline(cin, id_lt);

    tinh_tong_tien(); // tổng tiền tính tự động
}
void DatDichVu::cap_nhat() {
    cout << "Nhap ngay dat dich vu moi:\n";
    cin >> ngay_dat_dich_vu; 
    cout << "Ngay dich vu da cap nhat: " << ngay_dat_dich_vu << endl;
}

void DatDichVu::hien_thi() {
    cout << "Ma DV: " << ma_dich_vu << "\n";
    if (khach_hang) khach_hang->hien_thi();
    if (nhan_vien_hd) nhan_vien_hd->hien_thi();
    if (phuong_tien) phuong_tien->hien_thi();
    if (dia_danh) dia_danh->hien_thi();
    if (luu_tru) luu_tru->hien_thi();
    cout << "Tong tien: " << tong_tien << "\n";
    cout << "---------------------------\n";
}


DanhSachDichVu::DanhSachDichVu() { head = nullptr; }
DanhSachDichVu::~DanhSachDichVu() {
    NodeDichVu* p;
    while (head) {
        p = head;
        head = head->next;
        delete p->data;
        delete p;
    }
}

void DanhSachDichVu::them() {
    DatDichVu* dv = new DatDichVu;
    dv->nhap();
    dv->tinh_tong_tien();

    NodeDichVu* node = new NodeDichVu;
    node->data = dv;
    node->next = nullptr;

    if (!head) head = node;
    else {
        NodeDichVu* p = head;
        while (p->next) p = p->next;
        p->next = node;
    }
}

void DanhSachDichVu::hien_thi() {
    if (!head) {
        cout << "Danh sach dich vu rong!\n";
        return;
    }

    cout << "+------------+---------------+---------------+---------------+---------------+---------------+\n";
    cout << "| Ma DV      | Ma Khach Hang | Ma Nhan Vien  | Ma Phuong Tien| Ma Dia Danh   | Ma Luu Tru    |\n";
    cout << "+------------+---------------+---------------+---------------+---------------+---------------+\n";

    NodeDichVu* p = head;
    while (p) {
        cout << "| " << left << setw(11) << p->data->get_ma_dich_vu()
            << "| " << left << setw(14) << (p->data->get_khach_hang() ? p->data->get_khach_hang()->get_ma_khach_hang() : "")
            << "| " << left << setw(14) << (p->data->get_nhan_vien_hd() ? to_string(p->data->get_nhan_vien_hd()->get_ma_nhan_vien()) : "")
            << "| " << left << setw(14) << (p->data->get_phuong_tien() ? p->data->get_phuong_tien()->get_ma_phuong_tien() : "")
            << "| " << left << setw(14) << (p->data->get_dia_danh() ? p->data->get_dia_danh()->get_ma_dia_danh() : "")
            << "| " << left << setw(14) << (p->data->get_luu_tru() ? p->data->get_luu_tru()->get_ma_luu_tru() : "")
            << "|\n";

        cout << "+------------+---------------+---------------+---------------+---------------+---------------+\n";
        p = p->next;
    }
}



DatDichVu* DanhSachDichVu::tim_kiem(string ma) {
    NodeDichVu* p = head;
    while (p) {
        if (p->data->get_ma_dich_vu() == ma) return p->data;
        p = p->next;
    }
    return nullptr;
}

void DanhSachDichVu::doc_file(DanhSachKhachHang& dsKH,
    DanhSachNhanVien& dsNV,
    DanhSachPhuongTien& dsPT,
    DanhSachDiaDanh& dsDD,
    DanhSachLuuTru& dsLT,
    DanhSachThanhToan& dsTT)
{
    ifstream fin("ds_dich_vu.txt");
    if (!fin.is_open()) {
        cout << "Khong mo duoc file ds_dich_vu.txt\n";
        return;
    }

    string line;
    NodeDichVu* tail = nullptr;
    head = nullptr;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string ma, id_kh, id_nv_str, id_pt_str, id_dd_str, id_lt_str;

        getline(ss, ma, ';');
        getline(ss, id_kh, ';');
        getline(ss, id_nv_str, ';');
        getline(ss, id_pt_str, ';');
        getline(ss, id_dd_str, ';');
        getline(ss, id_lt_str, ';');


        int id_nv = stoi(id_nv_str);

        DatDichVu* dv = new DatDichVu;
        dv->set_ma_dich_vu(ma);
        dv->set_khach_hang(dsKH.tim_kiem(id_kh));
        dv->set_nhan_vien_hd(dsNV.tim_kiem(id_nv));
        dv->set_phuong_tien(dsPT.tim_kiem(id_pt_str));
        dv->set_dia_danh(dsDD.tim_kiem(id_dd_str));
        dv->set_luu_tru(dsLT.tim_kiem(id_lt_str));


        dv->tinh_tong_tien();

        NodeDichVu* node = new NodeDichVu;
        node->data = dv;
        node->next = nullptr;

        if (!head) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    fin.close();
}

void DanhSachDichVu::xoa(string ma) {
    if (!head) {
        cout << "Danh sach dich vu trong!\n";
        return;
    }

    NodeDichVu* curr = head;
    NodeDichVu* prev = nullptr;

    while (curr) {
        if (curr->data->get_ma_dich_vu() == ma) {
            if (prev == nullptr) {
                head = curr->next; // xóa đầu
            }
            else {
                prev->next = curr->next;
            }
            delete curr->data;
            delete curr;
            cout << "Da xoa dich vu co ma " << ma << ".\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Khong tim thay dich vu co ma " << ma << ".\n";
}

void DanhSachDichVu::chinh_sua(string ma) {
    DatDichVu* dv = tim_kiem(ma);
    if (!dv) {
        cout << "Khong tim thay dich vu co ma " << ma << ".\n";
        return;
    }

    cout << "Dang chinh sua dich vu co ma " << ma << ":\n";
    dv->nhap();         // gọi lại hàm nhap() để nhập lại toàn bộ thông tin
    dv->tinh_tong_tien(); // cập nhật lại tổng tiền sau khi chỉnh sửa
}

void DanhSachDichVu::cap_nhat(string ma) {
    cout << "Nhap ma dich vu can cap nhat: ";
    getline(cin, ma);

    DatDichVu* dv = tim_kiem(ma); // tìm dịch vụ theo ma
    if (dv) {
        dv->cap_nhat();          // gọi hàm cap_nhat() của DatDichVu
    }
    else {
        cout << "Khong tim thay dich vu co ma " << ma << "!\n";
    }
}

void DanhSachDichVu::hien_thi_menu_dich_vu() {
    int choice;
    this->hien_thi();

    do {
        cout << "\n=============== MENU DICH VU ===============\n";
        cout << "1. Them dich vu moi\n";
        cout << "2. Hien thi danh sach dich vu\n";
        cout << "3. Xoa dich vu theo ma\n";
        cout << "4. Tim dich vu theo ma\n";
        cout << "5. Chinh sua dich vu\n";
        cout << "6. Cap nhat ngay dich vu\n";
        cout << "7. Tinh tong tien dich vu\n";
        cout << "8. Ghi danh sach ra file (dang bao tri)\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            this->them();
            this->hien_thi();
            break;
        case 2:
            this->hien_thi();
            break;
        case 3: {
            string ma;
            cout << "Nhap ma dich vu can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            this->hien_thi();
            break;
        }
        case 4: {
            string ma;
            cout << "Nhap ma dich vu can tim: ";
            getline(cin, ma);
            DatDichVu* dv = this->tim_kiem(ma);
            if (dv)
                dv->hien_thi();
            else
                cout << "Khong tim thay dich vu co ma \"" << ma << "\"!\n";
            break;
        }
        case 5: {
            string ma;
            cout << "Nhap ma dich vu can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }
        case 6: {
            string ma;
            cout << "Nhap ma dich vu can cap nhat ngay: ";
            getline(cin, ma);
            this->cap_nhat(ma);
            this->hien_thi();
            break;
        }
        case 7: {
            string ma;
            cout << "Nhap ma dich vu can tinh tong tien: ";
            getline(cin, ma);
            DatDichVu* dv = this->tim_kiem(ma);
            if (dv) {
                dv->tinh_tong_tien();
                cout << "Tong tien da duoc cap nhat: " << dv->get_tong_tien() << endl;
            }
            else {
                cout << "Khong tim thay dich vu co ma \"" << ma << "\"!\n";
            }
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}
