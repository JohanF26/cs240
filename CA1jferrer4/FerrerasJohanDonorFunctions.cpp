#include <iostream>
#include <stdlib.h>
#include "Donor.h"

Donor::Donor(){
    last = "";
	first = "";
	age = -1;
	house_num = 0;
    street_name = "";
	town = "";
	zip_code = "xxxxx";
	donated = 0.00;
}

void Donor::add(){
    cout << "Last Name: ";
    cin >> last;
    
    cout << "First Name: ";
    cin >> first;
    
    cout << "Age: ";
    cin >> age;
    
    cout << "House Number: ";
    cin >> house_num;
    
    cout << "Street Name: ";
    cin >> street_name;
    
    cout << "Town: ";
    cin >> town;
    
    cout << "Zip Code: ";
    cin >> zip_code;
    
}

void Donor::manage(){
    add();
}

void Donor::view(){
    cout << "Donor Info\n" << first << " " << last << ": age " << age << "\n" << house_num;
    cout << " " << street_name << "\n" << town << ", NY " << zip_code;
    std::printf( "\nCurrent Amount Donated: $%.2f \n", donated);
}
    
void Donor::donate(){
    float d;
    cout << "\nEnter Amount to Donate: ";
    cin >> d;
    std::printf("$%.2f donated.\n", d);
    donated += d;
}

void Donor::total(){
    printf(" $%.2f\n", donated);
}











