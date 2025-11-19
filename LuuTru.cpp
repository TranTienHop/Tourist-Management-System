#include "LuuTru.h"

LuuTru::LuuTru() {
    this->ma_luu_tru = "";
    this->ten_luu_tru = "";
    this->so_dien_thoai = "";
    this->gia = 0;
    this->trang_thai = CON_TRONG;
}

LuuTru::~LuuTru() {

}

void LuuTru::set_ma_luu_tru(string ma) { 
    this->ma_luu_tru = ma;
}

string LuuTru::get_ma_luu_tru() {
    return this->ma_luu_tru; 
}

void LuuTru::set_ten_luu_tru(string ten) {
    this->ten_luu_tru = ten;
}

string LuuTru::get_ten_luu_tru() { 
    return this->ten_luu_tru;
}

void LuuTru::set_dia_chi(DiaChi dia_chi) { 
    this->dia_chi = dia_chi;
}

void LuuTru::set_so_dien_thoai(string so_dien_thoai) {
    this->so_dien_thoai = so_dien_thoai; 
}

void LuuTru::set_gia(double gia) {
    this->gia = gia; 
}

void LuuTru::set_trang_thai(TrangThai trang_thai) {
    this->trang_thai = trang_thai; 
}

DiaChi LuuTru::get_dia_chi() {
    return this->dia_chi;
}

string LuuTru::get_so_dien_thoai() { 
    return this->so_dien_thoai; 
}

double LuuTru::get_gia() { 
    return this->gia;
}

TrangThai LuuTru::get_trang_thai() {
    return this->trang_thai;
}

//------------------ KhachSan ------------------

KhachSan::KhachSan() : LuuTru() {
    this->sao = 0;
    this->tong_so_phong = 0;
}

KhachSan::~KhachSan() {

}

void KhachSan::set_sao(int sao) {
    this->sao = sao; 
}

void KhachSan::set_tong_so_phong(int tong_so_phong) {
    this->tong_so_phong = tong_so_phong; 
}

int KhachSan::get_sao() {
    return this->sao; 
}

int KhachSan::get_tong_so_phong() {
    return this->tong_so_phong;
}

void KhachSan::nhap() {
    cout << "Nhap ma khach san: "; cin >> this->ma_luu_tru;
    cin.ignore();
    cout << "Nhap ten khach san: "; getline(cin, this->ten_luu_tru);
    cout << "Nhap dia chi khach san: "; cin >> this->dia_chi;
    do {
        cout << "Nhap so dien thoai: ";
        getline(cin, this->so_dien_thoai);

        if (!input_validator::kiemTraSDT(this->so_dien_thoai)) {
            cout << "So dien thoai phai du 10 so va bat dau bang chu so 0! Moi nhap lai.\n";
        }
    } while (!input_validator::kiemTraSDT(this->so_dien_thoai));
    cin.ignore();
    cout << "Nhap gia: "; cin >> this->gia;
    cout << "Nhap so sao: "; cin >> this->sao;
    cout << "Nhap tong so phong: "; cin >> this->tong_so_phong;
    this->trang_thai = CON_TRONG;
}

void KhachSan::hien_thi() {
    cout << "\nMa khach san: " << this->ma_luu_tru;
    cout << "\nTen khach san: " << this->ten_luu_tru;
    cout << "\nDia chi:\n " << this->dia_chi;
    cout << "\nSo dien thoai: " << this->so_dien_thoai;
    cout << "\nGia: " << this->gia;
    cout << "\nSo sao: " << this->sao;
    cout << "\nTong so phong: " << this->tong_so_phong;
    cout << "\nTrang thai: " << this->trang_thai << "\n";
}

void KhachSan::cap_nhat() {
    cin.ignore();
    cout << "Nhap ten moi: "; getline(cin, this->ten_luu_tru);
    do {
        cout << "Nhap so dien thoai moi: ";
        getline(cin, this->so_dien_thoai);

        if (!input_validator::kiemTraSDT(this->so_dien_thoai)) {
            cout << "So dien thoai phai du 10 so va bat dau bang chu so 0! Moi nhap lai.\n";
        }
    } while (!input_validator::kiemTraSDT(this->so_dien_thoai));
    cin.ignore();
    cout << "Nhap gia moi: "; cin >> this->gia;
    cout << "Nhap so sao moi: "; cin >> this->sao;
}

void KhachSan::sua() {
    cout << "\n--- Sua thong tin khach san ---\n";
    this->nhap(); 
}

void KhachSan::dat_phong() {
    if (this->trang_thai == CON_TRONG) {
        this->trang_thai = DA_DAT;
        cout << "Dat phong thanh cong!\n";
    }
    else if (this->trang_thai == DA_DAT) {
        cout << "Phong da duoc dat!\n";
    }
    else {
        cout << "Phong dang bao tri, khong the dat!\n";
    }
}

void KhachSan::kt_trang_thai() {
    cout << "Trang thai hien_thi tai: " << this->trang_thai << endl;
}

void KhachSan::cap_nhat_trang_thai() {
    int tt;
    cout << "Nhap trang thai moi (0-TRONG,1-DAT,2-BAO_TRI): ";
    cin >> tt;
    this->trang_thai = static_cast<TrangThai>(tt);
}


NhaNghi::NhaNghi() : LuuTru() {
    this->gio_hoat_dong = "";
    this->so_xe = 0;
    this->tinh_trang_xe = CON_TRONG;
}

NhaNghi::~NhaNghi() {

}

void NhaNghi::set_gio_hoat_dong(string gio) {
    this->gio_hoat_dong = gio;
}

void NhaNghi::set_so_xe(int so_xe) {
    this->so_xe = so_xe;
}

void NhaNghi::set_tinh_trang_xe(TrangThai trang_thai) { 
    this->tinh_trang_xe = trang_thai;
}

string NhaNghi::get_gio_hoat_dong() {
    return this->gio_hoat_dong; 
}

int NhaNghi::get_so_xe() { 
    return this->so_xe; 
}

TrangThai NhaNghi::get_tinh_trang_xe() { 
    return this->tinh_trang_xe; 
}


void NhaNghi::nhap() {
    cout << "Nhap ma nha nghi: "; cin >> this->ma_luu_tru;
    cin.ignore();
    cout << "Nhap ten nha nghi: "; getline(cin, this->ten_luu_tru);
    cout << "Nhap dia chi nha nghi:\n "; cin >> this->dia_chi;
    do {
        cout << "Nhap so dien thoai: ";
        getline(cin, this->so_dien_thoai);

        if (!input_validator::kiemTraSDT(this->so_dien_thoai)) {
            cout << "So dien thoai phai du 10 so va bat dau bang chu so 0! Moi nhap lai.\n";
        }
    } while (!input_validator::kiemTraSDT(this->so_dien_thoai));
    cin.ignore();
    cout << "Nhap gia: "; cin >> this->gia;
    cin.ignore();
    cout << "Nhap gio hoat dong: "; getline(cin, this->gio_hoat_dong);
    cout << "Nhap so xe: "; cin >> this->so_xe;
    cin.ignore();
    int tt;
    cout << "Nhap tinh trang xe (0-CON_TRONG,1-DA_DAT,2-DANG_BAO_TRI): ";
    cin >> tt;
    this->tinh_trang_xe = static_cast<TrangThai>(tt);
    this->trang_thai = CON_TRONG; 
}

void NhaNghi::hien_thi() {
    cout << "\nMa nha nghi: " << this->ma_luu_tru;
    cout << "\nTen nha nghi: " << this->ten_luu_tru;
    cout << "\nDia chi: " << this->dia_chi;
    cout << "\nSo dien thoai: " << this->so_dien_thoai;
    cout << "\nGia: " << this->gia;
    cout << "\nGio hoat dong: " << this->gio_hoat_dong;
    cout << "\nSo xe: " << this->so_xe;

    cout << "\nTinh trang xe: ";
    switch (this->tinh_trang_xe) {
    case CON_TRONG: cout << "CON_TRONG"; break;
    case DA_DAT: cout << "DA_DAT"; break;
    case DANG_BAO_TRI: cout << "DANG_BAO_TRI"; break;
    }

    cout << "\nTrang thai chung: ";
    switch (this->trang_thai) {
    case CON_TRONG: cout << "CON_TRONG"; break;
    case DA_DAT: cout << "DA_DAT"; break;
    case DANG_BAO_TRI: cout << "DANG_BAO_TRI"; break;
    }
    cout << "\n";
}


void NhaNghi::cap_nhat() {
    cin.ignore();
    cout << "Nhap ten moi: "; getline(cin, this->ten_luu_tru);
    do {
        cout << "Nhap so dien thoai moi: ";
        getline(cin, this->so_dien_thoai);

        if (!input_validator::kiemTraSDT(this->so_dien_thoai)) {
            cout << "So dien thoai phai du 10 so va bat dau bang chu so 0! Moi nhap lai.\n";
        }
    } while (!input_validator::kiemTraSDT(this->so_dien_thoai));
    cin.ignore();
    cout << "Nhap gia moi: "; cin >> this->gia;
    cin.ignore();
    cout << "Nhap gio hoat dong moi: "; getline(cin, this->gio_hoat_dong);
    cout << "Nhap so xe moi: "; cin >> this->so_xe;
    cin.ignore();
    int tt;
    cout << "Nhap tinh trang xe moi (0-CON_TRONG,1-DA_DAT,2-DANG_BAO_TRI): ";
    cin >> tt;
    this->tinh_trang_xe = static_cast<TrangThai>(tt);
}

void NhaNghi::sua() {
    cout << "\n--- Sua thong tin nha nghi ---\n";
    this->nhap();
}

void NhaNghi::dat_phong() {
    if (this->trang_thai == CON_TRONG) {
        this->trang_thai = DA_DAT;
        cout << "Dat phong thanh cong!\n";
    }
    else if (this->trang_thai == DA_DAT) {
        cout << "Phong da duoc dat!\n";
    }
    else {
        cout << "Phong dang bao tri, khong the dat!\n";
    }
}

void NhaNghi::dat_xe() {
    if (this->tinh_trang_xe == CON_TRONG) {
        this->tinh_trang_xe = DA_DAT;
        cout << "Dat xe thanh cong!\n";
    }
    else {
        cout << "Xe khong the dat!\n";
    }
}

void NhaNghi::kt_trang_thai() {
    cout << "Tinh trang xe hien_thi tai: ";
    switch (this->tinh_trang_xe) {
    case CON_TRONG: cout << "CON_TRONG"; break;
    case DA_DAT: cout << "DA_DAT"; break;
    case DANG_BAO_TRI: cout << "DANG_BAO_TRI"; break;
    }
    cout << "\n";
}


void NhaNghi::cap_nhat_trang_thai() {
    int tt;
    cout << "Nhap trang thai moi (0-TRONG,1-DAT,2-BAO_TRI): ";
    cin >> tt;
    this->trang_thai = static_cast<TrangThai>(tt);
}

//------------------ DANH SACH LUU TRU ------------------

DanhSachLuuTru::DanhSachLuuTru() : head(nullptr) {

}

DanhSachLuuTru::~DanhSachLuuTru() {
    NodeLuuTru* tmp = head;
    while (tmp) {
        NodeLuuTru* del = tmp;
        tmp = tmp->next;
        delete del->luu_tru;
        delete del;
    }
}

void DanhSachLuuTru::them(LuuTru* luu_tru) {
    NodeLuuTru* node = new NodeLuuTru(luu_tru);
    if (!head) head = node;
    else {
        NodeLuuTru* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }
}

void DanhSachLuuTru::xoa(string ma_luu_tru) {
    NodeLuuTru* tmp = head;
    NodeLuuTru* prev = nullptr;
    while (tmp && tmp->luu_tru->get_ma_luu_tru() != ma_luu_tru) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp) {
        cout << "Khong tim thay luu tru de xoa.\n";
        return;
    }
    if (!prev) head = tmp->next;
    else prev->next = tmp->next;
    delete tmp->luu_tru;
    delete tmp;
    cout << "Da xoa luu tru.\n";
}

void DanhSachLuuTru::chinh_sua(string ma_luu_tru) {
    LuuTru* lt = tim_kiem(ma_luu_tru);
    if (lt) lt->sua();
    else cout << "Khong tim thay luu tru de chinh sua.\n";
}

LuuTru* DanhSachLuuTru::tim_kiem(string ma_luu_tru) {
    NodeLuuTru* tmp = head;
    while (tmp) {
        if (tmp->luu_tru->get_ma_luu_tru() == ma_luu_tru)
            return tmp->luu_tru;
        tmp = tmp->next;
    }
    return nullptr;
}

void DanhSachLuuTru::insertion_sort_theo_gia() {
    if (!head || !head->next) return;
    NodeLuuTru* sorted = nullptr;
    NodeLuuTru* current = head;
    while (current) {
        NodeLuuTru* next = current->next;
        if (!sorted || current->luu_tru->get_gia() < sorted->luu_tru->get_gia()) {
            current->next = sorted;
            sorted = current;
        }
        else {
            NodeLuuTru* tmp = sorted;
            while (tmp->next && tmp->next->luu_tru->get_gia() <= current->luu_tru->get_gia())
                tmp = tmp->next;
            current->next = tmp->next;
            tmp->next = current;
        }
        current = next;
    }
    head = sorted;
}

void DanhSachLuuTru::bubble_sort_theo_trang_thai() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        NodeLuuTru* tmp = head;
        while (tmp->next) {
            if (tmp->luu_tru->get_trang_thai() > tmp->next->luu_tru->get_trang_thai()) {
                swap(tmp->luu_tru, tmp->next->luu_tru);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
}
void DanhSachLuuTru::kt_trang_thai_theo_ma(string ma_luu_tru) {
    NodeLuuTru* tmp = head;
    while (tmp) {
        if (tmp->luu_tru->get_ma_luu_tru() == ma_luu_tru) {
            cout << "Trang thai cua \"" << ma_luu_tru << "\": ";
            switch (tmp->luu_tru->get_trang_thai()) {
            case CON_TRONG: cout << "CON_TRONG"; break;
            case DA_DAT: cout << "DA_DAT"; break;
            case DANG_BAO_TRI: cout << "DANG_BAO_TRI"; break;
            }
            cout << "\n";
            return;
        }
        tmp = tmp->next;
    }
    cout << "Khong tim thay ma luu tru: " << ma_luu_tru << "\n";
}
void DanhSachLuuTru::hien_thi() {
    NodeLuuTru* hien_tai = this->head;
    if (hien_tai == nullptr) {
        cout << "Danh sach luu tru rong.\n";
        return;
    }

    cout << "\n+------------+-------------------------------+-------------------------------+---------------+---------------+\n";
    cout << "| Ma LT      | Ten luu tru                   | Dia chi                       | Gia           | Trang thai    |\n";
    cout << "+------------+-------------------------------+-------------------------------+---------------+---------------+\n";

    while (hien_tai != nullptr) {
        LuuTru* lt = hien_tai->luu_tru;

        // Chuyển địa chỉ thành chuỗi
        string dia_chi_str = lt->get_dia_chi().get_so_nha() + " " +
            lt->get_dia_chi().get_ten_duong() + ", " +
            lt->get_dia_chi().get_ten_tinh();

        cout << "| " << left << setw(10) << lt->get_ma_luu_tru()
            << " | " << left << setw(29) << lt->get_ten_luu_tru()
            << " | " << left << setw(29) << dia_chi_str
            << " | " << right << setw(13) << fixed << setprecision(0) << lt->get_gia()
            << " | " << left << setw(13);

        // Hiển thị trạng thái enum thành string
        switch (lt->get_trang_thai()) {
        case CON_TRONG: cout << "CON_TRONG"; break;
        case DA_DAT: cout << "DA_DAT"; break;
        case DANG_BAO_TRI: cout << "DANG_BAO_TRI"; break;
        }

        cout << " |\n";
        cout << "+------------+-------------------------------+-------------------------------+---------------+---------------+\n";

        hien_tai = hien_tai->next;
    }
}

TrangThai chuyen_str_thanh_trang_thai(const string& str) {
    if (str == "CON_TRONG") return CON_TRONG;
    else if (str == "DA_DAT") return DA_DAT;
    else return DANG_BAO_TRI;
}

// -------------------- KhachSan --------------------
void KhachSan::doc_file(string line) {
    stringstream ss(line);
    string so_nha, ten_duong, ten_tinh, temp, tt_str;

    getline(ss, this->ma_luu_tru, ';');
    getline(ss, this->ten_luu_tru, ';');
    getline(ss, so_nha, ';');
    getline(ss, ten_duong, ';');
    getline(ss, ten_tinh, ';');
    DiaChi dc;
    dc.set_so_nha(so_nha);
    dc.set_ten_duong(ten_duong);
    dc.set_ten_tinh(ten_tinh);
    this->dia_chi = dc;

    getline(ss, this->so_dien_thoai, ';');

    getline(ss, temp, ';');
    this->gia = stod(temp);

    getline(ss, temp, ';');
    this->sao = stoi(temp);

    getline(ss, temp, ';');
    this->tong_so_phong = stoi(temp);

    getline(ss, tt_str, ';');
    this->trang_thai = chuyen_str_thanh_trang_thai(tt_str);
}

// -------------------- NhaNghi --------------------
void NhaNghi::doc_file(string line) {
    stringstream ss(line);
    string so_nha, ten_duong, ten_tinh, temp, tt_str;

    getline(ss, this->ma_luu_tru, ';');
    getline(ss, this->ten_luu_tru, ';');
    getline(ss, so_nha, ';');
    getline(ss, ten_duong, ';');
    getline(ss, ten_tinh, ';');
    DiaChi dc;
    dc.set_so_nha(so_nha);
    dc.set_ten_duong(ten_duong);
    dc.set_ten_tinh(ten_tinh);
    this->dia_chi = dc;

    getline(ss, this->so_dien_thoai, ';');

    getline(ss, temp, ';');
    this->gia = stod(temp);

    getline(ss, this->gio_hoat_dong, ';');

    getline(ss, temp, ';');
    this->so_xe = stoi(temp);

    getline(ss, tt_str, ';');
    this->tinh_trang_xe = chuyen_str_thanh_trang_thai(tt_str);

    this->trang_thai = CON_TRONG; // mặc định khi đọc
}

// -------------------- DanhSachLuuTru --------------------
void DanhSachLuuTru::doc_file() {
    string filename = "ds_luu_tru.txt"; 
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line.find("KS") == 0) { // KhachSan
            KhachSan* ks = new KhachSan();
            ks->doc_file(line);
            this->them(ks);
        }
        else if (line.find("NN") == 0) { 
            NhaNghi* nn = new NhaNghi();
            nn->doc_file(line);
            this->them(nn);
        }
    }

    file.close();
}
void DanhSachLuuTru::hien_thi_menu_luu_tru() {

    int choice;
    this->hien_thi();

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Them luu tru moi";
        cout << "\n2. Hien thi danh sach";
        cout << "\n3. Xoa luu tru theo ma";
        cout << "\n4. Tim luu tru theo ma";
        cout << "\n5. Chinh sua luu tru";
        cout << "\n6. Sap xep theo gia";
        cout << "\n7. Sap xep theo trang thai";
        cout << "\n8. Kiem tra trang thai theo ma";
        cout << "\n9. Ghi danh sach ra file (dang bao tri)";
        cout << "\n0. Thoat";
        cout << "\n==============================";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int loai;
            cout << "Chon loai luu tru (1. Khach San, 2. Nha Nghi):\n ";
            cin >> loai;
            cin.ignore();

            LuuTru* luu_tru = nullptr;
            switch (loai) {
            case 1: luu_tru = new KhachSan(); break;
            case 2: luu_tru = new NhaNghi(); break;
            default:
                cout << "Loai luu tru khong hop le!\n";
                break;
            }

            if (luu_tru) {
                luu_tru->nhap();
                this->them(luu_tru);
            }
            break;
        }

        case 2:
            this->hien_thi();
            break;

        case 3: {
            string ma;
            cout << "Nhap ma luu tru can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            break;
        }

        case 4: {
            string ma;
            cout << "Nhap ma luu tru can tim: ";
            getline(cin, ma);
            LuuTru* lt = this->tim_kiem(ma);
            if (lt) lt->hien_thi();
            else cout << "Khong tim thay luu tru.\n";
            break;
        }

        case 5: {
            string ma;
            cout << "Nhap ma luu tru can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            break;
        }

        case 6:
            this->insertion_sort_theo_gia();
            cout << "Da sap xep theo gia!\n";
            this->hien_thi();
            break;

        case 7:
            this->bubble_sort_theo_trang_thai();
            cout << "Da sap xep theo trang thai!\n";
            this->hien_thi();
            break;

        case 8: {
            string ma;
            cout << "Nhap ma luu tru can kiem tra trang thai: ";
            getline(cin, ma);
            this->kt_trang_thai_theo_ma(ma);
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

