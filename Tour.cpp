#include "Tour.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <utility>

Tour::Tour()
    : tour_id(),
      tour_destination(),
      tour_date(),
      tour_price_per_person(0.0f) {}

Tour::Tour(const std::string& id, const std::string& destination, const CDate& date, float price)
    : tour_id(id),
      tour_destination(destination),
      tour_date(date),
      tour_price_per_person(price) {}

Tour::Tour(const Tour& other) = default;

Tour::~Tour() = default;

void Tour::input_tour() {
    std::cout << "\nNhap ma tour: ";
    std::getline(std::cin, tour_id);

    std::cout << "Nhap diem den: ";
    std::getline(std::cin, tour_destination);

    std::cout << "Nhap ngay khoi hanh:\n";
    std::cin >> tour_date;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Nhap gia 1 nguoi: ";
    std::cin >> tour_price_per_person;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Tour::edit_tour() {
    std::cout << "\n--- Chinh sua tour ---\n";

    std::cout << "Nhap diem den moi: ";
    std::getline(std::cin, tour_destination);

    std::cout << "Nhap ngay khoi hanh moi:\n";
    std::cin >> tour_date;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Nhap gia moi: ";
    std::cin >> tour_price_per_person;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Tour::print_tour() const {
    std::cout << std::left << std::setw(10) << tour_id
              << std::setw(20) << tour_destination
              << std::setw(15);
    std::cout << tour_date;
    std::cout << std::setw(10) << tour_price_per_person << " VND" << std::endl;
}

void Tour::save_tour() const {
    std::ofstream out("tour.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "Khong mo duoc file tour.txt.\n";
        return;
    }

    out << tour_id << ';'
        << tour_destination << ';'
        << tour_date.get_day() << '/'
        << tour_date.get_month() << '/'
        << tour_date.get_year() << ';'
        << tour_price_per_person << '\n';

    std::cout << "Da luu tour vao file.\n";
}

void Tour::set_tour_id(const std::string& id) {
    tour_id = id;
}

void Tour::set_tour_destination(const std::string& destination) {
    tour_destination = destination;
}

void Tour::set_tour_date(const CDate& date) {
    tour_date = date;
}

void Tour::set_tour_price_per_person(float price) {
    tour_price_per_person = price;
}

std::string Tour::get_tour_id() const {
    return tour_id;
}

std::string Tour::get_tour_destination() const {
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
    if (std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void TourList::delete_tour(const std::string& id) {
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

void TourList::update_tour(const std::string& id) {
    TourNode* found = search_tour_by_id(id);
    if (found != nullptr) {
        found->data.edit_tour();
        std::cout << "Cap nhat thanh cong!\n";
    } else {
        std::cout << "Khong tim thay tour!\n";
    }
}

TourNode* TourList::search_tour_by_id(const std::string& id) {
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
                std::swap(i->data, j->data);
            }
        }
    }
}

void TourList::print_all_tours() const {
    std::cout << "\n=== DANH SACH TOUR ===\n";
    TourNode* current = head;
    while (current != nullptr) {
        current->data.print_tour();
        current = current->next;
    }
}

void TourList::save_to_file() const {
    std::ofstream out("tour.txt");
    if (!out.is_open()) {
        std::cout << "Khong mo duoc file tour.txt.\n";
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

    std::cout << "Da luu danh sach vao file tour.txt\n";
}

void TourList::load_from_file() {
    std::ifstream in("tour.txt");
    if (!in.is_open()) {
        std::cout << "Khong tim thay file tour.txt\n";
        return;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string id;
        std::string destination;
        std::string date_string;
        std::string price_string;

        std::getline(ss, id, ';');
        std::getline(ss, destination, ';');
        std::getline(ss, date_string, ';');
        std::getline(ss, price_string, ';');

        CDate date;
        date.parse_date(date_string);
        float price = std::stof(price_string);

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

    std::cout << "Da tai danh sach tour tu file!\n";
}

