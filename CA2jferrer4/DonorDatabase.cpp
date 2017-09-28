#include <iostream>
#include <stdlib.h>
#include "DonorDatabase.h"
#include "Donor.h"
#include <fstream>
#include <ctype.h>

DonorDatabase::DonorDatabase(int dbSize){
	maximumSize = dbSize;
	totalDonated = 0.00;
	donorsInBase = 0;
	donorList = new Donor[maximumSize];
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

	Donor *donor_ptr = new Donor();

	while(!donor_ptr.getValidInput()){
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

		for(int i = 0; i < donorsInBase; i++){
			if(donorList[i].getID() == userid){
				cout << "User ID is taken, try choosing a new one.\n"
				i = 0;
				cout << "User ID: ";
				cin >> userid;
			}
		}

		donor_ptr = new Donor(last, first, userid, pw, age, house_num, street_name, town, state, zip_code);
	}

	donorList[donorsInBase] = *donor_ptr;
	donorsInBase++;

	cout << "\n";
}

void DonorDatabase::save(string outputFile){
	ofstream tempFile;
	file.open(outputFile, ios::out);
	if(tempFile.is_open()){
		cout << "A file with this name already exists. Enter 'Y' to override this file";
		string choice;
		cin >> choice;
		if(choice == "Y"){
			string tempLast
			string tempFirst;
			string tempID;
			string tempPW;
			int tempAge;
			int tempHouse;
			string tempStreet;
			string tempTown;
			State tempState;
			string tempZip;
			float tempDonated;
			for(int i = 0; i < maximumSize; i++){
				tempLast = donorList[i].getLast();
				tempFirst = donorList[i].getFirst();
				tempID = donorList[i].getID();
				tempPW = donorList[i].getPW();
				tempAge = donorList[i].getAge();
				tempHouse = donorList[i].getHouse();
				tempStreet = donorList[i].getStreet();
				tempTown = donorList[i].getTown();
				tempState = donorList[i].getState();
				tempZip = donorList[i].getZip();
				tempDonated = donorList[i].getDonated();

				tempFile << i << endl;
				tempFile << tempLast << end1;
				tempFile << tempFirst << endl;
				tempFile << tempID << endl;
				tempFile << tempPW << endl;
				tempFile << tempAge << endl;
				tempFile << tempHouse << endl;
				tempFile << tempStreet << endl;
				tempFile << tempTown << endl;
				tempFile << tempState << endl;
				tempFile << tempZip << endl;
				tempFile << tempDonated << endl;

			}
			cout << "File was overriden.";
		} else {
			cout << "File was not modified."
		}
		tempFile.close();
	} else {
		cout << "Invalid file, please try again with a different file.";
	}
}

void DonorDatabase::load(string inputFile){
	ifstream tempFile(inputFile);
	if(tempFile.is_open()){
		string tempLast
		string tempFirst;
		string tempID;
		string tempPW;
		int tempAge;
		int tempHouse;
		string tempStreet;
		string tempTown;
		State tempState;
		string tempZip;
		float tempDonated;

		string currentLine;
		while(getLine(tempFile, currentLine)){
			int positionOnList = stoi(currentLine);

			getLine(tempFile, currentLine);
			tempLast = currentLine;

			getLine(tempFile, currentLine);
			tempFirst = currentLine;

			getLine(tempFile, currentLine);
			tempID = currentLine;

			getLine(tempFile, currentLine);
			tempPW = currentLine;

			getLine(tempFile, currentLine);
			tempAge = stoi(currentLine);

			getLine(tempFile, currentLine);
			tempHouse = stoi(currentLine);

			getLine(tempFile, currentLine);
			tempStreet = currentLine;

			getLine(tempFile, currentLine);
			tempTown = currentLine;

			getLine(tempFile, currentLine);
			tempState = currentLine;

			getLine(tempFile, currentLine);
			tempZip = currentLine;

			getLine(tempFile, currentLine);
			tempDonated = stof(currentLine);

			Donor *tempDonor = new Donor(tempLast, tempFirst, tempID, tempPW, tempAge, tempHouse, tempStreet, tempTown, tempState, tempZip);
			tempDonor.setDonated(tempDonated);

			donorList[positionOnList] = tempDonor;
			donorsInBase++;
		}
		tempFile.close();
	} else{
		cout << "Incorrect file. Make sure it is a .txt file.";
	}
}

void DonorDatabase::report(){
	float donationReport = 0;
	cout << donorsInBase << " donors currently in database.\n";
	for(int i = 0; i < maximumSize; i++){
		donationReport += donorList[i]->total();
	}
	printf("A total of $%.2f has been donated.\n", donationReport);
}
