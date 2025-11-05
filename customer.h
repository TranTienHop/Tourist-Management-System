#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Person.h"
#include "CTime.h"
#include "CAddress.h"

using namespace std;

class Customer : public Person {
private:
	string customer_id;
	int number_of_people;
	double total_spending;

public:
	Customer();
	Customer(string, string, int, string, string, int, double);
	Customer(const Customer&);
	~Customer();

	void set_customer_id(string);
	void set_number_of_people(int);
	void set_total_spending(double);

	string get_customer_id();
	int get_number_of_people();
	double get_total_spending();

	void input();
	void display();
	void update();
	void edit();
	void remove();
	void save();

	void calculate_loyalty_points();
	void view_booking();
};


struct Node {
	Customer data;
	Node* next;
};

class CustomerList {
private:
	Node* head;
public:
	CustomerList();
	~CustomerList();

	bool isEmpty();
	void add_customer(const Customer&);
	void display_all();
	Node* search_by_id(string);
	void update_customer(string);
	void remove_customer(string);
	void save_to_file(string);
	void load_from_file(string);
};

