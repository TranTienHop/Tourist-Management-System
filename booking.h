#pragma once

#include <fstream>
#include <string>

#include "CDate.h"

using namespace std;

class CustomerList;
class AccommodationList;
class VehicleList;
class PaymentList;
class TourList;
class TourGuideList;

class Booking {
private:
	string booking_id;
	CDate booking_date;
	string customer_id;
	string accommodation_id;
	string vehicle_id;
	string payment_id;
	string tour_id;
	string tour_guide_id;

public:
	Booking();
	Booking(const string& booking_id,
	        const CDate& booking_date,
	        const string& customer_id,
	        const string& accommodation_id,
	        const string& vehicle_id,
	        const string& payment_id,
	        const string& tour_id,
	        const string& tour_guide_id);
	Booking(const Booking& other);
	~Booking();

	void set_booking_date(const CDate& date);
	void set_booking_id(const string& id);
	void set_customer_id(const string& customer_id);
	void set_accommodation_id(const string& accommodation_id);
	void set_vehicle_id(const string& vehicle_id);
	void set_payment_id(const string& payment_id);
	void set_tour_id(const string& tour_id);
	void set_tour_guide_id(const string& tour_guide_id);

	CDate get_booking_date() const;
	string get_booking_id() const;
	string get_customer_id() const;
	string get_accommodation_id() const;
	string get_vehicle_id() const;
	string get_payment_id() const;
	string get_tour_id() const;
	string get_tour_guide_id() const;

	void input_booking(CustomerList& customer_list,
	                 AccommodationList& accommodation_list,
	                 VehicleList& vehicle_list,
	                 PaymentList& payment_list,
	                 TourList& tour_list,
	                 TourGuideList& tour_guide_list);
	void print_booking() const;
	void edit_booking();
	void save_booking() const;
};

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

	void add_booking(const Booking& booking);
	void edit_booking(const string& booking_id);
	void delete_booking(const string& booking_id);
	Booking* search_booking(const string& booking_id);
	void save_bookings(const string& filename) const;
	void update_booking_date(const string& booking_id, const CDate& new_date);
	void sort_bookings_by_date();
};