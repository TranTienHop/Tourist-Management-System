#pragma once

#include <fstream>
#include <string>

#include "CDate.h"

class CustomerList;
class AccommodationList;
class VehicleList;
class PaymentList;
class TourList;
class TourGuideList;

class Booking {
private:
	std::string booking_id;
	CDate booking_date;
	std::string customer_id;
	std::string accommodation_id;
	std::string vehicle_id;
	std::string payment_id;
	std::string tour_id;
	std::string tour_guide_id;

public:
	Booking();
	Booking(const std::string& booking_id,
	        const CDate& booking_date,
	        const std::string& customer_id,
	        const std::string& accommodation_id,
	        const std::string& vehicle_id,
	        const std::string& payment_id,
	        const std::string& tour_id,
	        const std::string& tour_guide_id);
	Booking(const Booking& other);
	~Booking();

	void set_booking_date(const CDate& date);
	void set_booking_id(const std::string& id);
	void set_customer_id(const std::string& customer_id);
	void set_accommodation_id(const std::string& accommodation_id);
	void set_vehicle_id(const std::string& vehicle_id);
	void set_payment_id(const std::string& payment_id);
	void set_tour_id(const std::string& tour_id);
	void set_tour_guide_id(const std::string& tour_guide_id);

	CDate get_booking_date() const;
	std::string get_booking_id() const;
	std::string get_customer_id() const;
	std::string get_accommodation_id() const;
	std::string get_vehicle_id() const;
	std::string get_payment_id() const;
	std::string get_tour_id() const;
	std::string get_tour_guide_id() const;

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
	void edit_booking(const std::string& booking_id);
	void delete_booking(const std::string& booking_id);
	Booking* search_booking(const std::string& booking_id);
	void save_bookings(const std::string& filename) const;
	void update_booking_date(const std::string& booking_id, const CDate& new_date);
	void sort_bookings_by_date();
};