#include <iostream>
#include <stdlib.h>
#include "DonorDatabase.h"
#include "Donor.h"

void DonorDatabase::DonorDatabase(int dbSize){
	maximumSize = dbSize;
	totalDonated = 0.00;
	donorsInBase = 0;
}

void DonorDatabase::login(){
	string uID = "";
	string pWord = "";
	
	cout << "Username: ";
	cin >> uID;

	cout << "Password: ";
	cin >> pWord;
	
	for(int i = 0; i < donorsInBase; i++){
		Donor* tempDon = &donorList[i];
		if(uID == tempDon->getID()){
			if(pWord == tempDon->getPW()){
				tempDon->donorMenu();
				break;
			} else{
				cout << "Incorrect password.";
			}
		} else{
			cout << "Username does not exist.";
		}
	}

}

void DonorDatabase::add(){
	string last;
	string first;
	string userid;
	string pw;
	int age;
	int house_num;
	string street_name;
	string town;
	State state;
	string zip_code;
	float donated;

  cout << "Last Name: ";
  cin >> last;

  cout << "First Name: ";
  cin >> first;

	cout << "User ID: ";
	cin >> userid;

	cout << "Password: ";
	cin >> pw;

  cout << "Age: ";
  cin >> age;

  cout << "House Number: ";
  cin >> house_num;

  cout << "Street Name: ";
  cin >> street_name;

  cout << "Town: ";
  cin >> town;

	cout << "State: ";
	cin >> state;

  cout << "Zip Code: ";
  cin >> zip_code;

	Donor *donor_ptr = new Donor(last, first, userid, pw, age, house_num, street_name, town, state, zip_code);
	donorsInBase
}

void DonorDatabase::save(){

}

void DonorDatabase::load(){

}

void DonorDatabase::report(){
	float donationReport = 0;
	for(int i = 0; i < maximumSize; i++){
		donationReport += donorList[i]->total();
	}
	printf("A total of $%.2f has been donated.\n", donationReport);
}

void DonorDatabase::quit(){
	

}
