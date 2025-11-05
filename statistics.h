#include <iostream>

#include "CDate.h"
#include "CTime.h"
#include "CName.h"
#include "CAddress.h"
#include "booking.h"

using namespace std;

class statistics {
	private: 
		int sum_customer, sum_tour;
		double sum_price;
	public:
		statistics();
		~statistics();
		
		// Getter
	    int getSumCustomer() ;
	    int getSumTour() ;
	    double getSumPrice() ;

		// Setter
	    void setSumCustomer(int value);
	    void setSumTour(int value);
	    void setSumPrice(double value);
	    
	    
		int count_tour(const BookingList& list); //Tong so tour  
	    int count_customer(const BookingList& list, const string& customer_id);  //Tong so khach hang 
	    double sum_price_all_tour(const BookingList& list, const string& tour_id); //Tong doanh thu  
	   
	    void printf_thong_ke();                
	    void update_thong_ke(BookingList& list);    
	    void delete_thong_ke();
	    void sort_thong_ke(const BookingList& list);
	    void save_file_thong_ke();
	    void search(const BookingList& list);

	
	    void thong_ke_theo_ngay(BookingList& list, const CDate&);
	    void thong_ke_theo_tour(BookingList& list, const string&);
	    void thong_ke_theo_khach_hang(BookingList& list, const string&);

}; 
#pragma once 
