#pragma once

#include <string>

#include "CDate.h"

using namespace std;

class Tour {
private:
	string tour_id;
	string tour_destination;
	CDate tour_date;
	float tour_price_per_person;

public:
	Tour();
	Tour(const string& id, const string& destination, const CDate& date, float price);
	Tour(const Tour& other);
	~Tour();

	void input_tour();
	void edit_tour();
	void print_tour() const;
	void save_tour() const;

	void set_tour_id(const string& id);
	void set_tour_destination(const string& destination);
	void set_tour_date(const CDate& date);
	void set_tour_price_per_person(float price);

	string get_tour_id() const;
	string get_tour_destination() const;
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
	void delete_tour(const string& id);
	void update_tour(const string& id);
	TourNode* search_tour_by_id(const string& id);
	void sort_by_price();
	void print_all_tours() const;
	void save_to_file() const;
	void load_from_file();
};
