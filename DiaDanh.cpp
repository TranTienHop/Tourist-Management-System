#include"DiaDanh.h"

DiaDanh::DiaDanh() : gia_du_lich(0) {

}

DiaDanh::~DiaDanh() {

}

void DiaDanh::set_ma_dia_danh(string ma) { 
    ma_dia_danh = ma;
}

void DiaDanh::set_ten_dia_danh(string ten) {
    ten_dia_danh = ten;
}

void DiaDanh::set_ngay_khoi_hanh(Date d) {
    ngay_khoi_hanh = d; 
}

void DiaDanh::set_gia(float g) {
    gia_du_lich = g;
}

string DiaDanh::get_ma_dia_danh() { 
    return ma_dia_danh;
}

string DiaDanh::get_ten_dia_danh() { 
    return ten_dia_danh;
}

Date DiaDanh::get_ngay_khoi_hanh() {
    return ngay_khoi_hanh;
}

float DiaDanh::get_gia() {
    return gia_du_lich;
}

void DiaDanh::nhap() {
    cout << "Nhap ma dia danh: ";
    cin >> this->ma_dia_danh;
    cin.ignore();
    cout << "Nhap ten dia danh: ";
    getline(cin, this->ten_dia_danh);
    cout << "Nhap ngay khoi hanh: ";
    cin >> this->ngay_khoi_hanh;  
    cout << "Nhap gia moi nguoi: ";
    cin >> this->gia_du_lich;
}

void DiaDanh::chinh_sua() {
    cout << "Nhap thong tin dia danh moi:\n";
    this->nhap(); 
}

void DiaDanh::hien_thi() {
    cout << "\nMa dia danh: " << this->ma_dia_danh << endl;
    cout << "Ten dia danh: " << this->ten_dia_danh << endl;
    cout << "Ngay khoi hanh: " << this->ngay_khoi_hanh << endl;
    cout << "Gia moi nguoi: " << fixed << setprecision(2) << this->gia_du_lich << endl;
}

void DiaDanh::cap_nhat() {
    cout << "Sua ngay khoi hanh : ";
    cin >> this->ngay_khoi_hanh;
    cout << "Sua gia moi nguoi: ";
    cin >> this->gia_du_lich;
}

//================= CLASS DANHSACHDIADANH =================//
DanhSachDiaDanh::DanhSachDiaDanh() : head(nullptr) {

}

DanhSachDiaDanh::~DanhSachDiaDanh() {
    while (head) {
        NodeDiaDanh* tmp = head;
        head = head->next;
        delete tmp;
    }
}

void DanhSachDiaDanh::them() {
    DiaDanh* d = new DiaDanh;
    d->nhap();
    NodeDiaDanh* p = new NodeDiaDanh{ d, nullptr };
    if (!head) head = p;
    else {
        NodeDiaDanh* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = p;
    }
}

void DanhSachDiaDanh::xoa(string ma) {
    if (!head) return;

    if (head->data->get_ma_dia_danh() == ma) {
        NodeDiaDanh* tmp = head;
        head = head->next;
        delete tmp->data; // xóa đối tượng DiaDanh
        delete tmp;       // xóa node
        return;
    }

    NodeDiaDanh* cur = head;
    while (cur->next && cur->next->data->get_ma_dia_danh() != ma)
        cur = cur->next;

    if (cur->next) {
        NodeDiaDanh* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp->data; // xóa đối tượng DiaDanh
        delete tmp;       // xóa node
    }
}

void DanhSachDiaDanh::cap_nhat(string ma) {
    DiaDanh* p = tim_kiem(ma);
    if (p) p->cap_nhat();
}

void DanhSachDiaDanh::chinh_sua(string ma) {
    cap_nhat(ma);
}

DiaDanh* DanhSachDiaDanh::tim_kiem(string ma) {
    NodeDiaDanh* cur = head;
    while (cur) {
        if (cur->data->get_ma_dia_danh() == ma)
            return cur->data;
        cur = cur->next;
    }
    return nullptr;
}

void DanhSachDiaDanh::hien_thi() {
    if (!head) {
        cout << "Danh sach dia danh rong!\n";
        return;
    }

    cout << "+------------+---------------------------+---------------+-------------+\n";
    cout << "| Ma Dia Danh| Ten Dia Danh              | Ngay Khoi Hanh| Gia (VND)   |\n";
    cout << "+------------+---------------------------+---------------+-------------+\n";

    NodeDiaDanh* temp = head;
    while (temp) {
        DiaDanh* dd = temp->data;

        cout << "| " << left << setw(11) << dd->get_ma_dia_danh()
            << "| " << left << setw(26) << dd->get_ten_dia_danh()
            << "| " << left << setw(15) << dd->get_ngay_khoi_hanh()
            << "    | " << right << setw(12) << fixed << setprecision(2) << dd->get_gia()
            << "|\n";

        temp = temp->next;
    }

    cout << "+------------+---------------------------+---------------+-------------+\n";
}


void DanhSachDiaDanh::insertion_sort_gia() {
    if (!head || !head->next) return;
    NodeDiaDanh* sorted = nullptr;
    while (head) {
        NodeDiaDanh* cur = head;
        head = head->next;

        if (!sorted || cur->data->get_gia() < sorted->data->get_gia()) {
            cur->next = sorted;
            sorted = cur;
        }
        else {
            NodeDiaDanh* tmp = sorted;
            while (tmp->next && tmp->next->data->get_gia() < cur->data->get_gia())
                tmp = tmp->next;
            cur->next = tmp->next;
            tmp->next = cur;
        }
    }
    head = sorted;
}

void DanhSachDiaDanh::selection_sort_dia_danh() {
    for (NodeDiaDanh* i = head; i && i->next; i = i->next) {
        NodeDiaDanh* min = i;
        for (NodeDiaDanh* j = i->next; j; j = j->next)
            if (j->data->get_ten_dia_danh() < min->data->get_ten_dia_danh())
                min = j;
        if (min != i) swap(i->data, min->data);
    }
}

void DanhSachDiaDanh::bubble_sort_ngay() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        for (NodeDiaDanh* p = head; p->next; p = p->next) {
            if (p->data->get_ngay_khoi_hanh() > p->next->data->get_ngay_khoi_hanh()) {
                swap(p->data, p->next->data); // swap con trỏ, node không đổi vị trí
                swapped = true;
            }
        }
    } while (swapped);
}

void DanhSachDiaDanh::doc_file() {
    ifstream file("ds_dia_danh.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc file ds_dia_danh.txt\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string ma, ten, ngay_str, gia_str;

        getline(ss, ma, ';');
        getline(ss, ten, ';');
        getline(ss, ngay_str, ';');
        getline(ss, gia_str, ';');
        Date ngay;
        ngay.phan_tich_chuoi_ngay(ngay_str);
        float gia = stof(gia_str);
        DiaDanh* d = new DiaDanh;
        d->set_ma_dia_danh(ma);
        d->set_ten_dia_danh(ten);
        d->set_ngay_khoi_hanh(ngay);
        d->set_gia(gia);

        NodeDiaDanh* p = new NodeDiaDanh{ d, nullptr };
        if (!head) head = p;
        else {
            NodeDiaDanh* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = p;
        }
    }

    file.close();
}

void DanhSachDiaDanh::ghi_file() {
    ofstream file("ds_dia_danh.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc file de ghi!\n";
        return;
    }

    NodeDiaDanh* p = head;
    while (p != nullptr) {
        DiaDanh* d = p->data;
        file << d->get_ma_dia_danh() << ";"
            << d->get_ten_dia_danh() << ";"
            << d->get_ngay_khoi_hanh().chuoi_ngay_thang_nam() << ";"
            << fixed << setprecision(0) << d->get_gia()
            << "\n";
        p = p->next;
    }

    file.close();
    cout << "Da ghi file thanh cong!\n";
}

void DanhSachDiaDanh::hien_thi_menu_dia_danh() {

    int choice;
    this->hien_thi();

    do {
        cout << "\n=============== MENU ===============";
        cout << "\n1. Them dia danh moi";
        cout << "\n2. Hien thi danh sach";
        cout << "\n3. Xoa dia danh theo ma";
        cout << "\n4. Tim dia danh theo ma";
        cout << "\n5. Chinh sua dia danh";
        cout << "\n6. Sap xep theo gia ";
        cout << "\n7. Sap xep theo ten dia danh";
        cout << "\n8. Sap xep theo ngay khoi hanh";
        cout << "\n9. Ghi danh sach ra file";
        cout << "\n0. Thoat";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            this->them();
            this->hien_thi();
            break;
        }

        case 2:
            this->hien_thi();
            break;

        case 3: {
            string ma;
            cout << "Nhap ma dia danh can xoa: ";
            getline(cin, ma);
            this->xoa(ma);
            this->hien_thi();
            break;
        }

        case 4: {
            string ma;
            cout << "Nhap ma dia danh can tim: ";
            getline(cin, ma);
            DiaDanh* p = this->tim_kiem(ma);
            if (p) {
       
                p->hien_thi();
            }
            else {
                cout << "Khong tim thay dia danh co ma \"" << ma << "\"!\n";
            }
            break;
        }

        case 5: {
            string ma;
            cout << "Nhap ma dia danh can chinh sua: ";
            getline(cin, ma);
            this->chinh_sua(ma);
            this->hien_thi();
            break;
        }

        case 6:
            this->insertion_sort_gia();
            cout << "Da sap xep theo gia\n";
            this->hien_thi();
            break;

        case 7:
            this->selection_sort_dia_danh();
            cout << "Da sap xep theo ten dia danh n";
            this->hien_thi();
            break;

        case 8:
            this->bubble_sort_ngay();
            cout << "Da sap xep theo ngay khoi hanh\n";
            this->hien_thi();
            break;
        case 9: {
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
