#include <string>
#include <fstream>
#include<iostream>
#include"CDate.h"
using namespace std;

struct BookingNode {
	Booking data;
	BookingNode* next;
};
class BookingList {
private:
	BookingNode* head;
public:
	BookingList();
	~BookingList();

	void add_booking(const Booking&);
	void edit_booking(string booking_id);
	void delete_booking(string booking_id);
	Booking* search_booking(string booking_id);
	void save_bookings(const string& filename);
	void update_date_booking(string booking_id, CDate new_date);
	//void _sort_Booking();
};
class  Booking {
private:
	string booking_id;           // Input
	CDate  booking_date;         // Input
	string customer_id;          // lấy data từ class Customer
	string accommodation_id;     // lấy data từ class Accommodation
	string vehicle_id;           // lấy data từ class Vehicle
	string payment_id;           // lấy data từ class Payment
	string tour_id;              // lấy data từ class Tour
	string tour_guide_id;        // lấy data từ class TourGuide

public:
	Booking();
	Booking(string, CDate, string, string, string, string, string, string);
	Booking(const Booking&);
	~Booking();

	// 7 hàm Setters thiết lập id và 1 hàm Setters thiết lập ngày cho class Booking
	void set_booking_date(CDate date);
	void set_booking_id(string id);
	void set_customer_id(string customer_id);
	void set_accommodation_id(string accommodation_id);
	void set_vehicle_id(string vehicle_id);
	void set_payment_id(string payment_id);
	void set_tour_id(string tour_id);
	void set_tour_guide_id(string tour_guide_id);

	// 7 hàm Getters để lấy id và 1 hàm Getters để lấy ngày cho class Booking

	CDate get_booking_date();
	string get_booking_id();
	string get_customer_id();
	string get_accommodation_id();
	string get_vehicle_id();
	string get_payment_id();
	string get_tour_id();
	string get_tour_guide_id();

	//Tính năng cơ bản
	void input_booking(CustomerList& customer_list, AccommodationList& accommodation_list, VehicleList& vehicle_list,
		PaymentList& payment_list, TourList& tour_list, TourGuideList& tour_guide_list);
	void print_booking();
	void edit_booking();
	void save_booking();

};