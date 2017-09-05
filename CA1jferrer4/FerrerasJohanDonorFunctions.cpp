#include <iostream>
#include <stdlib.h>
#include "Donor.h"

Donor::Donor(){
    last = "";
	first = "";
	age = -1;
	street_num = 0;
    street_name = "";
	town = "";
	zip_code = "xxxxx";
	donated = 0.00;
}

void Donor::add(){
    cout << "Last Name:";
    cin >> last;
    cout << '\n';
    
    cout << "First Name:";
    cin >> first;
    cout << '\n';
    
    cout << "Age:";
    cin >> age;
    cout << '\n';
    
    cout << "Street Number:";
    cin >> street_num;
    cout << '\n';
    
    cout << "Street Name:";
    cin >> street_name;
    cout << '\n';
    
    cout << "Town:";
    cin >> town;
    cout << '\n';
    
    cout << "Zip Code:";
    cin >> zip_code;
    cout << '\n';
    
}

void Donor::manage{
    add();
}

void Donor::view{
    cout << "Donor Info\n" << first << " " << last << ": age " << age << "\n" << street_num;
    cout << " " << street_name << "\n" << town << ", NY " << zip_code << ;
    std::printf( "\nCurrent Amount Donated: $%.2f", donated);
    cout << "\n\n"
}














