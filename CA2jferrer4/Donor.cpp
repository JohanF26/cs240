#include <iostream>
#include <stdlib.h>
#include "Donor.h"

Donor::Donor(){
    last = "";
	first = "";
	pw = "";
	age = -1;
	house_num = 0;
    street_name = "";
	town = "";
	state = NY;
	zip_code = "xxxxx";
	donated = 0.00;
	
}

void Donor::manage(){
	int choice = 0;
	while(choice != 9){
		cout << "1. Last Name\n2. First Name\n3. Age\n4. House Number\n5. Street Name\n6. Town\n7. State\n8. Zip Code";
		cout << "What would you like to change today? (Enter 9 to return)";
		cin >> choice;
		
		if(choice == 1){
			cout << "Last Name: ";
    		cin >> last;
		} else if(choice == 2){
			cout << "First Name: ";
    		cin >> first;
		} else if(choice == 3){
			cout << "Age: ";
    		cin >> age;
		} else if(choice == 4){
			cout << "House Number: ";
			cin >> house_num;
		} else if(choice == 5){
			cout << "Street Name: ";
    		cin >> street_name;
		} else if(choice == 6){
			cout << "Town: ";
    		cin >> town;
		} else if(choice == 7){
			cout << "State: ";
			cin >> state;
		} else if(choice == 8){
			cout << "Zip Code: ";
    		cin >> zip_code;
		}
	}
	

    
    
    
    
    
    
    
    
    
    
    
    
    
}

void Donor::password(){

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

