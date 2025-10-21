#include "CDate.h"
#include <iostream>
#include <string>
using namespace std;

class Tour {
private:
	string tour_id;					
	string tour_destination;		
	CDate  tour_date;				
	float  tour_price_per_person; 

public:
	Tour();
	Tour(string, string, CDate, float, float);
	Tour(const Tour&);
	~Tour();

	void input_tour();
	void edit_tour();
	void print_tour();
	void save_tour();

	void set_tour_id(string);
	void set_tour_destination(string);
	void set_tour_date(CDate);
	void set_tour_price_per_person(float);

	string get_tour_id();
	string get_tour_destination();
	CDate get_tour_date();
	float get_price_per_person();

};
struct Node {
	Tour data;
	Node* next;
};

class TourList {
private:
	Node* head;
public:
	TourList();
	void add_tour();
	void delete_tour(string);
	void update_tour(string);
	Node* search_tour_by_id(string);
	void sort_by_price();
	void print_all_tours();
	void save_to_file();
	void load_from_file();
	~TourList();

};
