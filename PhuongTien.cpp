#include "PhuongTien.h"

PhuongTien::PhuongTien() {
    ma_phuong_tien = "";
    ten_phuong_tien = "";
    so_ngay_thue = 0;
    gia_thue = 0;
    diem_den = "";
    trang_thai = CON_TRONG;
}

PhuongTien::~PhuongTien() {
}
void PhuongTien::set_ma_phuong_tien(string ma) {
    ma_phuong_tien = ma; 
}

void PhuongTien::set_ten_phuong_tien(string ten) {
    ten_phuong_tien = ten;
}

void PhuongTien::set_gia_thue(double gia) { 
    gia_thue = gia; 
}

void PhuongTien::set_diem_den(string diem) {
    diem_den = diem;
}

void PhuongTien::set_so_ngay_thue(int so_ngay_thue) {
    this->so_ngay_thue = so_ngay_thue;
}

void PhuongTien::set_trang_thai(TrangThai trang_thai) {
    this->trang_thai = trang_thai;
}

string PhuongTien::get_ma_phuong_tien() {
    return ma_phuong_tien; 
}

string PhuongTien::get_ten_phuong_tien() {
    return ten_phuong_tien;
}

double PhuongTien::get_gia_thue() {
    return gia_thue;
}

string PhuongTien::get_diem_den() {
    return diem_den;
}

int PhuongTien::get_so_ngay_thue() {
    return so_ngay_thue;
}

PhuongTien::TrangThai PhuongTien::get_trang_thai() {
    return trang_thai;
}
string PhuongTien:: trang_thai_to_string() {
    switch (trang_thai) {
    case CON_TRONG: return "Con trong";
    case DA_DAT: return "Da dat";
    case DANG_BAO_TRI: return "Dang bao tri";
    default: return "Khong xac dinh";
    }
}

// ======================== MAY BAY ========================

MayBay::MayBay() {
    this->ma_phuong_tien = "";
    this->ten_phuong_tien = "";
    this->gia_thue = 0;
    this->diem_den = "";
    this->trang_thai = CON_TRONG;
    this->hang_hang_khong = "";
}

MayBay::~MayBay() {

}

void MayBay::set_hang_hang_khong(string hang_hang_khong) {
    this->hang_hang_khong = hang_hang_khong; 
}

void MayBay::set_ngay_khoi_hanh(Date ngay_khoi_hanh) {
    this->ngay_khoi_hanh = ngay_khoi_hanh; 
}

string MayBay::get_hang_hang_khong() { 
    return hang_hang_khong; 
}

Date MayBay::get_ngay_khoi_hanh() {
    return ngay_khoi_hanh;
}

void MayBay::nhap() {

    cout << "\nNhap ma may bay: ";
    cin.ignore();
    getline(cin, ma_phuong_tien);

    cout << "Nhap ten may bay: ";
    getline(cin, ten_phuong_tien);

    cout << "Nhap gia thue: ";
    cin >> gia_thue;
    cin.ignore();

    cout << "Nhap diem den: ";
    getline(cin, diem_den);

    cout << "Nhap hang hang khong: ";
    getline(cin, hang_hang_khong);

    cout << "Nhap ngay khoi hanh: ";
    cin >> ngay_khoi_hanh;

    trang_thai = CON_TRONG;
}

void MayBay::hien_thi() {
    cout << "\nMa may bay: " << ma_phuong_tien;
    cout << "\nTen may bay: " << ten_phuong_tien;
    cout << "\nGia thue: " << gia_thue;
    cout << "\nDiem den: " << diem_den;
    cout << "\nHang hang khong: " << hang_hang_khong;
    cout << "\nNgay khoi hanh: " << ngay_khoi_hanh;

    cout << "\nTrang thai: ";
    if (trang_thai == CON_TRONG) {
        cout << "Con trong";
    }
    else if (trang_thai == DA_DAT) {
        cout << "Da dat";
    }
    else if (trang_thai == DANG_BAO_TRI) {
        cout << "Dang bao tri";
    }
    cout << endl;
}

void MayBay::cap_nhat() {
    cout << "\nDiem den hien_thi tai: " << diem_den;
    cout << "\nNhap diem den moi: ";
    cin.ignore();
    getline(cin, diem_den);
}

void MayBay::chinh_sua() {
    cout << "\nChinh sua thong tin may bay:\n";
    nhap();
}

void MayBay::dat_phuong_tien() {
    trang_thai = DA_DAT;
}

void MayBay::kiem_tra_trang_thai() {
    cout << "\nTrang thai hien_thi tai: ";
    if (trang_thai == CON_TRONG) {
        cout << "Con trong";
    }
    else if (trang_thai == DA_DAT) {
        cout << "Da dat";
    }
    else if (trang_thai == DANG_BAO_TRI) {
        cout << "Dang bao tri";
    }
    cout << endl;
}

void MayBay::cap_nhat_trang_thai() {
    int lua_chon;
    cout << "\nChon trang thai moi: 1-Con trong, 2-Da dat, 3-Dang bao tri: ";
    cin >> lua_chon;
    switch (lua_chon) {
    case 1: trang_thai = CON_TRONG; break;
    case 2: trang_thai = DA_DAT; break;
    case 3: trang_thai = DANG_BAO_TRI; break;
    default: cout << "Lua chon khong hop le!"; break;
    }
}

// ======================== XE KHACH ========================

XeKhach::XeKhach() {
    this->ma_phuong_tien = "";
    this->ten_phuong_tien = "";
    this->gia_thue = 0;
    this->diem_den = "";
    this->trang_thai = CON_TRONG;
    this->ten_tai_xe = "";
    this->loai_xe = XE_16_CHO;
}

XeKhach::~XeKhach() { }

void XeKhach::set_ten_tai_xe(string ten_tai_xe) {
    this->ten_tai_xe = ten_tai_xe;
}

void XeKhach::set_loai_xe(LoaiXeKhach loai_xe) { 
    this->loai_xe = loai_xe; 
}

string XeKhach::get_ten_tai_xe() { 
    return ten_tai_xe;
}

XeKhach::LoaiXeKhach XeKhach::get_loai_xe() {
    return loai_xe;
}

void XeKhach::nhap() {
    cout << "\nNhap ma xe khach: ";
    cin.ignore();
    getline(cin, ma_phuong_tien);

    cout << "Nhap ten xe khach: ";
    getline(cin, ten_phuong_tien);

    cout << "Nhap gia thue: ";
    cin >> gia_thue;
    cin.ignore();

    cout << "Nhap diem den: ";
    getline(cin, diem_den);

    cout << "Nhap ten tai xe: ";
    getline(cin, ten_tai_xe);

    int lua_chon;
    cout << "Chon loai xe khach (1-16 cho, 2-45 cho): ";
    cin >> lua_chon;
    if (lua_chon == 1) loai_xe = XE_16_CHO;
    else loai_xe = XE_45_CHO;

    trang_thai = CON_TRONG;
}

void XeKhach::hien_thi() {
    cout << "\n=== THONG TIN XE KHACH ===";
    cout << "\nMa xe khach: " << ma_phuong_tien;
    cout << "\nTen xe khach: " << ten_phuong_tien;
    cout << "\nGia thue: " << gia_thue;
    cout << "\nDiem den: " << diem_den;
    cout << "\nTen tai xe: " << ten_tai_xe;

    cout << "\nLoai xe: ";
    if (loai_xe == XE_16_CHO) cout << "16 cho";
    else if (loai_xe == XE_45_CHO) cout << "45 cho";

    cout << "\nTrang thai: ";
    if (trang_thai == CON_TRONG) cout << "Con trong";
    else if (trang_thai == DA_DAT) cout << "Da dat";
    else if (trang_thai == DANG_BAO_TRI) cout << "Dang bao tri";
    cout << endl;
}

void XeKhach::cap_nhat() {
    cout << "\nDiem den hien_thi tai: " << diem_den;
    cout << "\nNhap diem den moi: ";
    cin.ignore();
    getline(cin, diem_den);

    cout << "Loai xe hien_thi tai: ";
    if (loai_xe == XE_16_CHO) cout << "16 cho";
    else if (loai_xe == XE_45_CHO) cout << "45 cho";
    cout << "\nChon loai xe moi (1-16 cho, 2-45 cho): ";

    int lua_chon;
    cin >> lua_chon;
    if (lua_chon == 1) loai_xe = XE_16_CHO;
    else if (lua_chon == 2) loai_xe = XE_45_CHO;
    else cout << "Khong hop le.\n";
}

void XeKhach::chinh_sua() {
    cout << "\nChinh sua thong tin xe khach:\n";
    nhap();
}

void XeKhach::dat_phuong_tien() { 
    trang_thai = DA_DAT;
}

void XeKhach::kiem_tra_trang_thai() {
    cout << "\nTrang thai hien_thi tai: ";
    if (trang_thai == CON_TRONG) cout << "Con trong";
    else if (trang_thai == DA_DAT) cout << "Da dat";
    else if (trang_thai == DANG_BAO_TRI) cout << "Dang bao tri";
    cout << endl;
}

void XeKhach::cap_nhat_trang_thai() {
    int lua_chon;
    cout << "\nChon trang thai moi: 1-Con trong, 2-Da dat, 3-Dang bao tri: ";
    cin >> lua_chon;
    if (lua_chon == 1) trang_thai = CON_TRONG;
    else if (lua_chon == 2) trang_thai = DA_DAT;
    else if (lua_chon == 3) trang_thai = DANG_BAO_TRI;
    else cout << "Lua chon khong hop le!\n";
}

// ======================== XE HƠI ========================

XeHoi::XeHoi() {
    this->ma_phuong_tien = "";
    this->ten_phuong_tien = "";
    this->gia_thue = 0;
    this->diem_den = "";
    this->trang_thai = CON_TRONG;
    this->loai_xe = XE_XANG;
    this->so_ghe = XE_5_CHO;
}

XeHoi::~XeHoi() {

}

void XeHoi::set_loai_xe(LoaiXeHoi loai_xe_enum) {
    this->loai_xe = loai_xe_enum;
}

void XeHoi::set_suc_chua(SoGhe suc_chua_enum) {
    this->so_ghe = suc_chua_enum;
}

XeHoi::LoaiXeHoi XeHoi::get_loai_xe_enum() {
    return this->loai_xe;
}

XeHoi::SoGhe XeHoi::get_suc_chua_enum() {
    return this->so_ghe;
}

void XeHoi::nhap() {
    cout << "\nNhap ma xe hoi: ";
    cin.ignore();
    getline(cin, ma_phuong_tien);

    cout << "Nhap ten xe hoi: ";
    getline(cin, ten_phuong_tien);

    cout << "Nhap gia thue: ";
    cin >> gia_thue;
    cin.ignore();

    cout << "Nhap diem den: ";
    getline(cin, diem_den);

    int lua_chon;

    cout << "Chon loai xe (1 - Xe xang, 2 - Xe dien): ";
    cin >> lua_chon;
    if (lua_chon == 1) loai_xe = XE_XANG;
    else if (lua_chon == 2) loai_xe = XE_DIEN;
    else cout << "Khong hop le!!!!!\n";

    cout << "Chon so ghe (1 - 5 cho, 2 - 7 cho): ";
    cin >> lua_chon;
    if (lua_chon == 1) so_ghe = XE_5_CHO;
    else if (lua_chon == 2) so_ghe = XE_7_CHO;
    else cout << "Khong hop le!!!!!\n";

    trang_thai = CON_TRONG;
}

void XeHoi::hien_thi() {
    cout << "\n=== THONG TIN XE HOI ===";
    cout << "\nMa xe hoi: " << ma_phuong_tien;
    cout << "\nTen xe hoi: " << ten_phuong_tien;
    cout << "\nGia thue: " << gia_thue;
    cout << "\nDiem den: " << diem_den;

    cout << "\nLoai xe: ";
    if (loai_xe == XE_XANG) cout << "Xe xang";
    else cout << "Xe dien";

    cout << "\nSo ghe: ";
    if (so_ghe == XE_5_CHO) cout << "5 cho";
    else cout << "7 cho";

    cout << "\nTrang thai: ";
    if (trang_thai == CON_TRONG) cout << "Con trong";
    else if (trang_thai == DA_DAT) cout << "Da dat";
    else cout << "Dang bao tri";
    cout << endl;
}

void XeHoi::cap_nhat() {
    cout << "\nDiem den hien_thi tai: " << diem_den;
    cout << "\nNhap diem den moi: ";
    cin.ignore();
    getline(cin, diem_den);

    cout << "Loai xe hien_thi tai: ";
    if (loai_xe == XE_XANG) cout << "Xe xang";
    else cout << "Xe dien";

    int lua_chon;
    cout << "\nChon loai xe moi (1 - Xe xang, 2 - Xe dien): ";
    cin >> lua_chon;
    if (lua_chon == 1) loai_xe = XE_XANG;
    else if (lua_chon == 2) loai_xe = XE_DIEN;
    else cout << "Khong hop le!!!!!\n";

    cout << "So ghe hien_thi tai: ";
    if (so_ghe == XE_5_CHO) cout << "5 cho";
    else cout << "7 cho";

    cout << "\nChon so ghe moi (1 - 5 cho, 2 - 7 cho): ";
    cin >> lua_chon;
    if (lua_chon == 1) so_ghe = XE_5_CHO;
    else if (lua_chon == 2) so_ghe = XE_7_CHO;
    else cout << "Khong hop le!!!!!\n";
}

void XeHoi::chinh_sua() {
    cout << "\nChinh sua thong tin xe hoi:\n";
    nhap();
}

void XeHoi::dat_phuong_tien() {
    trang_thai = DA_DAT;
}

void XeHoi::kiem_tra_trang_thai() {
    cout << "\nTrang thai hien_thi tai: ";
    if (trang_thai == CON_TRONG) cout << "Con trong";
    else if (trang_thai == DA_DAT) cout << "Da dat";
    else cout << "Dang bao tri";
    cout << endl;
}

void XeHoi::cap_nhat_trang_thai() {
    int lua_chon;
    cout << "\nChon trang thai moi: ";
    cout << "\n1. Con trong";
    cout << "\n2. Da dat";
    cout << "\n3. Dang bao tri";
    cout << "\nNhap lua chon: ";
    cin >> lua_chon;

    if (lua_chon == 1) trang_thai = CON_TRONG;
    else if (lua_chon == 2) trang_thai = DA_DAT;
    else if (lua_chon == 3) trang_thai = DANG_BAO_TRI;
    else cout << "Lua chon khong hop le!\n";
}

// ======================== LINKLIST ========================

DanhSachPhuongTien::DanhSachPhuongTien() {
    this->head = nullptr;
}

DanhSachPhuongTien::~DanhSachPhuongTien() {
    NodePhuongTien* hien_tai = this->head;
    while (hien_tai != nullptr) {
        NodePhuongTien* xoa_node = hien_tai;
        hien_tai = hien_tai->next;
        delete xoa_node->data;
        delete xoa_node;
    }
    this->head = nullptr;
}

void DanhSachPhuongTien::them(PhuongTien* phuong_tien) {
    NodePhuongTien* node_moi = new NodePhuongTien;
    node_moi->data = phuong_tien;
    node_moi->next = nullptr;

    if (this->head == nullptr) {
        this->head = node_moi;
    }
    else {
        NodePhuongTien* hien_tai = this->head;
        while (hien_tai->next != nullptr) {
            hien_tai = hien_tai->next;
        }
        hien_tai->next = node_moi;
    }
}

void DanhSachPhuongTien::xoa(string ma_phuong_tien) {
    if (this->head == nullptr) {
        cout << "Danh sach rong.\n";
        return;
    }

    NodePhuongTien* hien_tai = this->head;
    NodePhuongTien* truoc = nullptr;

    while (hien_tai != nullptr && hien_tai->data->get_ma_phuong_tien() != ma_phuong_tien) {
        truoc = hien_tai;
        hien_tai = hien_tai->next;
    }

    if (hien_tai == nullptr) {
        cout << "Khong tim thay phuong tien co ma: " << ma_phuong_tien << endl;
        return;
    }

    if (truoc == nullptr) {
        this->head = hien_tai->next;
    }
    else {
        truoc->next = hien_tai->next;
    }

    delete hien_tai->data;
    delete hien_tai;

    cout << "Da xoa phuong tien co ma: " << ma_phuong_tien << endl;
}

void DanhSachPhuongTien::chinh_sua(string ma_phuong_tien) {
    NodePhuongTien* hien_tai = this->head;
    while (hien_tai != nullptr) {
        if (hien_tai->data->get_ma_phuong_tien() == ma_phuong_tien) {
            cout << "Nhap thong tin moi cho phuong tien co ma: " << ma_phuong_tien << endl;
            hien_tai->data->chinh_sua();
            return;
        }
        hien_tai = hien_tai->next;
    }
    cout << "Khong tim thay phuong tien co ma: " << ma_phuong_tien << endl;
}

PhuongTien* DanhSachPhuongTien::tim_kiem(string ma_phuong_tien) {
    NodePhuongTien* cur = head;
    while (cur != nullptr) {
        if (cur->data->get_ma_phuong_tien() == ma_phuong_tien) {
            return cur->data;
        }
        cur = cur->next;
    }
    return nullptr; // không tìm thấy
}


void DanhSachPhuongTien::hien_thi() {
    NodePhuongTien* hien_tai = this->head;
    if (hien_tai == nullptr) {
        cout << "Danh sach phuong tien rong.\n";
        return;
    }

    cout << "\n+------------+-------------------------------+----------------------+---------------+---------------+----------------+\n";
    cout << "| Ma PT      | Ten phuong tien               | Diem den             | Trang thai    | Gia thue      | So ngay thue   |\n";
    cout << "+------------+-------------------------------+----------------------+---------------+---------------+----------------+\n";

    while (hien_tai != nullptr) {
        PhuongTien* pt = hien_tai->data;
        cout << "| " << left << setw(10) << pt->get_ma_phuong_tien()
            << " | " << left << setw(29) << pt->get_ten_phuong_tien()
            << " | " << left << setw(20) << pt->get_diem_den()
            << " | " << left << setw(13) << pt->trang_thai_to_string()
            << " | " << right << setw(13) << fixed << setprecision(0) << pt->get_gia_thue()
            << " | " << right << setw(14) << pt->get_so_ngay_thue()
            << " |\n";
        cout << "+------------+-------------------------------+----------------------+---------------+---------------+----------------+\n";

        hien_tai = hien_tai->next;
    }

}

void DanhSachPhuongTien::doc_file() {
    string filename = "ds_phuong_tien.txt"; // tự đặt tên file ở đây
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong mo duoc file de doc!\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        PhuongTien* p = nullptr;

        if (line.rfind("MB", 0) == 0)
            p = new MayBay();
        else if (line.rfind("XK", 0) == 0)
            p = new XeKhach();
        else if (line.rfind("XH", 0) == 0)
            p = new XeHoi();

        if (p != nullptr) {
            p->doc_file(line);
            them(p);
        }
    }

    file.close();
}


// ==================== MAY BAY ====================
void MayBay::doc_file(string line) {
    stringstream ss(line);
    string temp;

    getline(ss, ma_phuong_tien, ';');
    getline(ss, ten_phuong_tien, ';');
    getline(ss, temp, ';');
    gia_thue = stod(temp);

    getline(ss, temp, ';');
    if (temp == "CON_TRONG") trang_thai = CON_TRONG;
    else if (temp == "DA_DAT") trang_thai = DA_DAT;
    else trang_thai = DANG_BAO_TRI;

    getline(ss, diem_den, ';');
    getline(ss, hang_hang_khong, ';');

    getline(ss, temp, ';');
    ngay_khoi_hanh.phan_tich_chuoi_ngay(temp); // giả sử lớp Date có hàm parse("dd/mm/yyyy")
}


// ==================== XE KHÁCH ====================
void XeKhach::doc_file(string line) {
    stringstream ss(line);
    string temp;

    getline(ss, ma_phuong_tien, ';');
    getline(ss, ten_phuong_tien, ';');

    getline(ss, temp, ';');
    so_ngay_thue = stoi(temp);

    getline(ss, temp, ';');
    gia_thue = stod(temp);

    getline(ss, ten_tai_xe, ';');

    getline(ss, temp, ';');
    if (temp == "CON_TRONG") trang_thai = CON_TRONG;
    else if (temp == "DA_DAT") trang_thai = DA_DAT;
    else trang_thai = DANG_BAO_TRI;

    getline(ss, diem_den, ';');
    getline(ss, temp, ';'); // hãng xe
    string hang_xe = temp;

    getline(ss, temp, ';'); // loại xe
    if (temp.find("45") != string::npos) loai_xe = XE_45_CHO;
    else loai_xe = XE_16_CHO;
}


// ==================== XE HƠI ====================
void XeHoi::doc_file(string line) {
    stringstream ss(line);
    string temp;

    getline(ss, ma_phuong_tien, ';');
    getline(ss, ten_phuong_tien, ';');

    getline(ss, temp, ';');
    so_ngay_thue = stoi(temp);

    getline(ss, temp, ';');
    gia_thue = stod(temp);

    getline(ss, temp, ';');
    if (temp == "CON_TRONG") trang_thai = CON_TRONG;
    else if (temp == "DA_DAT") trang_thai = DA_DAT;
    else trang_thai = DANG_BAO_TRI;

    getline(ss, diem_den, ';');

    getline(ss, temp, ';');
    if (temp.find("dien") != string::npos || temp.find("Dien") != string::npos)
        loai_xe = XE_DIEN;
    else
        loai_xe = XE_XANG;

    getline(ss, temp, ';');
    if (temp.find("7") != string::npos)
        so_ghe = XE_7_CHO;
    else
        so_ghe = XE_5_CHO;
}

// ==================== GHI FILE ====================
void MayBay::ghi_file(ofstream& file) {
    file << ma_phuong_tien << ";"
        << ten_phuong_tien << ";"
        << fixed << setprecision(0) << gia_thue << ";"
        << (trang_thai == CON_TRONG ? "CON_TRONG" : (trang_thai == DA_DAT ? "DA_DAT" : "DANG_BAO_TRI")) << ";"
        << diem_den << ";"
        << hang_hang_khong << ";"
        << ngay_khoi_hanh.chuoi_ngay_thang_nam()
        << "\n";
}

void XeKhach::ghi_file(ofstream& file) {
    file << ma_phuong_tien << ";"
        << ten_phuong_tien << ";"
        << so_ngay_thue << ";"
        << fixed << setprecision(0) << gia_thue << ";"
        << ten_tai_xe << ";"
        << (trang_thai == CON_TRONG ? "CON_TRONG" : (trang_thai == DA_DAT ? "DA_DAT" : "DANG_BAO_TRI")) << ";"
        << diem_den << ";"
        << "Futa" << ";"  // hãng xe - cần lấy từ đâu đó hoặc thêm getter
        << (loai_xe == XE_45_CHO ? "45 cho" : "16 cho")
        << "\n";
}

void XeHoi::ghi_file(ofstream& file) {
    file << ma_phuong_tien << ";"
        << ten_phuong_tien << ";"
        << so_ngay_thue << ";"
        << fixed << setprecision(0) << gia_thue << ";"
        << (trang_thai == CON_TRONG ? "CON_TRONG" : (trang_thai == DA_DAT ? "DA_DAT" : "DANG_BAO_TRI")) << ";"
        << diem_den << ";"
        << (loai_xe == XE_DIEN ? "XE_DIEN" : "XE_XANG") << ";"
        << (so_ghe == XE_7_CHO ? "7 cho" : "5 cho")
        << "\n";
}

void DanhSachPhuongTien::ghi_file() {
    ofstream file("ds_phuong_tien.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }

    // Ghi MayBay
    bool hasMayBay = false;
    NodePhuongTien* p = head;
    while (p) {
        if (dynamic_cast<MayBay*>(p->data)) {
            if (!hasMayBay) {
                file << "MayBay\n";
                hasMayBay = true;
            }
            p->data->ghi_file(file);
        }
        p = p->next;
    }

    // Ghi XeKhach
    bool hasXeKhach = false;
    p = head;
    while (p) {
        if (dynamic_cast<XeKhach*>(p->data)) {
            if (!hasXeKhach) {
                file << "\nXeKhach\n";
                hasXeKhach = true;
            }
            p->data->ghi_file(file);
        }
        p = p->next;
    }

    // Ghi XeHoi
    bool hasXeHoi = false;
    p = head;
    while (p) {
        if (dynamic_cast<XeHoi*>(p->data)) {
            if (!hasXeHoi) {
                file << "\nXeHoi\n";
                hasXeHoi = true;
            }
            p->data->ghi_file(file);
        }
        p = p->next;
    }

    file.close();
    cout << "Da ghi file thanh cong!\n";
}

void DanhSachPhuongTien::insertion_sort_theo_gia() {
    if (this->head == nullptr || this->head->next == nullptr) return;

    NodePhuongTien* sorted = nullptr;
    NodePhuongTien* hien_tai = this->head;

    while (hien_tai != nullptr) {
        NodePhuongTien* next = hien_tai->next;
        if (sorted == nullptr || hien_tai->data->get_gia_thue() < sorted->data->get_gia_thue()) {
            hien_tai->next = sorted;
            sorted = hien_tai;
        }
        else {
            NodePhuongTien* temp = sorted;
            while (temp->next != nullptr && temp->next->data->get_gia_thue() <= hien_tai->data->get_gia_thue()) {
                temp = temp->next;
            }
            hien_tai->next = temp->next;
            temp->next = hien_tai;
        }
        hien_tai = next;
    }
    this->head = sorted;
}

void DanhSachPhuongTien::bubble_sort_theo_trang_thai() {
    if (this->head == nullptr) return;

    bool swapped;
    NodePhuongTien* cuoi = nullptr;

    do {
        swapped = false;
        NodePhuongTien* hien_tai = this->head;

        while (hien_tai->next != cuoi) {
            if (hien_tai->data->get_trang_thai() > hien_tai->next->data->get_trang_thai()) {
                swap(hien_tai->data, hien_tai->next->data);
                swapped = true;
            }
            hien_tai = hien_tai->next;
        }
        cuoi = hien_tai;
    } while (swapped);
}

void DanhSachPhuongTien::hien_thi_menu_phuong_tien() {

    int choice;
    this->hien_thi();

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Them phuong tien moi";
        cout << "\n2. Hien thi danh sach";
        cout << "\n3. Xoa phuong tien theo ma";
        cout << "\n4. Tim phuong tien theo ma";
        cout << "\n5. Chinh sua phuong tien";
        cout << "\n6. Sap xep theo gia thue";
        cout << "\n7. Sap xep theo trang thai";
        cout << "\n8. Ghi danh sach ra file ";
        cout << "\n0. Thoat";
        cout << "\n==============================";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int loai;
            cout << "Chon loai phuong tien (1. May bay, 2. Xe khach, 3. Xe hoi): ";
            cin >> loai;
            cin.ignore();

            PhuongTien* pt = nullptr;
            if (loai == 1) {
                pt = new MayBay();
            }
            else if (loai == 2) {
                pt = new XeKhach();
            }
            else if (loai == 3) {
                pt = new XeHoi();
            }
            else {
                cout << "Loai phuong tien khong hop le!\n";
                break;
            }

            pt->nhap();
            this->them(pt);
            break;
        }

        case 2:
            this->hien_thi();
            break;

        case 3: {
            string ma;
            cout << "Nhap ma phuong tien can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            this->hien_thi();
            break;
        }

        case 4: {
            string ma;
            cout << "Nhap ma phuong tien can tim: ";
            getline(cin, ma);
            this->tim_kiem(ma);
            break;
        }

        case 5: {
            string ma;
            cout << "Nhap ma phuong tien can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }

        case 6:
            this->insertion_sort_theo_gia();
            cout << "Da sap xep theo gia thue!\n";
            this->hien_thi();
            break;

        case 7:
            this->bubble_sort_theo_trang_thai();
            cout << "Da sap xep theo trang thai!\n";
            this->hien_thi();
            break;
        case 8: {
            this->ghi_file();
            cout << "Da ghi danh sach ra file thanh cong!\n";
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
