#include"booking.h"
Booking::Booking() {
	this->booking_id = "A000";
	this->booking_date = CDate();
	this->customer_id = "A000";
	this->accommodation_id = "A000";
	this->vehicle_id = "A000";
	this->payment_id = "A000";
	this->tour_id = "A000";
	this->tour_guide_id = "A000";
}

Booking::Booking(string booking_id, CDate booking_date, string customer_id, string accommodation_id,
	string vehicle_id, string payment_id, string tour_id, string tour_guide_id) {
	this->booking_id = booking_id;
	this->booking_date = booking_date;
	this->customer_id = customer_id;
	this->accommodation_id = accommodation_id;
	this->vehicle_id = vehicle_id;
	this->payment_id = payment_id;
	this->tour_id = tour_id;
	this->tour_guide_id = tour_guide_id;
}

Booking::Booking(const Booking& b) {
	this->booking_id = b.booking_id;
	this->booking_date = b.booking_date;
	this->customer_id = b.customer_id;
	this->accommodation_id = b.accommodation_id;
	this->vehicle_id = b.vehicle_id;
	this->payment_id = b.payment_id;
	this->tour_id = b.tour_id;
	this->tour_guide_id = b.tour_guide_id;
}

Booking::~Booking() { }
void Booking::set_booking_date(CDate booking_date) { this->booking_date = booking_date; }
void Booking::set_booking_id(string booking_id) { this->booking_id = booking_id; }
void Booking::set_customer_id(string customer_id) { this->customer_id = customer_id; }
void Booking::set_accommodation_id(string accommodation_id) { this->accommodation_id = accommodation_id; }
void Booking::set_vehicle_id(string vehicle_id) { this->vehicle_id = vehicle_id; }
void Booking::set_payment_id(string payment_id) { this->payment_id = payment_id; }
void Booking::set_tour_id(string tour_id) { this->tour_id = tour_id; }
void Booking::set_tour_guide_id(string tour_guide_id) { this->tour_guide_id = tour_guide_id; }

CDate Booking::get_booking_date() { return booking_date; }
string Booking::get_booking_id() { return booking_id; }
string Booking::get_customer_id() { return customer_id; }
string Booking::get_accommodation_id() { return accommodation_id; }
string Booking::get_vehicle_id() { return vehicle_id; }
string Booking::get_payment_id() { return payment_id; }
string Booking::get_tour_id() { return tour_id; }
string Booking::get_tour_guide_id() { return tour_guide_id; }

void Booking::input_booking(CustomerList& customer_list,
	AccommodationList& accommodation_list,
	VehicleList& vehicle_list,
	PaymentList& payment_list,
	TourList& tour_list,
	TourGuideList& tour_guide_list) {
	cout << "Enter booking ID: ";
	getline(cin, booking_id);

	cout << "Enter booking date: ";
	cin >> booking_date;

	// Lấy ID từ danh sách có sẵn
	customer_id = customer_list.select_customer_id();
	accommodation_id = accommodation_list.select_accommodation_id();
	vehicle_id = vehicle_list.select_vehicle_id();
	payment_id = payment_list.select_payment_id();
	tour_id = tour_list.select_tour_id();
	tour_guide_id = tour_guide_list.select_tour_guide_id();

	cout << "Booking input completed.\n";
}
void Booking::print_booking() {
	cout << "Booking ID: " << booking_id << "\n";
	cout << "Booking date: " << booking_date << "\n"; // CDate đã overload <<
	cout << "Customer ID: " << customer_id << "\n";
	cout << "Accommodation ID: " << accommodation_id << "\n";
	cout << "Vehicle ID: " << vehicle_id << "\n";
	cout << "Payment ID: " << payment_id << "\n";
	cout << "Tour ID: " << tour_id << "\n";
	cout << "Tour Guide ID: " << tour_guide_id << "\n";
}

void Booking::edit_booking() {
	int choice;
	do {
		cout << "\nDang chinh sua booking: " << booking_id << "\n";
		cout << "1. Chinh sua ngay booking\n";
		cout << "2. Chinh sua ID khach hang\n";
		cout << "3. Chinh sua ID luu tru\n";
		cout << "4. Chinh sua ID phuong tien\n";
		cout << "5. Chinh sua ID thanh toan\n";
		cout << "6. Chinh sua ID tour\n";
		cout << "7. Chinh sua ID huong dan vien\n";
		cout << "0. Thoat menu chinh sua\n";
		cout << "Chon chuc nang: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "Nhap ngay booking moi: ";
			cin >> booking_date;
			break;
		case 2:
			cout << "Nhap ID khach hang moi: ";
			getline(cin, customer_id);
			break;
		case 3:
			cout << "Nhap ID luu tru moi: ";
			getline(cin, accommodation_id);
			break;
		case 4:
			cout << "Nhap ID phuong tien moi: ";
			getline(cin, vehicle_id);
			break;
		case 5:
			cout << "Nhap ID thanh toan moi: ";
			getline(cin, payment_id);
			break;
		case 6:
			cout << "Nhap ID tour moi: ";
			getline(cin, tour_id);
			break;
		case 7:
			cout << "Nhap ID huong dan vien moi: ";
			getline(cin, tour_guide_id);
			break;
		case 0:
			cout << "Thoat menu chinh sua.\n";
			break;
		default:
			cout << "Lua chon khong hop le, vui long thu lai.\n";
		}
	} while (choice != 0);
}

void Booking::save_booking() {
	ofstream out("booking.txt", ios::app);  // mở file ở chế độ append
	if (!out.is_open()) {
		cout << "Khong mo duoc file booking.txt de luu.\n";
		return;
	}

	out << booking_id << ";"
		<< booking_date.get_day() << "/" << booking_date.get_month() << "/" << booking_date.get_year() << ";"
		<< customer_id << ";"
		<< accommodation_id << ";"
		<< vehicle_id << ";"
		<< payment_id << ";"
		<< tour_id << ";"
		<< tour_guide_id << "\n";

	out.close();
	cout << "Luu booking thanh cong.\n";
}

void BookingList::addBooking(const Booking& b) {
	BookingNode* newNode = new BookingNode;
	newNode->data = b;    // copy booking
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;   // danh sach rong
	}
	else {
		BookingNode* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;  // thêm vào cuối danh sách
	}

	cout << "Booking da duoc them vao danh sach.\n";
}
void BookingList::editBooking(string booking_id) {
	if (head == nullptr) {
		cout << "Danh sach booking rong.\n";
		return;
	}

	BookingNode* temp = head;
	while (temp != nullptr) {
		if (temp->data.get_booking_id() == booking_id) {
			temp->data.edit_booking();  // goi edit_booking() cua Booking
			cout << "Booking da duoc cap nhat.\n";
			return;
		}
		temp = temp->next;
	}

	cout << "Khong tim thay booking voi ID: " << booking_id << "\n";
}
void BookingList::deleteBooking(string booking_id) {
	if (head == nullptr) {
		cout << "Danh sach booking rong.\n";
		return;
	}

	BookingNode* temp = head;
	BookingNode* prev = nullptr;

	while (temp != nullptr && temp->data.get_booking_id() != booking_id) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		cout << "Khong tim thay booking voi ID: " << booking_id << "\n";
		return;
	}

	if (prev == nullptr) { // xoa node dau
		head = head->next;
	}
	else {
		prev->next = temp->next;
	}

	delete temp;
	cout << "Booking da duoc xoa.\n";
}
Booking* BookingList::searchBooking(string booking_id) {
	BookingNode* temp = head;
	while (temp != nullptr) {
		if (temp->data.get_booking_id() == booking_id)
			return &temp->data; // tra ve con tro den booking
		temp = temp->next;
	}
	return nullptr; // khong tim thay
}
void BookingList::saveAllBookings(const string& filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		cout << "Khong mo duoc file de luu.\n";
		return;
	}

	BookingNode* temp = head;
	while (temp != nullptr) {
		out << temp->data.get_booking_id() << ";"
			<< temp->data.get_booking_date().get_day() << "/"
			<< temp->data.get_booking_date().get_month() << "/"
			<< temp->data.get_booking_date().get_year() << ";"
			<< temp->data.get_customer_id() << ";"
			<< temp->data.get_accommodation_id() << ";"
			<< temp->data.get_vehicle_id() << ";"
			<< temp->data.get_payment_id() << ";"
			<< temp->data.get_tour_id() << ";"
			<< temp->data.get_tour_guide_id() << "\n";
		temp = temp->next;
	}

	out.close();
	cout << "Da luu tat ca booking vao file.\n";
}
void BookingList::updateBookingDate(string booking_id, CDate new_date) {
	Booking* b = searchBooking(booking_id);
	if (b != nullptr) {
		b->set_booking_date(new_date);
		cout << "Ngay booking da duoc cap nhat.\n";
	}
	else {
		cout << "Khong tim thay booking voi ID: " << booking_id << "\n";
	}
}
void BookingList::sortBookingsByDate() {
	if (head == nullptr || head->next == nullptr)
		return;

	for (BookingNode* i = head; i != nullptr; i = i->next) {
		for (BookingNode* j = i->next; j != nullptr; j = j->next) {
			if (i->data.get_booking_date() > j->data.get_booking_date()) {
				swap(i->data, j->data);
			}
		}
	}

	cout << "Da sap xep booking theo ngay.\n";
}