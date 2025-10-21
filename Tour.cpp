#include "Tour.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


Tour::Tour() {
    tour_id = "";
    tour_destination = "";
    tour_date = CDate();
    tour_price_per_person = 0;
}

Tour::Tour(string id, string dest, CDate date, float price) {
    tour_id = id;
    tour_destination = dest;
    tour_date = date;
    tour_price_per_person = price;
}

Tour::Tour(const Tour& t) {
    tour_id = t.tour_id;
    tour_destination = t.tour_destination;
    tour_date = t.tour_date;
    tour_price_per_person = t.tour_price_per_person;
}

Tour::~Tour() {}

void Tour::input_tour() {
    cout << "\nNhap ma tour: ";
    cin >> tour_id;
    cin.ignore();
    cout << "Nhap diem den: ";
    getline(cin, tour_destination);
    cout << "Nhap ngay khoi hanh:\n";
    cin >> tour_date;
    cout << "Nhap gia 1 nguoi: ";
    cin >> tour_price_per_person;
}

void Tour::edit_tour() {
    cout << "\n--- Chinh sua tour ---\n";
    cout << "Nhap diem den moi: ";
    cin.ignore();
    getline(cin, tour_destination);
    cout << "Nhap ngay khoi hanh moi:\n";
    cin >> tour_date;
    cout << "Nhap gia moi: ";
    cin >> tour_price_per_person;
}

void Tour::print_tour() const {
    cout << left << setw(10) << tour_id
         << setw(20) << tour_destination
         << setw(15);
    cout << tour_date;
    cout << setw(10) << tour_price_per_person << " VND" << endl;
}

void Tour::set_tour_id(string id) { tour_id = id; }
void Tour::set_tour_destination(string d) { tour_destination = d; }
void Tour::set_tour_date(CDate d) { tour_date = d; }
void Tour::set_tour_price_per_person(float p) { tour_price_per_person = p; }

string Tour::get_tour_id() const { return tour_id; }
string Tour::get_tour_destination() const { return tour_destination; }
CDate Tour::get_tour_date() const { return tour_date; }
float Tour::get_price_per_person() const { return tour_price_per_person; }


TourList::TourList() {
    head = nullptr;
}

TourList::~TourList() {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void TourList::add_tour() {
    Tour t;
    t.input_tour();
    Node* newNode = new Node{ t, nullptr };

    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void TourList::delete_tour(string id) {
    if (!head) return;
    if (head->data.get_tour_id() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr && curr->data.get_tour_id() != id) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

void TourList::update_tour(string id) {
    Node* found = search_tour_by_id(id);
    if (found) {
        found->data.edit_tour();
        cout << "Cap nhat thanh cong!\n";
    } else cout << "Khong tim thay tour!\n";
}

Node* TourList::search_tour_by_id(string id) {
    Node* temp = head;
    while (temp) {
        if (temp->data.get_tour_id() == id)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void TourList::sort_by_price() {
    for (Node* i = head; i != nullptr; i = i->next)
        for (Node* j = i->next; j != nullptr; j = j->next)
            if (i->data.get_price_per_person() > j->data.get_price_per_person())
                swap(i->data, j->data);
}

void TourList::print_all_tours() const {
    cout << "\n=== DANH SACH TOUR ===\n";
    Node* temp = head;
    while (temp) {
        temp->data.print_tour();
        temp = temp->next;
    }
}

void TourList::save_to_file() {
    ofstream fout("tour.txt");
    Node* temp = head;
    while (temp) {
        fout << temp->data.get_tour_id() << ";"
             << temp->data.get_tour_destination() << ";"
             << temp->data.get_tour_date().get_day() << "/"
             << temp->data.get_tour_date().get_month() << "/"
             << temp->data.get_tour_date().get_year() << ";"
             << temp->data.get_price_per_person() << endl;
        temp = temp->next;
    }
    fout.close();
    cout << "Da luu danh sach vao file tour.txt\n";
}

void TourList::load_from_file() {
    ifstream fin("tour.txt");
    if (!fin) {
        cout << "Khong tim thay file tour.txt\n";
        return;
    }
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string id, dest, dateStr, priceStr;
        getline(ss, id, ';');
        getline(ss, dest, ';');
        getline(ss, dateStr, ';');
        getline(ss, priceStr, ';');
        CDate d;
        d.parse_date(dateStr);
        float price = stof(priceStr);
        Tour t(id, dest, d, price);
        Node* newNode = new Node{ t, nullptr };
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    fin.close();
    cout << "Da tai danh sach tour tu file!\n";
}


