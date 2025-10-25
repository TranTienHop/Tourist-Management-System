#include"statistics.h"
#include<fstream> 

using namespace std;

statistics::statistics(){
	sum_customer = 0;
	sum_tour = 0;
	sum_price = 0; 
} 

statistics::~statistics() {}

//Getter 
int statistics::getSumCustomer() {
	return sum_customer; 
}

int statistics::getSumTour() {
	return sum_tour; 
}

double statistics::getSumPrice() {
	return sum_price; 
}

//Setter 
void statistics::setSumCustomer(int value) { 
	sum_customer = value; 
}

void statistics::setSumTour(int value) { 
	sum_tour = value; 
}

void statistics::setSumPrice(double value) { 
	sum_price = value; 
}

int statistics::count_tour(const BookingList& list) {
    int count = 0;
    BookingNode* p1 = list.head;
    while (p1 != NULL) {
        bool existed = false;
        BookingNode* p2 = list.head;
        while (p2 != p1) {
            if (p1->data.get_tour_id() == p2->data.get_tour_id()) {
                existed = true;
                break;
            }
            p2 = p2->next;
        }
        if (existed == false) count++;
        p1 = p1->next;
    }
    return count;
}

int statistics::count_customer(const BookingList& list, const string& customer_id) {
    int count = 0;
    BookingNode* p = list.head;
    while (p != NULL) {
        if (p->data.get_customer_id() == customer_id)
            count++;
        p = p->next;
    }
    return count;
}


//Chua hoan thien  
double statistics::sum_price_all_tour(const BookingList& list, const string& tour_id) {
    double total = 0.0;
    BookingNode* p = list.head;
    while (p != NULL) {
        if (p->data.get_tour_id() == tour_id)
            total += 0;
        p = p->next;
    }
    return total;
}

//In thong tin thong ke 
void statistics::printf_thong_ke() {
    cout << "\n===== THONG KE =====\n";
    cout << "Tong so khach hang: " << sum_customer << endl;
    cout << "Tong so tour:       " << sum_tour << endl;
    cout << "Tong doanh thu:     " << sum_price << endl;
}

//Cap nhat thong tin thong ke 
void statistics::update_thong_ke(BookingList& list) {
    int customer_count = 0;
    int tour_count = 0;
    double total_price = 0.0;

    BookingNode* p1 = list.head;
    while (p1 != NULL) {
        bool existed = false;
        BookingNode* p2 = list.head;
        while (p2 != p1) {
            if (p1->data.get_customer_id() == p2->data.get_customer_id()) {
                existed = true;
                break;
            }
            p2 = p2->next;
        }
        if (existed == false) customer_count++;
        p1 = p1->next;
    }

    tour_count = count_tour(list);

    BookingNode* p3 = list.head;
    while (p3 != NULL) {
        total_price += 0;
        p3 = p3->next;
    }

    sum_customer = customer_count;
    sum_tour = tour_count;
    sum_price = total_price;
}

//Xoa thong tin thong ke  
void statistics::delete_thong_ke() {
    sum_customer = 0;
    sum_tour = 0;
    sum_price = 0.0;
    cout << "Da xoa thanh cong.\n";
}

//Buble Sort theo id khach hang
void statistics::sort_customer(BookingList& list) {
    if (list.head == NULL || list.head->next == NULL) {
        cout << "Danh sach rong hoac chi co 1 phan tu, khong can sap xep.\n";
        return;
    }

    bool swapped;
    BookingNode* p;
    BookingNode* lastSorted = NULL;

    do {
        swapped = false;
        p = list.head;

        while (p->next != lastSorted) {
            if (p->data.get_customer_id() > p->next->data.get_customer_id()) {
                Booking temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = true;
            }
            p = p->next;
        }
        lastSorted = p;
    } while (swapped);

    cout << "Da sap xep danh sach booking theo id khach hang.\n";
}

//Buble Sort theo id tour 
void statistics::sort_tour(BookingList& list) {
    if (list.head == NULL || list.head->next == NULL) {
        cout << "Danh sach rong hoac chi co 1 phan tu, khong can sap xep.\n";
        return;
    }

    bool swapped;
    BookingNode* p;
    BookingNode* lastSorted = NULL;

    do {
        swapped = false;
        p = list.head;

        while (p->next != lastSorted) {
            if (p->data.get_tour_id() > p->next->data.get_tour_id()) {
                Booking temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = true;
            }
            p = p->next;
        }
        lastSorted = p;
    } while (swapped);

    cout << "Da sap xep danh sach booking theo id tour.\n";
}

//Luu file thong ke  
void statistics::save_file_thong_ke() {
    ofstream file("thongke.txt");

    if (!file) {
        cout << "Khong the mo file de luu thong ke.\n";
        return;
    }

    file << "===== THONG KE =====\n";
    file << "Tong so khach hang: " << sum_customer << endl;
    file << "Tong so tour:       " << sum_tour << endl;
    file << "Tong doanh thu:     " << sum_price;

    file.close(); 
    cout << "Da luu thong tin thong ke vao file thongke.txt.\n";
}

//Tim kiem 
void statistics::search(const BookingList& list) {
	if (list.head == NULL) {
        cout << "Danh sach rong, khong the tim kiem.\n";
        return;
    }

    int choice;
    cout << "\n===== TIM KIEM =====\n";
    cout << "1. Theo ma khach hang\n";
    cout << "2. Theo ma tour\n";
    cout << "3. Theo ngay dat tour\n";
    cout << "Chon chuc nang: ";
    cin >> choice;

    cin.ignore();

    if (choice == 1) {
        string customer_id;
        cout << "Nhap ma khach hang can tim: ";
        getline(cin, customer_id);

        int count = 0;
        double total = 0.0;
        BookingNode* p = list.head;

        cout << "\n--- Danh sach booking cua khach hang " << customer_id << " ---\n";
        while (p != NULL) {
            if (p->data.get_customer_id() == customer_id) {
                cout << "Booking ID: " << p->data.get_booking_id()
                     << "Tour: " << p->data.get_tour_id()
                     << "Ngay: " << p->data.get_booking_date() << endl;
                total += 0;
                count++;
            }
            p = p->next;
        }

        if (count == 0)
            cout << "Khong tim thay khach hang nay trong danh sach.\n";
        else {
            cout << "\nTong so booking: " << count << endl;
            cout << "Tong tien da chi: " << total << endl;
        }
    }

    else if (choice == 2) {
        string tour_id;
        cout << "Nhap ma tour can tim: ";
        getline(cin, tour_id);

        int count = 0;
        double total = 0.0;
        BookingNode* p = list.head;

        cout << "\n--- Danh sach booking cua tour " << tour_id << " ---\n";
        while (p != NULL) {
            if (p->data.get_tour_id() == tour_id) {
                cout << "Booking ID: " << p->data.get_booking_id()
                     << "Khach hang: " << p->data.get_customer_id()
                     << "Ngay: " << p->data.get_booking_date() << endl;
                total += 0; //Con thieu  
                count++;
            }
            p = p->next;
        }

        if (count == 0)
            cout << "Khong tim thay tour nay trong danh sach.\n";
        else {
            cout << "\nTong so booking: " << count << endl;
            cout << "Tong doanh thu: " << total << endl;
        }
    }

    else if (choice == 3) {
        CDate date;
        cout << "Nhap ngay can tim (dd mm yyyy): ";
        int d, m, y;
        cin >> d >> m >> y;
        date.set_day(d);
        date.set_month(m);
        date.set_year(y);

        int count = 0;
        double total = 0.0;
        BookingNode* p = list.head;

        cout << "\n--- Danh sach booking trong ngay "
             << d << "/" << m << "/" << y << " ---\n";
        while (p != NULL) {
            CDate cd = p->data.get_booking_date();
            if (cd.get_day() == d && cd.get_month() == m && cd.get_year() == y) {
                cout << "Booking ID: " << p->data.get_booking_id()
                     << "Khach hang: " << p->data.get_customer_id()
                     << "Tour: " << p->data.get_tour_id() << endl;
                total += 0; //Con thieu  
                count++;
            }
            p = p->next;
        }

        if (count == 0)
            cout << "Khong co booking nao trong ngay nay.\n";
        else {
            cout << "\nTong so booking: " << count << endl;
            cout << "Tong doanh thu: " << total << endl;
        }
    }

    else {
        cout << "Lua chon khong hop le.\n";
    }    
}


void statistics::thong_ke_theo_ngay(BookingList& list, const CDate& date) {
    cout << "\n=== THONG KE THEO NGAY ===\n";
    int count = 0;
    double total = 0.0;

    BookingNode* p = list.head;
    while (p != NULL) {
        CDate d = p->data.get_booking_date();
        if (d.get_day() == date.get_day() &&
            d.get_month() == date.get_month() &&
            d.get_year() == date.get_year()) {

            cout << "Booking ID: " << p->data.get_booking_id()
                 << "Khach hang: " << p->data.get_customer_id()
                 << "Tour: " << p->data.get_tour_id() << endl;
			
			total += 0; //Con thieu  
            count++;
        }
        p = p->next;
    }

    cout << "Tong so booking ngay nay: " << count << endl;
    cout << "Tong doanh thu: " << total << endl;
}

void statistics::thong_ke_theo_tour(BookingList& list, const string& tour_id) {
    cout << "\n=== THONG KE THEO TOUR ===\n";
    int count = 0;
    double total = 0.0;

    BookingNode* p = list.head;
    while (p != NULL) {
        if (p->data.get_tour_id() == tour_id) {
            cout << "Booking ID: " << p->data.get_booking_id()
                 << "Khach hang: " << p->data.get_customer_id()
                 << "Ngay: " << p->data.get_booking_date() << endl;
                 
        	total += 0; //Con thieu  
            count++;
        }
        p = p->next;
    }

    cout << "Tong so booking cua tour nay: " << count << endl;
    cout << "Tong doanh thu: " << total << endl;
}

void statistics::thong_ke_theo_khach_hang(BookingList& list, const string& customer_id) {
    cout << "\n=== THONG KE THEO KHACH HANG ===\n";
    int count = 0;
    double total = 0.0;

    BookingNode* p = list.head;
    while (p != NULL) {
        if (p->data.get_customer_id() == customer_id) {
            cout << "Booking ID: " << p->data.get_booking_id()
                 << "Tour: " << p->data.get_tour_id()
                 << "Ngay: " << p->data.get_booking_date() << endl;
            
            total += 0; //Con thieu  
            count++;
        }
        p = p->next;
    }

    cout << "Tong so booking cua khach hang: " << count << endl;
    cout << "Tong tien da chi: " << total << endl;
}
