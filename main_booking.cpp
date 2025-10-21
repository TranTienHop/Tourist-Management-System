#include"booking.h"

	int main() {
		BookingList booking_list;
		CustomerList customer_list;
		AccommodationList accommodation_list;
		VehicleList vehicle_list;
		PaymentList payment_list;
		TourList tour_list;
		TourGuideList tour_guide_list;

		int choice;
		Booking b;
		string booking_id;
		CDate new_date;

		do {
			cout << "\n===== QUAN LY BOOKING =====\n";
			cout << "1. Them booking\n";
			cout << "2. Chinh sua booking theo ID\n";
			cout << "3. Xoa booking theo ID\n";
			cout << "4. Tim booking theo ID\n";
			cout << "5. Cap nhat ngay booking theo ID\n";
			cout << "6. Sap xep booking theo ngay\n";
			cout << "7. Luu tat ca booking vao file\n";
			cout << "0. Thoat\n";
			cout << "Chon chuc nang: ";
			cin >> choice;
			cin.ignore();

			switch (choice) {
			case 1:
				b.input_booking(customer_list, accommodation_list, vehicle_list,
					payment_list, tour_list, tour_guide_list);
				booking_list.addBooking(b);
				break;
			case 2:
				cout << "Nhap booking ID can chinh sua: ";
				getline(cin, booking_id);
				booking_list.editBooking(booking_id);
				break;
			case 3:
				cout << "Nhap booking ID can xoa: ";
				getline(cin, booking_id);
				booking_list.deleteBooking(booking_id);
				break;
			case 4:
				cout << "Nhap booking ID can tim: ";
				getline(cin, booking_id);
				{
					Booking* found = booking_list.searchBooking(booking_id);
					if (found != nullptr)
						found->print_booking();
					else
						cout << "Khong tim thay booking.\n";
				}
				break;
			case 5:
				cout << "Nhap booking ID can cap nhat ngay: ";
				getline(cin, booking_id);
				cout << "Nhap ngay booking moi: ";
				cin >> new_date;
				cin.ignore();
				booking_list.updateBookingDate(booking_id, new_date);
				break;
			case 6:
				booking_list.sortBookingsByDate();
				break;
			case 7:
				booking_list.saveAllBookings("booking.txt");
				break;
			case 0:
				cout << "Thoat chuong trinh.\n";
				break;
			default:
				cout << "Lua chon khong hop le, vui long thu lai.\n";
			}
		} while (choice != 0);

		return 0;
	}
	
