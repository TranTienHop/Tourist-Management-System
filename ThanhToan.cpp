#include "ThanhToan.h"

ThanhToan::ThanhToan() {
    ma_thanh_toan = "";
    ma_dat_dich_vu = "";
    so_tien = 0;
    loai = TIEN_MAT;
    du_lieu.so_tien_mat = 0;
    da_thanh_toan = false;
}

ThanhToan::~ThanhToan() {}

void ThanhToan::gan_ma_thanh_toan(string ma) {
    ma_thanh_toan = ma;
}

void ThanhToan::gan_ma_dat_dich_vu(string ma) {
    ma_dat_dich_vu = ma;
}

void ThanhToan::gan_so_tien(float tien) {
    so_tien = tien;
}

void ThanhToan::gan_loai(LoaiThanhToan l) {
    loai = l;
}

void ThanhToan::gan_du_lieu_tien_mat(double tien) {
    du_lieu.so_tien_mat = tien;
}

void ThanhToan::gan_du_lieu_the(const char* the) {
    strncpy(du_lieu.so_the, the,20);
}

void ThanhToan::gan_du_lieu_vi(const char* vi) {
    strncpy(du_lieu.tai_khoan_vi, vi,20);
}

void ThanhToan::gan_ngay_thanh_toan(Date ngay) {
    ngay_thanh_toan = ngay;
}

void ThanhToan::gan_trang_thai(bool tt) {
    da_thanh_toan = tt;
}

string ThanhToan::lay_ma_thanh_toan() {
    return ma_thanh_toan;
}

string ThanhToan::lay_ma_dat_dich_vu() {
    return ma_dat_dich_vu;
}

float ThanhToan::lay_so_tien() {
    return so_tien;
}

LoaiThanhToan ThanhToan::lay_loai() {
    return loai;
}

DuLieuThanhToan ThanhToan::lay_du_lieu() {
    return du_lieu;
}

Date& ThanhToan::lay_ngay_thanh_toan() {
    return ngay_thanh_toan;
}

bool ThanhToan::lay_trang_thai() {
    return da_thanh_toan;
}

void ThanhToan::nhap() {
    cout << "Nhap ma thanh toan: ";
    getline(cin, ma_thanh_toan);
    cout << "Nhap ma dat dich vu: ";
    getline(cin, ma_dat_dich_vu);
    cout << "Nhap so tien: ";
    cin >> so_tien;
    cout << "Chon loai thanh toan (0: tien mat, 1: the, 2: vi dien tu): ";
    int chon; cin >> chon; loai = (LoaiThanhToan)chon;
    cin.ignore();

    if (loai == TIEN_MAT) {
        cout << "Nhap so tien mat: ";
        cin >> du_lieu.so_tien_mat;
        cin.ignore();
    }
    else if (loai == THE) {
        cout << "Nhap so the: ";
        cin.getline(du_lieu.so_the, 20);
    }
    else {
        cout << "Nhap tai khoan vi: ";
        cin.getline(du_lieu.tai_khoan_vi, 20);
    }

    cout << "Nhap ngay thanh toan:\n";
    cin>>ngay_thanh_toan;

    cout << "Da thanh toan (1-co, 0-khong): ";
    cin >> da_thanh_toan;
    cin.ignore();
}

void ThanhToan::hien_thi() {
    cout << left << setw(15) << ma_thanh_toan
        << setw(15) << ma_dat_dich_vu
        << setw(12) << so_tien
        << setw(15);

    if (loai == TIEN_MAT)
        cout << "Tien mat";
    else if (loai == THE)
        cout << "The";
    else
        cout << "Vi dien tu";

    cout << setw(15);
    if (loai == TIEN_MAT)
        cout << du_lieu.so_tien_mat;
    else if (loai == THE)
        cout << du_lieu.so_the;
    else
        cout << du_lieu.tai_khoan_vi;

    cout << setw(15)<< ngay_thanh_toan;
    cout << setw(10) << (da_thanh_toan ? "Da TT" : "Chua TT") << endl;
}

void ThanhToan::chinh_sua() {
    cout << "Nhap so tien moi: ";
    cin >> so_tien;
    cout << "Nhap trang thai moi (1-co, 0-khong): ";
    cin >> da_thanh_toan;
}

void ThanhToan::cap_nhat() {
    char choice;
    cout << "Da thanh toan? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        da_thanh_toan = true;
    }
    else {
        da_thanh_toan = false;
    }
}

void ThanhToan::ghi_file(ofstream &file) {
	file << ma_thanh_toan << ";"
         << ma_dat_dich_vu << ";"
         << so_tien << ";"
         << loai << ";";
         
    if (loai == TIEN_MAT) {
        file << du_lieu.so_tien_mat << ";";
    }
    else if (loai == THE) {
        file << du_lieu.so_the << ";";
    }
    else { // VI_DIEN_TU
        file << du_lieu.tai_khoan_vi << ";";
    }
    
    file << ngay_thanh_toan.get_ngay() << "/"
         << ngay_thanh_toan.get_thang() << "/"
         << ngay_thanh_toan.get_nam() << ";";
         
    file << da_thanh_toan;
    file << "\n";
}

// ----------------- DANH SÁCH -----------------

DanhSachThanhToan::DanhSachThanhToan() {
    head = nullptr;
}

DanhSachThanhToan::~DanhSachThanhToan() {
    NodeThanhToan* p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}

void DanhSachThanhToan::them() {
    ThanhToan* tt = new ThanhToan;   
    tt->nhap();

    NodeThanhToan* node = new NodeThanhToan{ tt, nullptr };
    if (!head) head = node;
    else {
        NodeThanhToan* p = head;
        while (p->next) p = p->next;
        p->next = node;
    }

}

void DanhSachThanhToan::xoa(string ma) {
    NodeThanhToan* p = head;
    NodeThanhToan* trc = nullptr;

    while (p && p->data->lay_ma_thanh_toan() != ma) {
        trc = p;
        p = p->next;
    }

    if (!p) {
        cout << "Khong tim thay thanh toan!\n";
        return;
    }

    if (!trc) head = p->next;   
    else trc->next = p->next;  

    delete p->data;   
    delete p;         
    cout << "Xoa thanh cong.\n";
}

void DanhSachThanhToan::cap_nhat(string ma) {
    ThanhToan* p = tim_kiem(ma);
    if (p) p->cap_nhat();
}

void DanhSachThanhToan::chinh_sua(string ma) {
    ThanhToan* p = tim_kiem(ma);
    if (p) p->nhap();
}

void DanhSachThanhToan::hien_thi() {
    if (!head) {
        cout << "Danh sach thanh toan rong.\n";
        return;
    }

    cout << "+---------------+---------------+------------+------------+-----------------+------------+\n";
    cout << "| Ma Thanh Toan | Ma Dich vu    | So tien    | Loai       | Ngay Thanh Toan | Tinh Trang |\n";
    cout << "+---------------+---------------+------------+------------+-----------------+------------+\n";

    for (NodeThanhToan* p = head; p; p = p->next) {
        ThanhToan* tt = p->data;

        cout << "| " << left << setw(13) << tt->lay_ma_thanh_toan()
            << " | " << left << setw(13) << tt->lay_ma_dat_dich_vu()
            << " | " << right << setw(10) << fixed << setprecision(0) << tt->lay_so_tien()
            << " | ";

        // Loai thanh toan
        string loaiStr;
        switch (tt->lay_loai()) {
        case TIEN_MAT: loaiStr = "Tien mat"; break;
        case THE: loaiStr = "The"; break;
        case VI_DIEN_TU: loaiStr = "Vi dien tu"; break;
        default: loaiStr = ""; break;
        }
        cout << left << setw(10) << loaiStr << " | ";

        
        // Ngay thanh toan
        Date ngay = tt->lay_ngay_thanh_toan();
        cout << left << setw(10) << (to_string(ngay.get_ngay()) + "/" +
            to_string(ngay.get_thang()) + "/" +
            to_string(ngay.get_nam())) << "      | ";

        // Trang thai
        cout << left << setw(10) << (tt->lay_trang_thai() ? "Da TT" : "Chua TT") << " |\n";

        cout << "+---------------+---------------+------------+------------+-----------------+------------+\n";
    }
}

ThanhToan* DanhSachThanhToan::tim_kiem(string ma) {
    for (NodeThanhToan* p = head; p; p = p->next) {
        if (p->data->lay_ma_thanh_toan() == ma)
            return p->data;
    }
    return nullptr;
}

void DanhSachThanhToan::insertion_sort_ngay() {
    if (!head || !head->next) return;

    NodeThanhToan* sorted = nullptr;
    NodeThanhToan* curr = head;

    while (curr) {
        NodeThanhToan* next = curr->next;

        if (!sorted || curr->data->lay_ngay_thanh_toan() < sorted->data->lay_ngay_thanh_toan()) {
            curr->next = sorted;
            sorted = curr;
        }
        else {
            NodeThanhToan* s = sorted;
            while (s->next && !(curr->data->lay_ngay_thanh_toan() < s->next->data->lay_ngay_thanh_toan()))
                s = s->next;
            curr->next = s->next;
            s->next = curr;
        }

        curr = next;
    }
}

void DanhSachThanhToan::selection_sort_so_tien() {
    for (NodeThanhToan* i = head; i && i->next; i = i->next) {
        NodeThanhToan* min = i;
        for (NodeThanhToan* j = i->next; j; j = j->next)
            if (j->data->lay_so_tien() < min->data->lay_so_tien())
                min = j;
        if (min != i) swap(i->data, min->data); 
    }
}

void DanhSachThanhToan::bubble_sort_loai() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        NodeThanhToan* p = head;
        while (p->next) {
            if (p->data->lay_loai() > p->next->data->lay_loai()) {
                swap(p->data, p->next->data); // swap con trỏ ThanhToan*
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

void DanhSachThanhToan::ghi_file() {
    ofstream file("ds_thanh_toan.txt");

    if (!file.is_open()) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    NodeThanhToan* p = head;
    while (p != nullptr) {
        p->data->ghi_file(file);
        p = p->next;
    }

    file.close();
    cout << "Da ghi file thanh cong!\n";
}

void DanhSachThanhToan::doc_file() {
    ifstream file("ds_thanh_toan.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ThanhToan* tt = new ThanhToan;  // tạo động
        string temp;

        getline(ss, temp, ';'); tt->gan_ma_thanh_toan(temp);
        getline(ss, temp, ';'); tt->gan_ma_dat_dich_vu(temp);
        getline(ss, temp, ';'); tt->gan_so_tien(stof(temp));
        getline(ss, temp, ';'); tt->gan_loai((LoaiThanhToan)stoi(temp));

        getline(ss, temp, ';');
        if (tt->lay_loai() == TIEN_MAT) tt->gan_du_lieu_tien_mat(stod(temp));
        else if (tt->lay_loai() == THE) tt->gan_du_lieu_the(temp.c_str());
        else tt->gan_du_lieu_vi(temp.c_str());

        getline(ss, temp, ';'); tt->lay_ngay_thanh_toan().phan_tich_chuoi_ngay(temp);
        getline(ss, temp, ';'); tt->gan_trang_thai(stoi(temp));

        NodeThanhToan* node = new NodeThanhToan{ tt, nullptr };
        if (!head) head = node;
        else {
            NodeThanhToan* p = head;
            while (p->next) p = p->next;
            p->next = node;
        }
    }

    file.close();
}
void DanhSachThanhToan::hien_thi_menu_thanh_toan() {

    int choice;
    this->hien_thi();

    do {
        cout << "\n=============== MENU ===============\n";
        cout << "1. Them thanh toan moi\n";
        cout << "2. Hien thi danh sach thanh toan\n";
        cout << "3. Xoa thanh toan theo ma\n";
        cout << "4. Tim thanh toan theo ma\n";
        cout << "5. Chinh sua thanh toan\n";
        cout << "6. Cap nhat trang thai\n";
        cout << "7. Sap xep theo ngay thanh toan\n";
        cout << "8. Sap xep theo so tien\n";
        cout << "9. Sap xep theo loai thanh toan\n";
        cout << "10. Ghi danh sach ra file\n";
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
            cout << "Nhap ma thanh toan can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            this->hien_thi();
            break;
        }
        case 4: {
            string ma;
            cout << "Nhap ma thanh toan can tim: ";
            getline(cin, ma);
            ThanhToan* p = this->tim_kiem(ma);
            if (p)
                p->hien_thi();
            else
                cout << "Khong tim thay thanh toan co ma \"" << ma << "\"!\n";
            break;
        }
        case 5: {
            string ma;
            cout << "Nhap ma thanh toan can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }
        case 6: {
            string ma;
            cout << "Nhap ma thanh toan can chinh sua: ";
            getline(cin, ma);
            this->cap_nhat(ma);
            this->hien_thi();
            break;
        }
        case 7:
            this->insertion_sort_ngay();
            cout << "Da sap xep theo ngay thanh toan\n";
            this->hien_thi();
            break;
        case 8:
            this->selection_sort_so_tien();
            cout << "Da sap xep theo so tien\n";
            this->hien_thi();
            break;
        case 9:
            this->bubble_sort_loai();
            cout << "Da sap xep theo loai thanh toan\n";
            this->hien_thi();
            break;
        case 10:
            this->ghi_file();
    	    cout << "Da ghi danh sach ra file thanh cong!\n";
    	    break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);
}


