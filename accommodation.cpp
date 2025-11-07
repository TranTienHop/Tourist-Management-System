#include<iostream>
#include<string> 
#include<fstream> 
#include<vector>
#include<sstream> 
#include"accommodation.h"

using namespace std; 

Accommodation::~Accommodation() {}

Accommodation::Accommodation() {
	accommodation_id = " ";
	name = " ";
	address = " ";
	mobile = 0;
	price = 0;
	room_status = "Unknow";  
} 

Accommodation::Accommodation(string id, string n, string addr, int m, double p, string r_s) {
	accommodation_id = id;
    name = n;
    address = addr;
    mobile = m;
    price = p;
    room_status = r_s;
}

Accommodation::Accommodation(const Accommodation& ac) {
	accommodation_id = ac.accommodation_id;
    name = ac.name;
    address = ac.address;
    mobile = ac.mobile;
    price = ac.price;
    room_status = ac.room_status;
}

//Getter 
string Accommodation::get_accommodation_id() {
    return accommodation_id;
}

string Accommodation::get_name() {
    return name;
}

string Accommodation::get_address() {
    return address;
}

int Accommodation::get_mobile() {
    return mobile;
}

double Accommodation::get_price() {
    return price;
}

string Accommodation::get_room_status() {
    return room_status;
}

//Setter
void Accommodation::set_accommodation_id(string id) {
	accommodation_id = id; 
} 

void Accommodation::set_name(string n) {
    name = n;
}

void Accommodation::set_address(string addr) {
    address = addr;
}

void Accommodation::set_mobile(int m) {
    mobile = m;
}

void Accommodation::set_price(double p) {
    price = p;
}

void Accommodation::set_room_status(string r_s) {
    room_status = r_s;
}

istream& operator>>(istream& is, Accommodation& ac) {
	ac.input();
	return is;
}

ostream& operator<<(ostream& os, const Accommodation& ac) {
	ac.display();
	return os;
}

void readFromFile(const string& filename, vector<Accommodation*>& list) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong the mo file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ';');

        if (type == "Hotel") {
            string id, name, addr, r_s, uti;
            int mobile, star, total;
            double price;
            string temp;

            getline(ss, id, ';');
            getline(ss, name, ';');
            getline(ss, addr, ';');
            getline(ss, temp, ';'); mobile = stoi(temp);
            getline(ss, temp, ';'); price = stod(temp);
            getline(ss, r_s, ';');
            getline(ss, temp, ';'); star = stoi(temp);
            getline(ss, uti, ';');
            getline(ss, temp, ';'); total = stoi(temp);

            list.push_back(new Hotel(id, name, addr, mobile, price, r_s, star, uti, total));
        }
        else if (type == "Motel") {
            string id, name, addr, r_s, w_h, v_status;
            int mobile, m_count;
            double price;
            string temp;

            getline(ss, id, ';');
            getline(ss, name, ';');
            getline(ss, addr, ';');
            getline(ss, temp, ';'); mobile = stoi(temp);
            getline(ss, temp, ';'); price = stod(temp);
            getline(ss, r_s, ';');
            getline(ss, w_h, ';');
            getline(ss, temp, ';'); m_count = stoi(temp);
            getline(ss, v_status, ';');

            list.push_back(new Motel(id, name, addr, mobile, price, r_s, w_h, m_count, v_status));
        }
    }

    file.close();
    cout << "Da doc " << list.size() << " doi tuong tu file " << filename << endl;
}

//CLASS HOTEL 
Hotel::Hotel():Accommodation() {
	star_rating = 0;
	utilities =  "";
	total_rooms = 0; 
} 

Hotel::Hotel(string id, string name, string addr, int m, double p, string r_s, int star, string uti, int total):Accommodation(id, name, addr, m, p, r_s) {
	star_rating = star;
    utilities = uti;
    total_rooms = total;
}

Hotel::Hotel(const Hotel& h):Accommodation(h) {
	star_rating = h.star_rating;
    utilities = h.utilities;
    total_rooms = h.total_rooms;
} 

Hotel::~Hotel() {}

//Setter 
void Hotel::set_star_rating(int star) {
    star_rating = star;
}

void Hotel::set_utilities(string uti) {
    utilities = uti;
}

void Hotel::set_total_rooms(int total) {
    total_rooms = total;
}

//Getter 
int Hotel::get_star_rating() {
    return star_rating;
}

string Hotel::get_utilities() {
    return utilities;
}

int Hotel::get_total_rooms() {
    return total_rooms;
}

void Hotel::input() {
    cout << "\n========== NHAP THONG TIN KHACH SAN ==========\n";
	cout << "Nhap ma khach san: ";
	getline(cin, accommodation_id);
	cout << "\nNhap ten khach san: ";
	getline(cin, name);
	cout << "\nNhap dia chi khach san: ";
	getline(cin, address);
	cout << "\nNhap so dien thoai: ";
	cin >> mobile;
	cout << "\nNhap gia tien khach san: ";
	cin >> price;
	cin.ignore(); 
	cout << "\nNhap trang thai phong(Available/Booked): ";
	getline(cin, room_status);

    cout << "\nNhap so sao: ";
    cin >> star_rating;
    cin.ignore();
    cout << "\nNhap tien ich: ";
    getline(cin, utilities);
    cout << "\nNhap tong so phong: ";
    cin >> total_rooms;
    cin.ignore();
}

void Hotel::display() const {
    cout << "\n========== THONG TIN KHACH SAN ==========\n";
    cout << "\nMa khach san: " << accommodation_id;
	cout << "\nTen khach san: " << name;
	cout << "\nDia chi khach san: " << address;
	cout << "\nSo dien thoai: " << mobile;
	cout << "\nGia tien: " << price;
	cout << "\nTrang thai phong: " << room_status;

    cout << "\nSo sao khach san: " << star_rating;
    cout << "\nTien ich cua khach san: " << utilities;
    cout << "\nTong so phong: " << total_rooms;
}

void Hotel::update() {
    int choice;
    do {
        cout << "\n========== CAP NHAT THONG TIN KHACH SAN ==========\n";
        cout << "1. Cap nhat ma khach san\n";
        cout << "2. Cap nhat ten khach san\n";
        cout << "3. Cap nhat dia chi khach san\n";
        cout << "4. Cap nhat so dien thoai\n";
        cout << "5. Cap nhat gia tien\n";
        cout << "6. Cap nhat trang thai phong\n";
        cout << "7. Cap nhat so sao\n";
        cout << "8. Cap nhat tien ich\n";
        cout << "9. Cap nhat tong so phong\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Nhap ma khach san moi: ";
                getline(cin, accommodation_id);
                break;
            case 2:
                cout << "Nhap ten khach san moi: ";
                getline(cin, name);
                break;
            case 3:
                cout << "Nhap dia chi khach san moi: ";
                getline(cin, address);
                break;
            case 4:
                cout << "Nhap so dien thoai moi: ";
                cin >> mobile;
                cin.ignore();
                break;
            case 5:
                cout << "Nhap gia tien moi: ";
                cin >> price;
                cin.ignore();
                break;
            case 6:
                cout << "Nhap trang thai phong moi: ";
                getline(cin, room_status);
                break;
            case 7:
                cout << "Nhap so sao moi: ";
                cin >> star_rating;
                cin.ignore();
                break;
            case 8:
                cout << "Nhap tien ich moi: ";
                getline(cin, utilities);
                break;
            case 9:
                cout << "Nhap tong so phong moi: ";
                cin >> total_rooms;
                cin.ignore();
                break;
            case 0:
                cout << "Da thoat!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 0);
}

void Hotel::edit() {
	cout << "\n========== CHINH SUA TOAN BO THONG TIN KHACH SAN ==========\n";
    cout << "\nNhap ma khach san moi: ";
    getline(cin, accommodation_id);
    cout << "\nNhap ten khach san moi: ";
    getline(cin, name);
    cout << "\nNhap dia chi khach san moi: ";
    getline(cin, address);
    cout << "\nNhap so dien thoai moi: ";
    cin >> mobile;
    cout << "\nNhap gia tien moi: ";
    cin >> price;
    cin.ignore();
    cout << "\nNhap trang thai phong moi: ";
    getline(cin, room_status);
    cout << "\nNhap so sao moi: ";
    cin >> star_rating;
	cin.ignore();
	cout << "\nNhap tien ich moi: ";
	getline(cin, utilities);
	cout << "\nNhap tong so phong moi: ";
	cin >> total_rooms;  
    cout << "\nChinh sua thanh cong!";
} 

void Hotel::remove() {
	cout << "\nDa xoa thong tin cho o co ma: " << accommodation_id << endl;
    accommodation_id = "";
    name = "";
    address = "";
    mobile = 0;
    price = 0.0;
    room_status = "";
    star_rating = 0;
	utilities = "Deleted";
	total_rooms = 0; 
	cout << "\nDa xoa thanh cong!";
} 

void Hotel::search() {
	string keyword;
    cout << "\nNhap ten khach san can tim: ";
    getline(cin, keyword);
    if (name.find(keyword) != string::npos) {
        cout << "Tim thay thong tin phu hop:\n";
        display();
    } else {
        cout << "Khong tim thay thong tin phu hop\n";
    }
} 

void Hotel::save_to_file() {
	ofstream file("Accommodation.txt", ios::app); 
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }
    file << "Hotel;"
    	 << accommodation_id << ";"
         << name << ";"
         << address << ";"
         << mobile << ";"
         << price << ";"
         << room_status << ";"
         << star_rating << ";"
		 << utilities << ";"
		 << total_rooms << "\n"; 

    file.close();
    cout << "Da luu thong tin vao file thanh cong!\n";
} 

void Hotel::book_room() {
	if (room_status == "Available") {
        room_status = "Booked";
        cout << "Dat phong thanh cong!\n";
    } else if (room_status == "Booked") {
        cout << "Phong da co nguoi dat!\n";
    } else {
        cout << "Trang thai phong khong ro\n";
    }
} 

void Hotel::check_status() {
	cout << "\nTrang thai hien tai cua ma khach san [" << accommodation_id << "]: " << room_status << endl;
} 

void Hotel::update_status() {
	cout << "\nNhap trang thai moi cho phong (Available/Booked): ";
    getline(cin, room_status);
    cout << "Trang thai da cap nhat thanh: " << room_status << endl;
} 

//CLASS MOTEL
Motel::Motel() : Accommodation() {
    working_hours = "";
    motorbike_count = 0;
    vehicle_status = "Unknown";
}

Motel::Motel(string id, string n, string addr, int m, double p, string r_s, string w_h, int m_count, string v_status):Accommodation(id, n, addr, m, p, r_s) {
    working_hours = w_h;
    motorbike_count = m_count;
    vehicle_status = v_status;
}

Motel::Motel(const Motel& mt) : Accommodation(mt) {
    working_hours = mt.working_hours;
    motorbike_count = mt.motorbike_count;
    vehicle_status = mt.vehicle_status;
}

Motel::~Motel() {}
 
//Getter
 string Motel::get_working_hours() {
    return working_hours;
}

int Motel::get_motorbike_count() {
    return motorbike_count;
}

string Motel::get_vehicle_status() {
    return vehicle_status;
}

//Setter
void Motel::set_working_hours(string w) {
    working_hours = w;
}

void Motel::set_motorbike_count(int count) {
    motorbike_count = count;
}

void Motel::set_vehicle_status(string status) {
    vehicle_status = status;
}

void Motel::input() {
    cout << "\n========== NHAP THONG TIN NHA NGHI ==========\n";
	cout << "Nhap ma nha nghi: ";
	getline(cin, accommodation_id);
	cout << "\nNhap ten nha nghi: ";
	getline(cin, name);
	cout << "\nNhap dia chi nha nghi: ";
	getline(cin, address);
	cout << "\nNhap so dien thoai: ";
	cin >> mobile;
	cout << "\nNhap gia tien nha nghi: ";
	cin >> price;
	cin.ignore(); 
	cout << "\nNhap trang thai phong(Available/Booked): ";
	getline(cin, room_status);

    cout << "\nNhap gio lam viec (VD: 6h - 22h): ";
    getline(cin, working_hours);
    cout << "\nNhap so luong xe may: ";
    cin >> motorbike_count;
    cin.ignore();
    cout << "\nNhap trang thai bai do xe (Available/Full/...): ";
    getline(cin, vehicle_status);
} 

void Motel::display() const {
    cout << "\n========== THONG TIN NHA NGHI ==========\n";
    cout << "\nMa nha nghi: " << accommodation_id;
	cout << "\nTen nha nghi: " << name;
	cout << "\nDia chi nha nghi: " << address;
	cout << "\nSo dien thoai: " << mobile;
	cout << "\nGia tien: " << price;
	cout << "\nTrang thai phong: " << room_status;

    cout << "\nGio lam viec: " << working_hours;
    cout << "\nSo xe may hien co: " << motorbike_count;
    cout << "\nTrang thai bai do xe: " << vehicle_status;
}

void Motel::update() {
    int choice;
    do {
        cout << "\n========== CAP NHAT THONG TIN NHA NGHI ==========\n";
        cout << "1. Cap nhat ma nha nghi\n";
        cout << "2. Cap nhat ten nha nghi\n";
        cout << "3. Cap nhat dia chi nha nghi\n";
        cout << "4. Cap nhat so dien thoai\n";
        cout << "5. Cap nhat gia tien\n";
        cout << "6. Cap nhat trang thai phong\n";
        
        cout << "7. Cap nhat gio lam viec\n";
        cout << "8. Cap nhat so luong xe may\n";
        cout << "9. Cap nhat trang thai xe\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Nhap ma nha nghi moi: ";
                getline(cin, accommodation_id);
                break;
            case 2:
                cout << "Nhap ten nha nghi moi: ";
                getline(cin, name);
                break;
            case 3:
                cout << "Nhap dia chi nha nghi moi: ";
                getline(cin, address);
                break;
            case 4:
                cout << "Nhap so dien thoai moi: ";
                cin >> mobile;
                cin.ignore();
                break;
            case 5:
                cout << "Nhap gia tien moi: ";
                cin >> price;
                cin.ignore();
                break;
            case 6:
                cout << "Nhap trang thai phong moi: ";
                getline(cin, room_status);
                break;
            case 7:
                cout << "Nhap gio lam viec moi: ";
                getline(cin, working_hours);
                break;
            case 8:
                cout << "Nhap so luong xe may moi: ";
                cin >> motorbike_count;
                cin.ignore();
                break;
            case 9:
                cout << "Nhap trang thai bai do xe moi: ";
                getline(cin, vehicle_status);
                break;
            case 0:
                cout << "Da thoat!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 0);
}

void Motel::edit() {
	cout << "\n========== CHINH SUA TOAN BO THONG TIN NHA NGHI ==========\n";
    cout << "\nNhap ma nha nghi moi: ";
    getline(cin, accommodation_id);
    cout << "\nNhap ten nha nghi moi: ";
    getline(cin, name);
    cout << "\nNhap dia chi nha nghi moi: ";
    getline(cin, address);
    cout << "\nNhap so dien thoai moi: ";
    cin >> mobile;
    cout << "\nNhap gia tien nha nghi moi: ";
    cin >> price;
    cin.ignore();
    cout << "\nNhap trang thai phong moi: ";
    getline(cin, room_status);
    cout << "Nhap gio lam viec moi: ";
    getline(cin, working_hours);
	cout << "Nhap so luong xe may moi: ";
    cin >> motorbike_count;
    cin.ignore();
	cout << "Nhap trang thai bai do xe moi: ";
    getline(cin, vehicle_status);
    cout << "Chinh sua thanh cong!\n";
} 

void Motel::remove() {
	cout << "\nDa xoa thong tin cho o co ma: " << accommodation_id << endl;
    accommodation_id = "";
    name = "";
    address = "";
    mobile = 0;
    price = 0.0;
    room_status = "";
   	working_hours = "";
	motorbike_count = 0;
	vehicle_status = "Deleted"; 
	cout << "\nDa xoa thanh cong!";
} 

void Motel::search() {
	 string keyword;
    cout << "\nNhap ten nha nghi can tim: ";
    getline(cin, keyword);
    if (name.find(keyword) != string::npos) {
        cout << "Tim thay thong tin phu hop:\n";
        display();
    } else {
        cout << "Khong tim thay thong tin phu hop\n";
    }
} 

void Motel::save_to_file() {
	ofstream file("Accommodation.txt", ios::app); 
    if (!file) {
        cout << "Khong the mo file!\n";
        return;
    }
    file << "Motel;"
    	 << accommodation_id << ";"
         << name << ";"
         << address << ";"
         << mobile << ";"
         << price << ";"
         << room_status << ";"
         << working_hours << ";"
         << motorbike_count << ";"
         << vehicle_status << "\n";

    file.close();
    cout << "Da luu thong tin vao file thanh cong!\n";
} 

void Motel::book_room() {
	if (room_status == "Available") {
        room_status = "Booked";
        cout << "Dat phong thanh cong!\n";
    } else if (room_status == "Booked") {
        cout << "Phong da co nguoi dat!\n";
    } else {
        cout << "Trang thai phong khong ro\n";
    }
} 

void Motel::check_status() {
	cout << "\nTrang thai hien tai cua ma cho o [" << accommodation_id << "]: " << room_status << endl;
} 

void Motel::update_status() {
	cout << "\nNhap trang thai moi cho phong (Available/Booked): ";
    getline(cin, room_status);
    cout << "Trang thai da cap nhat thanh: " << room_status << endl;
} 

void Motel::book_vehicle() {
    if (vehicle_status == "Available" && motorbike_count > 0) {
        motorbike_count--;
        if (motorbike_count == 0) vehicle_status = "Full";
        cout << "Dat xe thanh cong! So xe con lai: " << motorbike_count << endl;
    } else if (vehicle_status == "Full" || motorbike_count == 0) {
        cout << "Hien khong con xe trong!\n";
    } else {
        cout << "Trang thai xe khong ro.\n";
    }
}




