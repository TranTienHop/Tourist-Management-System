#include "booking.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>

Booking::Booking()
    : booking_id("A000"),
      booking_date(),
      customer_id("A000"),
      accommodation_id("A000"),
      vehicle_id("A000"),
      payment_id("A000"),
      tour_id("A000"),
      tour_guide_id("A000") {}

Booking::Booking(const std::string& booking_id,
                 const CDate& booking_date,
                 const std::string& customer_id,
                 const std::string& accommodation_id,
                 const std::string& vehicle_id,
                 const std::string& payment_id,
                 const std::string& tour_id,
                 const std::string& tour_guide_id)
    : booking_id(booking_id),
      booking_date(booking_date),
      customer_id(customer_id),
      accommodation_id(accommodation_id),
      vehicle_id(vehicle_id),
      payment_id(payment_id),
      tour_id(tour_id),
      tour_guide_id(tour_guide_id) {}

Booking::Booking(const Booking& other) = default;

Booking::~Booking() = default;

void Booking::set_booking_date(const CDate& date) { booking_date = date; }

void Booking::set_booking_id(const std::string& id) { booking_id = id; }

void Booking::set_customer_id(const std::string& customer_id_value) {
    customer_id = customer_id_value;
}

void Booking::set_accommodation_id(const std::string& accommodation_id_value) {
    accommodation_id = accommodation_id_value;
}

void Booking::set_vehicle_id(const std::string& vehicle_id_value) {
    vehicle_id = vehicle_id_value;
}

void Booking::set_payment_id(const std::string& payment_id_value) {
    payment_id = payment_id_value;
}

void Booking::set_tour_id(const std::string& tour_id_value) { tour_id = tour_id_value; }

void Booking::set_tour_guide_id(const std::string& tour_guide_id_value) {
    tour_guide_id = tour_guide_id_value;
}

CDate Booking::get_booking_date() const { return booking_date; }

std::string Booking::get_booking_id() const { return booking_id; }

std::string Booking::get_customer_id() const { return customer_id; }

std::string Booking::get_accommodation_id() const { return accommodation_id; }

std::string Booking::get_vehicle_id() const { return vehicle_id; }

std::string Booking::get_payment_id() const { return payment_id; }

std::string Booking::get_tour_id() const { return tour_id; }

std::string Booking::get_tour_guide_id() const { return tour_guide_id; }

void Booking::input_booking(CustomerList& customer_list,
                            AccommodationList& accommodation_list,
                            VehicleList& vehicle_list,
                            PaymentList& payment_list,
                            TourList& tour_list,
                            TourGuideList& tour_guide_list) {
    std::cout << "Enter booking ID: ";
    std::getline(std::cin, booking_id);

    std::cout << "Enter booking date: ";
    std::cin >> booking_date;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    customer_id = customer_list.select_customer_id();
    accommodation_id = accommodation_list.select_accommodation_id();
    vehicle_id = vehicle_list.select_vehicle_id();
    payment_id = payment_list.select_payment_id();
    tour_id = tour_list.select_tour_id();
    tour_guide_id = tour_guide_list.select_tour_guide_id();

    std::cout << "Booking input completed.\n";
}

void Booking::print_booking() const {
    std::cout << "Booking ID: " << booking_id << '\n';
    std::cout << "Booking date: " << booking_date << '\n';
    std::cout << "Customer ID: " << customer_id << '\n';
    std::cout << "Accommodation ID: " << accommodation_id << '\n';
    std::cout << "Vehicle ID: " << vehicle_id << '\n';
    std::cout << "Payment ID: " << payment_id << '\n';
    std::cout << "Tour ID: " << tour_id << '\n';
    std::cout << "Tour Guide ID: " << tour_guide_id << '\n';
}

void Booking::edit_booking() {
    int choice = -1;
    do {
        std::cout << "\nDang chinh sua booking: " << booking_id << '\n';
        std::cout << "1. Chinh sua ngay booking\n";
        std::cout << "2. Chinh sua ID khach hang\n";
        std::cout << "3. Chinh sua ID luu tru\n";
        std::cout << "4. Chinh sua ID phuong tien\n";
        std::cout << "5. Chinh sua ID thanh toan\n";
        std::cout << "6. Chinh sua ID tour\n";
        std::cout << "7. Chinh sua ID huong dan vien\n";
        std::cout << "0. Thoat menu chinh sua\n";
        std::cout << "Chon chuc nang: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            std::cout << "Nhap ngay booking moi: ";
            std::cin >> booking_date;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        case 2:
            std::cout << "Nhap ID khach hang moi: ";
            std::getline(std::cin, customer_id);
            break;
        case 3:
            std::cout << "Nhap ID luu tru moi: ";
            std::getline(std::cin, accommodation_id);
            break;
        case 4:
            std::cout << "Nhap ID phuong tien moi: ";
            std::getline(std::cin, vehicle_id);
            break;
        case 5:
            std::cout << "Nhap ID thanh toan moi: ";
            std::getline(std::cin, payment_id);
            break;
        case 6:
            std::cout << "Nhap ID tour moi: ";
            std::getline(std::cin, tour_id);
            break;
        case 7:
            std::cout << "Nhap ID huong dan vien moi: ";
            std::getline(std::cin, tour_guide_id);
            break;
        case 0:
            std::cout << "Thoat menu chinh sua.\n";
            break;
        default:
            std::cout << "Lua chon khong hop le, vui long thu lai.\n";
            break;
        }
    } while (choice != 0);
}

void Booking::save_booking() const {
    std::ofstream out("booking.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "Khong mo duoc file booking.txt de luu.\n";
        return;
    }

    out << booking_id << ';'
        << booking_date.get_day() << '/' << booking_date.get_month() << '/' << booking_date.get_year() << ';'
        << customer_id << ';'
        << accommodation_id << ';'
        << vehicle_id << ';'
        << payment_id << ';'
        << tour_id << ';'
        << tour_guide_id << '\n';

    out.close();
    std::cout << "Luu booking thanh cong.\n";
}

BookingList::BookingList() : head(nullptr) {}

BookingList::~BookingList() {
    BookingNode* current = head;
    while (current != nullptr) {
        BookingNode* next = current->next;
        delete current;
        current = next;
    }
}

void BookingList::add_booking(const Booking& booking) {
    auto* new_node = new BookingNode{booking, nullptr};

    if (head == nullptr) {
        head = new_node;
    } else {
        BookingNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    std::cout << "Booking da duoc them vao danh sach.\n";
}

void BookingList::edit_booking(const std::string& booking_id) {
    if (head == nullptr) {
        std::cout << "Danh sach booking rong.\n";
        return;
    }

    BookingNode* temp = head;
    while (temp != nullptr) {
        if (temp->data.get_booking_id() == booking_id) {
            temp->data.edit_booking();
            std::cout << "Booking da duoc cap nhat.\n";
            return;
        }
        temp = temp->next;
    }

    std::cout << "Khong tim thay booking voi ID: " << booking_id << '\n';
}

void BookingList::delete_booking(const std::string& booking_id) {
    if (head == nullptr) {
        std::cout << "Danh sach booking rong.\n";
        return;
    }

    BookingNode* temp = head;
    BookingNode* prev = nullptr;

    while (temp != nullptr && temp->data.get_booking_id() != booking_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Khong tim thay booking voi ID: " << booking_id << '\n';
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    std::cout << "Booking da duoc xoa.\n";
}

Booking* BookingList::search_booking(const std::string& booking_id) {
    BookingNode* temp = head;
    while (temp != nullptr) {
        if (temp->data.get_booking_id() == booking_id) {
            return &temp->data;
        }
        temp = temp->next;
    }
    return nullptr;
}

void BookingList::save_bookings(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cout << "Khong mo duoc file de luu.\n";
        return;
    }

    BookingNode* temp = head;
    while (temp != nullptr) {
        out << temp->data.get_booking_id() << ';'
            << temp->data.get_booking_date().get_day() << '/'
            << temp->data.get_booking_date().get_month() << '/'
            << temp->data.get_booking_date().get_year() << ';'
            << temp->data.get_customer_id() << ';'
            << temp->data.get_accommodation_id() << ';'
            << temp->data.get_vehicle_id() << ';'
            << temp->data.get_payment_id() << ';'
            << temp->data.get_tour_id() << ';'
            << temp->data.get_tour_guide_id() << '\n';
        temp = temp->next;
    }

    out.close();
    std::cout << "Da luu tat ca booking vao file.\n";
}

void BookingList::update_booking_date(const std::string& booking_id, const CDate& new_date) {
    Booking* booking = search_booking(booking_id);
    if (booking != nullptr) {
        booking->set_booking_date(new_date);
        std::cout << "Ngay booking da duoc cap nhat.\n";
    } else {
        std::cout << "Khong tim thay booking voi ID: " << booking_id << '\n';
    }
}

void BookingList::sort_bookings_by_date() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    for (BookingNode* i = head; i != nullptr; i = i->next) {
        for (BookingNode* j = i->next; j != nullptr; j = j->next) {
            if (i->data.get_booking_date() > j->data.get_booking_date()) {
                std::swap(i->data, j->data);
            }
        }
    }

    std::cout << "Da sap xep booking theo ngay.\n";
}

