#include"NhanVien.h"

NhanVien::NhanVien() {
	this->ma_nhan_vien = 0;
	this->luong_co_ban = 0;
	this->he_so_luong = 1;
	this->kinh_nghiem = 0;
	this->luong = 0;
	this->phong_ban = "";
}

NhanVien::~NhanVien() {

}

void NhanVien::set_ma_nhan_vien(int ma_nhan_vien) {
	this->ma_nhan_vien = ma_nhan_vien;
}

void NhanVien::set_phong_ban(const string& phong_ban) {
	this->phong_ban = phong_ban;
}

void NhanVien::set_luong_co_ban(double luong_co_ban) {
	this->luong_co_ban = luong_co_ban; 
}

void NhanVien::set_he_so_luong(float he_so_luong) { 
	this->he_so_luong = he_so_luong; 
}

void NhanVien::set_kinh_nghiem(int kinh_nghiem) { 
	this->kinh_nghiem = kinh_nghiem;
}

int NhanVien::get_ma_nhan_vien() {
	return ma_nhan_vien;
}

string NhanVien::get_phong_ban() { 
	return phong_ban; 
}

double NhanVien::get_luong_co_ban() { 
	return luong_co_ban; 
}

float NhanVien::get_he_so_luong() {
	return he_so_luong; 
}

int NhanVien::get_kinh_nghiem() {
	return kinh_nghiem; 
}

NhanVienChamSoc::NhanVienChamSoc() {
    this->so_khach_phu_trach = 0;
    this->thuong = 0;
    this->ma_nhan_vien = 0;
    this->luong_co_ban = 0;
    this->he_so_luong = 1;
    this->kinh_nghiem = 0;
    this->luong = 0;
    this->phong_ban = "";
}

NhanVienChamSoc::~NhanVienChamSoc() {

}

void NhanVienChamSoc::set_so_khach_phu_trach(int so_khach_phu_trach) {
    this->so_khach_phu_trach = so_khach_phu_trach;
}

void NhanVienChamSoc::set_thuong(double thuong) { 
    this->thuong = thuong;
}

int NhanVienChamSoc::get_so_khach_phu_trach() {
    return so_khach_phu_trach;
}

double NhanVienChamSoc::get_thuong() {
    return thuong; 
}

void NhanVienChamSoc::nhap() {
    cout << "\n=== NHAP THONG TIN NHAN VIEN CHAM SOC ===";

    cout << "\nNhap ma nhan vien: ";
    cin >> ma_nhan_vien;
    cin.ignore();

    cout << "\nNhap ho ten:\n";
    cin >> ten;  

    cout << "\nNhap so dien thoai: ";
    cin >> so_dien_thoai;
    cin.ignore();

    cout << "\nNhap ngay sinh:\n";
    cin >> ngay_sinh; 

    cout << "\nNhap email: ";
    getline(cin, email);

    cout << "\nNhap phong ban: ";
    getline(cin, phong_ban);

    cout << "\nNhap luong co ban: ";
    cin >> luong_co_ban;

    cout << "\nNhap he so luong: ";
    cin >> he_so_luong;

    cout << "\nNhap kinh nghiem (so nam): ";
    cin >> kinh_nghiem;

    cout << "\nNhap so khach phu trach: ";
    cin >> so_khach_phu_trach;

    cout << "\nNhap thuong: ";
    cin >> thuong;

    luong = tinh_luong();

    cout << "\n=== Da nhap thong tin thanh cong! ===\n";
}

void NhanVienChamSoc::hien_thi() {
    cout << "\n=== THONG TIN NHAN VIEN CHAM SOC ==="
        << "\nMa nhan vien: " << ma_nhan_vien
        << "\nHo ten: " << this->ten
        << "\nSo dien thoai: " << so_dien_thoai
        << "\nNgay sinh: " << ngay_sinh
        << "\nEmail: " << email
        << "\nPhong ban: " << phong_ban
        << "\nLuong co ban: " << luong_co_ban
        << "\nHe so luong: " << he_so_luong
        << "\nKinh nghiem: " << kinh_nghiem
        << "\nSo khach phu trach: " << so_khach_phu_trach
        << "\nThuong: " << thuong
        << "\nLuong thuc linh: " << luong
        << "\n";
}

double NhanVienChamSoc::tinh_luong() {
    return luong_co_ban * he_so_luong + thuong;
}

void NhanVienChamSoc::cap_nhat() {
    cout << "Cap nhat thuong moi: ";
    cin >> thuong;
    luong = tinh_luong();
}

void NhanVienChamSoc::chinh_sua() {
    cout << "Chinh sua thong tin nhan vien cham soc: " << endl;
    nhap();
}

HuongDanVien::HuongDanVien() {
    this->ngon_ngu = "";
    this->so_tour_da_dan = 0;
    this->ma_nhan_vien = 0;
    this->luong_co_ban = 0;
    this->he_so_luong = 1;
    this->kinh_nghiem = 0;
    this->luong = 0;
    this->phong_ban = "";
}

HuongDanVien::~HuongDanVien() {

}

void HuongDanVien::set_ngon_ngu(const string& ngon_ngu) {
    this->ngon_ngu = ngon_ngu; 
}

void HuongDanVien::set_so_tour_da_dan(int so_tour_da_dan) {
    this->so_tour_da_dan = so_tour_da_dan;
}

string HuongDanVien::get_ngon_ngu() {
    return ngon_ngu; 
}

int HuongDanVien::get_so_tour_da_dan() { 
    return so_tour_da_dan; 
}

void HuongDanVien::nhap() {
    cout << "\nNhap ma nhan vien: ";
    cin >> ma_nhan_vien;
    cin.ignore();

    cout << "\nNhap ho ten:\n";
    cin >> ten;
    cin.ignore();

    cout << "\nNhap ngay sinh:\n";
    cin >> ngay_sinh;

    cout << "\nNhap so dien thoai: ";
    cin >> so_dien_thoai;
    cin.ignore();

    cout << "\nNhap email: ";
    getline(cin, email);

    cout << "\nNhap phong ban: ";
    getline(cin, phong_ban);

    cout << "\nNhap luong co ban: ";
    cin >> luong_co_ban;

    cout << "\nNhap he so luong: ";
    cin >> he_so_luong;

    cout << "\nNhap ngon ngu huong dan: ";
    cin.ignore();
    getline(cin, ngon_ngu);

    cout << "\nNhap so tour da dan: ";
    cin >> so_tour_da_dan;

    cout << "\nNhap so nam kinh nghiem: ";
    cin >> kinh_nghiem;

    luong = tinh_luong();
    cin.ignore();
}


void HuongDanVien::hien_thi() {
    cout << "\nMa nhan vien: " << ma_nhan_vien
        << "\nHo ten: " << ten
        << "\nNgay sinh: " << ngay_sinh
        << "\nSo dien thoai: " << so_dien_thoai
        << "\nEmail: " << email
        << "\nPhong ban: " << phong_ban
        << "\nLuong co ban: " << luong_co_ban
        << "\nHe so luong: " << he_so_luong
        << "\nNgon ngu huong dan: " << ngon_ngu
        << "\nSo tour da dan: " << so_tour_da_dan
        << "\nKinh nghiem: " << kinh_nghiem
        << "\nLuong thuc linh: " << luong << endl;
}

double HuongDanVien::tinh_luong() {
    return luong_co_ban * he_so_luong + so_tour_da_dan * 200000;
}

void HuongDanVien::cap_nhat() {
    cout << "Nhap so tour da dan moi: ";
    cin >> so_tour_da_dan;
    luong = tinh_luong();
}

void HuongDanVien::chinh_sua() {
    cout << "Chinh sua thong tin huong dan vien: " << endl;
    nhap();
}

DanhSachNhanVien::DanhSachNhanVien() {
    this->head = nullptr;
}

DanhSachNhanVien::~DanhSachNhanVien() { 
    giai_phong(); 
}

void DanhSachNhanVien::them(NhanVien* nv) {
    NodeNhanVien* node = new NodeNhanVien{ nv, nullptr };
    if (!head) head = node;
    else {
        NodeNhanVien* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
}




NhanVien* DanhSachNhanVien::tim_kiem(int ma_nv) {
    NodeNhanVien* temp = head;
    while (temp) {
        if (temp->data->get_ma_nhan_vien() == ma_nv)
            return temp->data;
        temp = temp->next;
    }
    return nullptr;
}

void DanhSachNhanVien::xoa(int ma_nv) {
    NodeNhanVien* temp = head, * prev = nullptr;
    while (temp && temp->data->get_ma_nhan_vien() != ma_nv) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp->data;
    delete temp;
}

void DanhSachNhanVien::chinh_sua(int ma_nv) {
    NhanVien* nv = tim_kiem(ma_nv);
    if (nv) nv->chinh_sua();
    else cout << "Khong tim thay nhan vien!\n";
}

void DanhSachNhanVien::insertion_sort_luong() {
    if (!head || !head->next) return;
    NodeNhanVien* sorted = nullptr;
    NodeNhanVien* current = head;
    while (current) {
        NodeNhanVien* next = current->next;
        if (!sorted || current->data->tinh_luong() < sorted->data->tinh_luong()) {
            current->next = sorted;
            sorted = current;
        }
        else {
            NodeNhanVien* temp = sorted;
            while (temp->next && temp->next->data->tinh_luong() < current->data->tinh_luong())
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

void DanhSachNhanVien::bubble_sort_ten() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        NodeNhanVien* temp = head;
        while (temp->next) {
            string ten1 = temp->data->get_ten().get_ten();
            string ten2 = temp->next->data->get_ten().get_ten();
            if (ten1 > ten2) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void DanhSachNhanVien::hien_thi() {
    if (!head) {
        cout << "Danh sach nhan vien rong.\n";
        return;
    }

    cout << "+------------+-------------------------------+---------------+---------------+---------------+---------------+---------------+\n";
    cout << "| Ma NV      | Ho ten                        | Phong ban     | Luong co ban  | He so luong   | Thuong        | Luong thuc te |\n";
    cout << "+------------+-------------------------------+---------------+---------------+---------------+---------------+---------------+\n";

    NodeNhanVien* temp = head;
    while (temp) {
        NhanVien* nv = temp->data;

        double thuong = 0;
        // Nếu là nhân viên chăm sóc, lấy thuong
        if (auto cs = dynamic_cast<NhanVienChamSoc*>(nv)) {
            thuong = cs->get_thuong();
        }
        // Nếu là HDV, bạn có thể để thuong = 0 hoặc tính theo nhu cầu
        else if (auto hdv = dynamic_cast<HuongDanVien*>(nv)) {
            thuong = 0;
        }

        cout << "| " << left << setw(10) << nv->get_ma_nhan_vien()
            << " | " << left << setw(29) << nv->get_ten().get_ho_ten()
            << " | " << left << setw(13) << nv->get_phong_ban()
            << " | " << right << setw(13) << fixed << setprecision(0) << nv->get_luong_co_ban()
            << " | " << right << setw(13) << nv->get_he_so_luong()
            << " | " << right << setw(13) << fixed << setprecision(0) << thuong
            << " | " << right << setw(13) << fixed << setprecision(0) << nv->tinh_luong()
            << " |\n";

        temp = temp->next;
    }

    cout << "+------------+-------------------------------+---------------+---------------+---------------+---------------+---------------+\n";
}
void DanhSachNhanVien::doc_file() {
    ifstream file("ds_nhan_vien.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    giai_phong(); // xoá danh sách cũ

    string line, loai;
    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == "ChamSoc" || line == "HuongDan") {
            loai = line;
            continue;
        }

        if (loai == "ChamSoc") {
            NhanVienChamSoc* nv = new NhanVienChamSoc();
            nv->doc_file(line);
            them(nv);
        }
        else if (loai == "HuongDan") {
            HuongDanVien* nv = new HuongDanVien();
            nv->doc_file(line);
            them(nv);
        }
    }
}

void NhanVienChamSoc::doc_file(string line) {
    stringstream ss(line);
    string temp, full_name, ngay;

    getline(ss, temp, ';'); ma_nhan_vien = stoi(temp);
    getline(ss, full_name, ';'); ten.set_hoten(full_name);
    getline(ss, phong_ban, ';');
    getline(ss, temp, ';'); so_dien_thoai = stoi(temp);
    getline(ss, ngay, ';'); ngay_sinh.phan_tich_chuoi_ngay(ngay);
    getline(ss, email, ';');
    getline(ss, temp, ';'); luong_co_ban = stod(temp);
    getline(ss, temp, ';'); he_so_luong = stof(temp);
    getline(ss, temp, ';'); kinh_nghiem = stoi(temp);
    getline(ss, temp, ';'); so_khach_phu_trach = stoi(temp);
    getline(ss, temp, ';'); thuong = stod(temp);

    luong = tinh_luong();
}

void HuongDanVien::doc_file(string line) {
    stringstream ss(line);
    string temp, full_name, ngay;

    getline(ss, temp, ';'); ma_nhan_vien = stoi(temp);
    getline(ss, full_name, ';'); ten.set_hoten(full_name);
    getline(ss, phong_ban, ';');
    getline(ss, temp, ';'); so_dien_thoai = stoi(temp);
    getline(ss, ngay, ';'); ngay_sinh.phan_tich_chuoi_ngay(ngay);
    getline(ss, email, ';');
    getline(ss, temp, ';'); luong_co_ban = stod(temp);
    getline(ss, temp, ';'); he_so_luong = stof(temp);
    getline(ss, temp, ';'); kinh_nghiem = stoi(temp);
    getline(ss, ngon_ngu, ';');
    getline(ss, temp, ';'); so_tour_da_dan = stoi(temp);

    luong = tinh_luong();
}
void DanhSachNhanVien::giai_phong() {
    while (head) {
        NodeNhanVien* temp = head;
        head = head->next;
        delete temp->data;  // xóa đối tượng NhanVien
        delete temp;        // xóa node
    }
}

void DanhSachNhanVien::hien_thi_menu_nhan_vien() {

    int choice;
    this->hien_thi();

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Them nhan vien moi";
        cout << "\n2. Hien thi danh sach";
        cout << "\n3. Xoa nhan vien theo ma";
        cout << "\n4. Tim nhan vien theo ma";
        cout << "\n5. Chinh sua nhan vien";
        cout << "\n6. Sap xep theo ten";
        cout << "\n7. Sap xep theo luong";
        cout << "\n8. Ghi danh sach ra file (dang bao tri)";
        cout << "\n0. Thoat";
        cout << "\n==============================";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: { 
            int loai;
            cout << "Chon loai nhan vien (1. Cham soc, 2. Huong dan): ";
            cin >> loai;
            cin.ignore();

            if (loai == 1) {
                NhanVienChamSoc* nv = new NhanVienChamSoc();
                nv->nhap();
                this->them(nv);
            }
            else if (loai == 2) {
                HuongDanVien* hdv = new HuongDanVien();
                hdv->nhap();
                this->them(hdv);
            }
            else {
                cout << "Loai nhan vien khong hop le!\n";
            }
            break;
        }

        case 2:
            this->hien_thi();
            break;

        case 3: {
            int ma;
            cout << "Nhap ma nhan vien can xoa: ";
            cin >> ma;
            this->xoa(ma);
            this->hien_thi();
            break;
        }

        case 4: {
            int ma;
            cout << "Nhap ma nhan vien can tim: ";
            cin >> ma;
            NhanVien* nv = this->tim_kiem(ma);
            if (nv) nv->hien_thi();
            else cout << "Khong tim thay!\n";
            break;
        }

        case 5: {
            int ma;
            cout << "Nhap ma nhan vien can chinh sua: ";
            cin >> ma;
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }

        case 6:
            this->bubble_sort_ten();
            cout << "Da sap xep theo ten!\n";
            this->hien_thi();
            break;

        case 7:
            this->insertion_sort_luong();
            cout << "Da sap xep theo luong!\n";
            this->hien_thi();
            break;

        case 0:
            cout << "Thoat chuong trinh.\n";
            this->giai_phong();
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);


}
