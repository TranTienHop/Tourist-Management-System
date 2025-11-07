#pragma once 
#include<string>
#include<iostream> 
#include<vector> 
#include<fstream>
 
using namespace std;

class Accommodation {
protected:
    string accommodation_id;
    string name;
    string address;
    int mobile;
    double price;
    string room_status;

public:
	friend istream& operator>>(istream& is, Accommodation& ac);
    friend ostream& operator<<(ostream& os, const Accommodation& ac);
	
    Accommodation();
    Accommodation(string id, string n, string addr, int m, double p, string r_s);
    Accommodation(const Accommodation& ac);
    virtual ~Accommodation();

	//Getter 
    string get_accommodation_id();
    string get_name();
    string get_address();
    int get_mobile();
    double get_price();
    string get_room_status();

    //Setter 
    void set_accommodation_id(string id);
    void set_name(string n);
    void set_address(string addr);
    void set_mobile(int m);
    void set_price(double p);
    void set_room_status(string r_s);

    virtual void input() = 0;
    virtual void display() const = 0;
    virtual void update() = 0;
    virtual void edit() = 0;
    virtual void remove() = 0;
    virtual void search() = 0;
    virtual void save_to_file() = 0;

    virtual void book_room() = 0;
    virtual void check_status() = 0;
    virtual void update_status() = 0;
};


void readFromFile(const string& filename, vector<Accommodation*>& list);


class Hotel : public Accommodation {
private:
    int star_rating;
    string utilities;
    int total_rooms;

public:
    Hotel();
    Hotel(string id, string name, string addr, int m, double p, string r_s, int star, string uti, int total);
    Hotel(const Hotel& h);
    ~Hotel();

    void set_star_rating(int star);
    void set_utilities(string uti);
    void set_total_rooms(int total_rooms);

    int get_star_rating();
    string get_utilities();
    int get_total_rooms();

    void input() override;
    void display() const override;
    void update() override;
    void edit() override;
	void remove() override;
	void  search() override;
	void save_to_file() override;
	
	void book_room() override;
	void check_status() override;
	void update_status() override; 
};

class Motel : public Accommodation {
private:
    string working_hours;
    int motorbike_count;
    string vehicle_status;

public:
    Motel();
    Motel(string id, string n, string addr, int m, double p, string r_s, string w_h, int m_count, string v_status);
    Motel(const Motel& mt);
    ~Motel();

    void set_working_hours(string w);
    void set_motorbike_count(int count);
    void set_vehicle_status(string status);
 
    string get_working_hours();
    int get_motorbike_count();
    string get_vehicle_status();

    void input() override;
    void display() const override;
    void update() override;
    void edit() override;
	void remove() override;
	void  search() override;
	void save_to_file() override;
	
	void book_room() override;
	void check_status() override;
	void update_status() override; 
    
    void book_vehicle();
};

