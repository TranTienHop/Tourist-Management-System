#pragma once

#include <string>

#include "CDate.h"

class Tour {
private:
	std::string tour_id;
	std::string tour_destination;
	CDate tour_date;
	float tour_price_per_person;

public:
	Tour();
	Tour(const std::string& id, const std::string& destination, const CDate& date, float price);
	Tour(const Tour& other);
	~Tour();

	void input_tour();
	void edit_tour();
	void print_tour() const;
	void save_tour() const;

	void set_tour_id(const std::string& id);
	void set_tour_destination(const std::string& destination);
	void set_tour_date(const CDate& date);
	void set_tour_price_per_person(float price);

	std::string get_tour_id() const;
	std::string get_tour_destination() const;
	CDate get_tour_date() const;
	float get_price_per_person() const;
};

struct TourNode {
	Tour data;
	TourNode* next;
};

class TourList {
private:
	TourNode* head;

public:
	TourList();
	~TourList();

	void add_tour();
	void delete_tour(const std::string& id);
	void update_tour(const std::string& id);
	TourNode* search_tour_by_id(const std::string& id);
	void sort_by_price();
	void print_all_tours() const;
	void save_to_file() const;
	void load_from_file();
};
