#include "Tour.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <utility>

using namespace std;

Tour::Tour()
    : tour_id(),
      tour_destination(),
      tour_date(),
      tour_price_per_person(0.0f) {}

Tour::Tour(const string& id, const string& destination, const CDate& date, float price)
    : tour_id(id),
      tour_destination(destination),
      tour_date(date),
      tour_price_per_person(price) {}

Tour::Tour(const Tour& other) = default;

Tour::~Tour() = default;

void Tour::input_tour() {
    cout << "\nNhap ma tour: ";
    getline(cin, tour_id);

    cout << "Nhap diem den: ";
    getline(cin, tour_destination);

    cout << "Nhap ngay khoi hanh:\n";
    cin >> tour_date;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap gia 1 nguoi: ";
    cin >> tour_price_per_person;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Tour::edit_tour() {
    cout << "\n--- Chinh sua tour ---\n";

    cout << "Nhap diem den moi: ";
    getline(cin, tour_destination);

    cout << "Nhap ngay khoi hanh moi:\n";
    cin >> tour_date;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap gia moi: ";
    cin >> tour_price_per_person;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Tour::print_tour() const {
    cout << left << setw(10) << tour_id
         << setw(20) << tour_destination
         << setw(15);
    cout << tour_date;
    cout << setw(10) << tour_price_per_person << " VND" << endl;
}

void Tour::save_tour() const {
    ofstream out("tour.txt", ios::app);
    if (!out.is_open()) {
        cout << "Khong mo duoc file tour.txt.\n";
        return;
    }

    out << tour_id << ';'
        << tour_destination << ';'
        << tour_date.get_day() << '/'
        << tour_date.get_month() << '/'
        << tour_date.get_year() << ';'
        << tour_price_per_person << '\n';

    cout << "Da luu tour vao file.\n";
}

void Tour::set_tour_id(const string& id) {
    tour_id = id;
}

void Tour::set_tour_destination(const string& destination) {
    tour_destination = destination;
}

void Tour::set_tour_date(const CDate& date) {
    tour_date = date;
}

void Tour::set_tour_price_per_person(float price) {
    tour_price_per_person = price;
}

string Tour::get_tour_id() const {
    return tour_id;
}

string Tour::get_tour_destination() const {
    return tour_destination;
}

CDate Tour::get_tour_date() const {
    return tour_date;
}

float Tour::get_price_per_person() const {
    return tour_price_per_person;
}

TourList::TourList()
    : head(nullptr) {}

TourList::~TourList() {
    TourNode* current = head;
    while (current != nullptr) {
        TourNode* next = current->next;
        delete current;
        current = next;
    }
}

void TourList::add_tour() {
    Tour tour;
    if (cin.peek() == '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    tour.input_tour();

    TourNode* new_node = new TourNode{tour, nullptr};
    if (head == nullptr) {
        head = new_node;
    } else {
        TourNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = new_node;
    }
}

void TourList::delete_tour(const string& id) {
    if (head == nullptr) {
        return;
    }

    if (head->data.get_tour_id() == id) {
        TourNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    TourNode* previous = head;
    TourNode* current = head->next;
    while (current != nullptr && current->data.get_tour_id() != id) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        previous->next = current->next;
        delete current;
    }
}

void TourList::update_tour(const string& id) {
    TourNode* found = search_tour_by_id(id);
    if (found != nullptr) {
        found->data.edit_tour();
        cout << "Cap nhat thanh cong!\n";
    } else {
        cout << "Khong tim thay tour!\n";
    }
}

TourNode* TourList::search_tour_by_id(const string& id) {
    TourNode* current = head;
    while (current != nullptr) {
        if (current->data.get_tour_id() == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void TourList::sort_by_price() {
    for (TourNode* i = head; i != nullptr; i = i->next) {
        for (TourNode* j = i->next; j != nullptr; j = j->next) {
            if (i->data.get_price_per_person() > j->data.get_price_per_person()) {
                swap(i->data, j->data);
            }
        }
    }
}

void TourList::print_all_tours() const {
    cout << "\n=== DANH SACH TOUR ===\n";
    TourNode* current = head;
    while (current != nullptr) {
        current->data.print_tour();
        current = current->next;
    }
}

void TourList::save_to_file() const {
    ofstream out("tour.txt");
    if (!out.is_open()) {
        cout << "Khong mo duoc file tour.txt.\n";
        return;
    }

    TourNode* current = head;
    while (current != nullptr) {
        out << current->data.get_tour_id() << ';'
            << current->data.get_tour_destination() << ';'
            << current->data.get_tour_date().get_day() << '/'
            << current->data.get_tour_date().get_month() << '/'
            << current->data.get_tour_date().get_year() << ';'
            << current->data.get_price_per_person() << '\n';
        current = current->next;
    }

    cout << "Da luu danh sach vao file tour.txt\n";
}

void TourList::load_from_file() {
    ifstream in("tour.txt");
    if (!in.is_open()) {
        cout << "Khong tim thay file tour.txt\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string id;
        string destination;
        string date_string;
        string price_string;

        getline(ss, id, ';');
        getline(ss, destination, ';');
        getline(ss, date_string, ';');
        getline(ss, price_string, ';');

        CDate date;
        date.parse_date(date_string);
        float price = stof(price_string);

        Tour tour(id, destination, date, price);
        TourNode* new_node = new TourNode{tour, nullptr};

        if (head == nullptr) {
            head = new_node;
        } else {
            TourNode* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new_node;
        }
    }

    cout << "Da tai danh sach tour tu file!\n";
}


