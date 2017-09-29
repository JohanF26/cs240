#include <iostream>
#include <stdlib.h>
#include "DonorDatabase.h"
#include "Donor.h"
#include <fstream>
#include <ctype.h>
#include "state.h"

using namespace std;

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
	string st;
	State state;
	string zip_code;
	float donated;

	Donor *donor_ptr = new Donor();

	if(donorsInBase == maximumSize){
		cout << "Limit of donors has been reached";
		return;
	}

	while(!donor_ptr->getValidInput()){
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
		cin.ignore(1000, '\n');
	  getline(cin, street_name);

	  cout << "Town: ";
	  getline(cin, town);

		cout << "State: ";
		cin >> st;
		if(st == "NY" || st == "PA" || st == "RI" || st == "NH" || st == "VT" || st == "MA" || st == "CT" || st == "ME"){
        if(st == "NY"){
        	state = NY;
        } else if(st == "PA"){
        	state = PA;
        } else if(st == "RI"){
        	state = RI;
        } else if(st == "NH"){
        	state = NH;
        } else if(st == "VT"){
        	state = VT;
        } else if(st == "MA"){
        	state = MA;
        } else if(st == "CT"){
        	state = CT;
        } else{
        	state = ME;
        }
      }

	  cout << "Zip Code: ";
	  cin >> zip_code;

		for(int i = 0; i < donorsInBase; i++){
			if(donorList[i].getID() == userid){
				cout << "User ID is taken, try choosing a new one.\n";
				i = 0;
				cout << "User ID: ";
				cin >> userid;
			}
		}

		donor_ptr->setDonor(last, first, userid, pw, age, house_num, street_name, town, state, zip_code);
	}

	donorList[donorsInBase] = *donor_ptr;
	donorsInBase++;

	cout << "\n";
}

void DonorDatabase::save(string outputFile){
	ofstream tempFile;
	tempFile.open(outputFile, ios::out);
	if(tempFile.is_open()){
		cout << "A file with this name already exists. Enter 'Y' to override this file";
		string choice;
		cin >> choice;
		if(choice == "Y"){
			string tempLast;
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
				tempFile << tempLast << endl;
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
			cout << "File was not modified.";
		}
		tempFile.close();
	} else {
		cout << "Invalid file, please try again with a different file.";
	}
}

void DonorDatabase::load(string inputFile){
	ifstream tempFile(inputFile);
	if(tempFile.is_open()){
		string tempLast;
		string tempFirst;
		string tempID;
		string tempPW;
		int tempAge;
		int tempHouse;
		string tempStreet;
		string tempTown;
		string tempSt;
		State tempState;
		string tempZip;
		float tempDonated;

		string currentLine;
		int donorsInFile = 0;
		while(getline(tempFile, currentLine)){
			int positionOnList = stoi(currentLine);
			if(positionOnList > donorsInFile){
				donorsInFile = positionOnList;
			}

			getline(tempFile, currentLine);
			tempLast = currentLine;

			getline(tempFile, currentLine);
			tempFirst = currentLine;

			getline(tempFile, currentLine);
			tempID = currentLine;

			getline(tempFile, currentLine);
			tempPW = currentLine;

			getline(tempFile, currentLine);
			tempAge = stoi(currentLine);

			getline(tempFile, currentLine);
			tempHouse = stoi(currentLine);

			getline(tempFile, currentLine);
			tempStreet = currentLine;

			getline(tempFile, currentLine);
			tempTown = currentLine;

			getline(tempFile, currentLine);
			tempSt = currentLine;
			if(tempSt == "NY" || tempSt == "PA" || tempSt == "RI" || tempSt == "NH" || tempSt == "VT" || tempSt == "MA" || tempSt == "CT" || tempSt == "ME"){
		    if(tempSt == "NY"){
		    	tempState = NY;
		    } else if(tempSt == "PA"){
		    	tempState = PA;
		    } else if(tempSt == "RI"){
		    	tempState = RI;
		    } else if(tempSt == "NH"){
		    	tempState = NH;
		    } else if(tempSt == "VT"){
		    	tempState = VT;
		    } else if(tempSt == "MA"){
		    	tempState = MA;
		    } else if(tempSt == "CT"){
		    	tempState = CT;
		    } else{
		    	tempState = ME;
		    }
		  }

			getline(tempFile, currentLine);
			tempZip = currentLine;

			getline(tempFile, currentLine);
			tempDonated = stof(currentLine);

			Donor *tempDonor = new Donor();
			tempDonor->setDonor(tempLast, tempFirst, tempID, tempPW, tempAge, tempHouse, tempStreet, tempTown, tempState, tempZip);
			tempDonor->setDonated(tempDonated);

			donorList[positionOnList] = *tempDonor;
		}
		donorsInBase += donorsInFile;
		tempFile.close();
	} else{
		cout << "Incorrect file. Make sure it is a .txt file.";
	}
}

void DonorDatabase::report(){
	float donationReport = 0;
	cout << donorsInBase << " donors currently in database.\n";
	for(int i = 0; i < donorsInBase; i++){
		donationReport += donorList[i].total();
	}
	printf("A total of $%.2f has been donated.\n", donationReport);
}
