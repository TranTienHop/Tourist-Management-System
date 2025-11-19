#include"KhachHang.h"

Nguoi::Nguoi() {
    this->so_dien_thoai = "";
    this->email = "";
}

Nguoi::~Nguoi() {

}

bool Nguoi::kiemTraSDT(const string& sdt) {
	if (sdt.length() != 10) return false;
    if (sdt[0] != '0') return false;

    for (char c : sdt) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool Nguoi::kiemTraEmail(const string& email) {
	if (email.empty()) return false;
    if (email.find(' ') != string::npos) return false;

    size_t at = email.find('@');
    size_t dot = email.find('.', at + 1);

    return (at != string::npos && dot != string::npos && dot > at + 1);
}

void Nguoi::set_ten(const Name& ten) {
    this->ten = ten;
}

void Nguoi::set_so_dien_thoai(string so_dien_thoai) {
    this->so_dien_thoai = so_dien_thoai;
}

void Nguoi::set_ngay_sinh(const Date& ngay_sinh) {
    this->ngay_sinh = ngay_sinh;
}

void Nguoi::set_email(const string& email) {
    this->email = email;
}

Name Nguoi::get_ten() {
    return ten;
}

string Nguoi::get_so_dien_thoai() {
    return so_dien_thoai;
}

Date Nguoi::get_ngay_sinh() {
    return ngay_sinh;
}

string Nguoi::get_email() {
    return email;
}

KhachHang::KhachHang() {
    this->ma_khach_hang = "";
    this->so_nguoi = 0;
    this->tong_chi_tieu = 0;
}

KhachHang::~KhachHang() {
}

void KhachHang::set_ma_khach_hang(const string& ma_khach_hang) {
    this->ma_khach_hang = ma_khach_hang;
}

void KhachHang::set_so_nguoi(int so_nguoi) {
    this->so_nguoi = so_nguoi; 
}

void KhachHang::set_tong_chi_tieu(double tong_chi_tieu) { 
    this->tong_chi_tieu = tong_chi_tieu; 
}

string KhachHang::get_ma_khach_hang() {
    return this->ma_khach_hang; 
}

int KhachHang::get_so_nguoi() {
    return this->so_nguoi; 
}

double KhachHang::get_tong_chi_tieu() {
    return this->tong_chi_tieu; 
}

void KhachHang::nhap() {
    cout << "\n=== Nhap thong tin khach hang ===\n";
    cout << "Nhap ma khach hang: ";
    getline(cin, this->ma_khach_hang);

    cout << "Nhap ho ten:\n";
    cin >> this->ten;

    do {
        cout << "Nhap so dien thoai: ";
        cin >> this->so_dien_thoai;

        if (!kiemTraSDT(this->so_dien_thoai)) {
            cout << "So dien thoai phai du 10 so va bat dau bang chu so 0! Moi nhap lai.\n";
        }
    } while (!kiemTraSDT(this->so_dien_thoai));
    cin.ignore();

    cout << "Nhap ngay sinh:\n";
    cin >> this->ngay_sinh;
    cin.ignore();

    do {
        cout << "Nhap email: ";
        getline(cin, this->email);

        if (!kiemTraEmail(this->email)) {
            cout << "Email khong hop le! (vi du: name@gmail.com)\n";
        }
    } while (!kiemTraEmail(this->email));

    cout << "Nhap so nguoi trong doan: ";
    cin >> this->so_nguoi;

    cout << "Nhap tong chi tieu: ";
    cin >> this->tong_chi_tieu;
    cin.ignore();
}

void KhachHang::hien_thi() {
    cout << "\n=== Thong tin khach hang ===";
    cout << "\nMa KH: " << this->ma_khach_hang;
    cout << "\nTen: " << this->ten;
    cout << "\nSo dien thoai: " << this->so_dien_thoai;
    cout << "\nNgay sinh: " << this->ngay_sinh;
    cout << "\nEmail: " << this->email;
    cout << "\nSo nguoi: " << this->so_nguoi;
    cout << "\nTong chi tieu: " << this->tong_chi_tieu << " VND" << endl;
}

void KhachHang::cap_nhat() {
    cout << "\nCap nhat so dien thoai cho khach hang co ma " << this->ma_khach_hang << ":\n";
    cout << "So dien thoai cu: " << this->so_dien_thoai << endl;
    string new_sdt;
    do {
        cout << "Nhap so dien thoai moi: ";
        cin >> new_sdt;

        if (!kiemTraSDT(new_sdt)) {
            cout << "So dien thoai khong hop le!\n";
        }
    } while (!kiemTraSDT(new_sdt));

    this->so_dien_thoai = new_sdt;
}

void KhachHang::chinh_sua() {
    cout << "\n=== Chinh sua thong tin khach hang (ma: " << this->ma_khach_hang << ") ===\n";
    this->nhap();
}


DanhSachKhachHang::DanhSachKhachHang() {
    this->head = nullptr;
}

DanhSachKhachHang::~DanhSachKhachHang() {
    this->giai_phong();
}

void DanhSachKhachHang::giai_phong() {
    NodeKhachHang* temp;
    while (this->head != nullptr) {
        temp = this->head;
        this->head = this->head->next;
        delete temp->data;
        delete temp;
    }
}


void DanhSachKhachHang::them(KhachHang* kh) {
    NodeKhachHang* node = new NodeKhachHang(kh);
    if (this->head == nullptr) {
        this->head = node;
    }
    else {
        NodeKhachHang* temp = this->head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = node;
    }
}

KhachHang* DanhSachKhachHang::tim_kiem(const string& ma) {
    NodeKhachHang* temp = this->head;
    while (temp != nullptr) {
        if (temp->data->get_ma_khach_hang() == ma)
            return temp->data;
        temp = temp->next;
    }
    return nullptr;
}

void DanhSachKhachHang::xoa(const string& ma) {
    if (this->head == nullptr) return;

    if (this->head->data->get_ma_khach_hang() == ma) {
        NodeKhachHang* del = this->head;
        this->head = this->head->next;
        delete del->data;
        delete del;
        return;
    }

    NodeKhachHang* temp = this->head;
    while (temp->next != nullptr && temp->next->data->get_ma_khach_hang() != ma)
        temp = temp->next;

    if (temp->next != nullptr) {
        NodeKhachHang* del = temp->next;
        temp->next = del->next;
        delete del->data;
        delete del;
    }
}

void DanhSachKhachHang::chinh_sua(const string& ma) {
    KhachHang* kh = tim_kiem(ma);
    if (kh == nullptr) {
        cout << "Khong tim thay khach hang!\n";
        return;
    }
    kh->chinh_sua();
}

void DanhSachKhachHang::cap_nhat(const string& ma) {
    KhachHang* kh = tim_kiem(ma);
    if (kh == nullptr) {
        cout << "Khong tim thay khach hang!\n";
        return;
    }
    kh->cap_nhat();
}

void DanhSachKhachHang::doc_file() {
    string filename = "ds_khach_hang.txt"; 
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    giai_phong();

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string temp, hoten, str_ngay, sdt, email;
        KhachHang* kh = new KhachHang();

        getline(ss, temp, ';');
        kh->set_ma_khach_hang(temp);

        getline(ss, hoten, ';');
        Name n;
        n.set_hoten(hoten);
        kh->set_ten(n);

        getline(ss, sdt, ';');
        kh->set_so_dien_thoai(sdt);

        getline(ss, email, ';');
        kh->set_email(email);

        getline(ss, str_ngay, ';');
        Date d;
        d.phan_tich_chuoi_ngay(str_ngay);
        kh->set_ngay_sinh(d);

        getline(ss, temp, ';');
        kh->set_so_nguoi(stoi(temp));

        getline(ss, temp, ';');
        kh->set_tong_chi_tieu(stod(temp));

        this->them(kh);
    }

    file.close();
}

void DanhSachKhachHang::hien_thi() {
    if (!this->head) {
        cout << "Danh sach khach hang rong.\n";
        return;
    }

    cout << "+------------+-------------------------------+---------------+----------------------+---------------+---------------+---------------+\n";
    cout << "| Ma KH      | Ho ten                        | So dien thoai | Email                | Ngay sinh     | So nguoi      | Tong chi tieu |\n";
    cout << "+------------+-------------------------------+---------------+----------------------+---------------+---------------+---------------+\n";

    NodeKhachHang* temp = this->head;
    while (temp) {
        KhachHang* kh = temp->data;

        cout << "| " << left << setw(10) << kh->get_ma_khach_hang()
            << " | " << left << setw(29) << kh->get_ten().get_ho_ten()
            << " | " << left << setw(13) << kh->get_so_dien_thoai()
            << " | " << left << setw(20) << kh->get_email()
            << " | " << right << setw(13) << kh->get_ngay_sinh().chuoi_ngay_thang_nam()
            << " | " << right << setw(13) << kh->get_so_nguoi()
            << " | " << right << setw(13) << fixed << setprecision(0) << kh->get_tong_chi_tieu()
            << " |\n";

        temp = temp->next;
    }

    cout << "+------------+-------------------------------+---------------+----------------------+---------------+---------------+---------------+\n";
}


NodeKhachHang* DanhSachKhachHang::chia_doi(NodeKhachHang* head) {
    NodeKhachHang* nhanh = head->next;
    NodeKhachHang* cham = head;

    while (nhanh && nhanh->next) {
        cham = cham->next;
        nhanh = nhanh->next->next;
    }

    NodeKhachHang* mid = cham->next;
    cham->next = nullptr;
    return mid;
}

// Hàm trộn 2 danh sách đã sắp xếp
NodeKhachHang* DanhSachKhachHang::tron(NodeKhachHang* a, NodeKhachHang* b) {
    if (!a) return b;
    if (!b) return a;

    NodeKhachHang* result = nullptr;

    if (a->data->get_tong_chi_tieu() < b->data->get_tong_chi_tieu()) {
        result = a;
        result->next = tron(a->next, b);
    }
    else {
        result = b;
        result->next = tron(a, b->next);
    }
    return result;
}

// Merge Sort chính
NodeKhachHang* DanhSachKhachHang::merge_sort(NodeKhachHang* head) {
    if (!head || !head->next)
        return head;

    NodeKhachHang* mid = chia_doi(head);
    NodeKhachHang* left = merge_sort(head);
    NodeKhachHang* right = merge_sort(mid);

    return tron(left, right);
}

void DanhSachKhachHang::merge_sort_chi_tieu() {
    this->head = merge_sort(this->head);
    cout << "\nDanh sach da duoc sap xep theo tong chi tieu tang dan.\n";
}
// =================== BUBBLE SORT THEO TÊN ===================
void DanhSachKhachHang::bubble_sort_ten() {
    if (!this->head || !this->head->next) return;

    bool swapped;
    do {
        swapped = false;
        NodeKhachHang* current = this->head;

        while (current->next != nullptr) {
            string ten1 = current->data->get_ten().get_ten();
            string ten2 = current->next->data->get_ten().get_ten();

            if (ten1 > ten2) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "\nDanh sach da duoc sap xep theo ten (A–Z).\n";
}
void DanhSachKhachHang::hien_thi_menu_khach_hang() {
    this->hien_thi();
    int choice;
    do {
        cout << "\n==============================";
        cout << "\n1. Them khach hang moi";
        cout << "\n2. Hien thi danh sach khach hang";
        cout << "\n3. Tim khach hang theo ma";
        cout << "\n4. Xoa khach hang theo ma";
        cout << "\n5. Chinh sua thong tin khach hang";
        cout << "\n6. Sap xep theo tong chi tieu";
        cout << "\n7. Sap xep theo ten";
        cout << "\n8. Ghi danh sach ra file (dang bao tri)";
        cout << "\n0. Thoat";
        cout << "\n==============================";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            KhachHang* kh = new KhachHang();
            kh->nhap();
            this->them(kh);
            this->hien_thi();
            break;
        }
        case 2:
            this->hien_thi();
            break;
        case 3: {
            string ma;
            cout << "Nhap ma khach hang can tim: ";
            getline(cin, ma);
            KhachHang* kq = this->tim_kiem(ma);
            if (kq) kq->hien_thi();
            else cout << "Khong tim thay!\n";
            break;
        }
        case 4: {
            string ma;
            cout << "Nhap ma khach hang can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            this->hien_thi();
            break;
        }
        case 5: {
            string ma;
            cout << "Nhap ma khach hang can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }
        case 6:
            this->merge_sort_chi_tieu();
            cout << "Da sap xep theo tong chi tieu!\n";
            this->hien_thi();
            break;
        case 7:
            this->bubble_sort_ten();
            cout << "Da sap xep theo ten!\n";
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
