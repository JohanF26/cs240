#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#include "string"
#include "state.h"

using namespace std;

Donor::Donor(){
  string last = "";
  string first = "";
  string userid = "";
  string pw = "";
  int age = 0;
  int house_num = 0;
  string street_name = "";
  string town = "";
  State state = NY;
  string zip_code = "";

}

void Donor::setDonor(string l_name, string f_name, string u_ID, string p_word, int a, int s_num, string s_name, string t, State s, string zc){
	validInputs = true;

	bool validLast = true;
	for(int i = 0; i < l_name.length(); i++){
		if(!isalpha(l_name[i])){
			validLast = false;
			break;
		}
	}
	if(validLast){
		last = l_name;
	} else {
		validInputs = false;
	}

	bool validFirst = true;
	for(int i = 0; i < f_name.length(); i++){
		if(!isalpha(f_name[i])){
			validFirst = false;
			break;
		}
	}
	if(validFirst){
		first = f_name;
	} else {
		validInputs = false;
	}

	bool validID = true;
	for(int i = 0; i < u_ID.length(); i++){
		if(!isalnum(u_ID[i])){
			validID = false;
			break;
		}
	}
	if(validID && u_ID.length() >= 5 && u_ID.length() <= 10){
		userid = u_ID;
	} else {
		validInputs = false;
	}

  if(p_word.length() >= 6){
    bool has_digit = false;
    bool has_nonalnum = false;

    for(int i = 0; i < p_word.length(); i++){
      if(isdigit(p_word[i])){
        has_digit = true;
      } else if(isalnum(p_word[i]) == false){
        has_nonalnum = true;
      }
    }
    if(has_digit && has_nonalnum){
      pw = p_word;
    } else {
  		validInputs = false;
  	}
  } else {
  	validInputs = false;
  }

  if(a >= 18){
    age = a;
  } else {
  	validInputs = false;
  }

  if(s_num > 0){
    house_num = s_num;
  } else {
  	validInputs = false;
  }

  //this  basically doesn't need any checking
  street_name = s_name;
  town = t;

  if(s <= ME){
    state = s;
  } else {
  	validInputs = false;
  }

	bool validZIP = true;
	for(int i = 0; i < zc.length(); i++){
		if(!isdigit(zc[i])){
			validZIP = false;
			break;
		}
	}
	if(zc.length() == 5 && validZIP){
		zip_code = zc;
	} else {
		validInputs = false;
	}

  donated = 0.00;

  if(validInputs == false){
  	cout << "One or more of your inputs is invalid, please try again";
  }

}

void Donor::donorMenu(){
	bool continue_program = true;
	string com;
	while(continue_program){
		cout << "\nSuccessfully logged in as donor.\n Please enter a command.\nChoose from [\"Manage\" \"Passwd\" \"View\" \"Donate\" \"Total\" \"Logout\"]\n";
		cout << ": ";
		cin >> com;
		if(com == "Logout"){
			cout << "Logging out...";
		  continue_program = false;
		} else if(com == "Manage"){
		  manage();
		} else if(com == "Passwd"){
		  password();
		} else if(com == "View"){
		  view();
		} else if(com == "Donate"){
		  donate();
		} else if(com == "Total"){
		  total();
		} else{
		  cout << "Command not recognized. Please try again.\n";
		}
	}
}

void Donor::manage(){
	int choice = 0;
  string l_name;
  string f_name;
  string u_ID;
  string p_word;
  int a;
  int s_num;
  string s_name;
  string t;
  string s;
  string zc;

	while(choice != 9){
		cout << "1. Last Name\n2. First Name\n3. Age\n4. House Number\n5. Street Name\n6. Town\n7. State\n8. Zip Code";
		cout << "What would you like to change today? (Enter 9 to return)";
		cin >> choice;

		if(choice == 1){
			cout << "Last Name: ";
			cin >> l_name;

			bool validLast = true;
			for(int i = 0; i < l_name.length(); i++){
				if(!isalpha(l_name[i])){
					validLast = false;
					break;
				}
			}
			if(validLast){
				last = l_name;
				cout << "Last name was succesfully updated.";
			}
		} else if(choice == 2){
			cout << "First Name: ";
			cin >> f_name;

			bool validFirst = true;
			for(int i = 0; i < f_name.length(); i++){
				if(!isalpha(f_name[i])){
					validFirst = false;
					break;
				}
			}
			if(validFirst){
				first = f_name;
				cout << "First name was succesfully updated.";
			}

		} else if(choice == 3){
			cout << "Age: ";
    	cin >> a;

      if(a >= 18){
        age = a;
        cout << "Age was succesfully updated.";
      }

		} else if(choice == 4){
			cout << "House Number: ";
			cin >> s_num;

      if(s_num > 0){
        house_num = s_num;
        cout << "House number was succesfully updated.";
      }

		} else if(choice == 5){
			cout << "Street Name: ";
    	cin >> street_name;
      cout << "Street name was succesfully updated.";
		} else if(choice == 6){
			cout << "Town: ";
    	cin >> town;
      cout << "Town was succesfully updated";
		} else if(choice == 7){
			cout << "State: ";
			cin >> s;

      if(s == "NY" || s == "PA" || s == "RI" || s == "NH" || s == "VT" || s == "MA" || s == "CT" || s == "ME"){
        if(s == "NY"){
        	state = NY;
        } else if(s == "PA"){
        	state = PA;
        } else if(s == "RI"){
        	state = RI;
        } else if(s == "NH"){
        	state = NH;
        } else if(s == "VT"){
        	state = VT;
        } else if(s == "MA"){
        	state = MA;
        } else if(s == "CT"){
        	state = CT;
        } else{
        	state = ME;
        }
        cout << "State was succesfully updated.";
      }

		} else if(choice == 8){
			cout << "Zip Code: ";
    	cin >> zc;

		bool validZIP = true;
		for(int i = 0; i < zc.length(); i++){
			if(!isdigit(zc[i])){
				validZIP = false;
				break;
			}
		}
		if(zc.length() == 5 && validZIP){
			zip_code = zc;
			cout << "Zip code was succesfully updated.";
		}

		}
	}
}

void Donor::password(){
	string oldPW = "";
	string newPW = "";
	string newPW2 = "";
	bool pwDontMatch = true;
	cout << "Enter Old Password: ";
	cin >> oldPW;

	if(oldPW == pw){
		while(pwDontMatch){
			cout << "Enter New Password: ";
			cin >> newPW;

			if(newPW.length() >= 6){
				bool has_digit = false;
				bool has_nonalnum = false;

				for(int i = 0; i < newPW.length(); i++){
				  if(isdigit(newPW[i])){
					has_digit = true;
				  } else if(isalnum(newPW[i]) == false){
					has_nonalnum = true;
				  }
				}
				if(has_digit && has_nonalnum){
					cout << "Enter new password again: ";
					cin >> newPW2;
					if(newPW == newPW2){
						pw = newPW;
						pwDontMatch = false;
				  		cout << "Password successfully updated.";
					} else {
						cout << "Passwords do not match";
					}

				}
				else {
					cout << "Invalid password format. Password was not updated, please try again.";
				}
			}
		}
	} else {
		cout << "Incorrect password.";
	}

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
    if((d + donated) > 5000){
    	cout << "Donated total exceeds $5000.00";
    } else if(d < 0){
    	cout << "Cannot donate negative amount";
    } else {
    	std::printf("$%.2f donated.\n", d);
    	donated += d;
    }
}

float Donor::total(){
  cout << last;
  printf(" $%.2f\n", donated);
  return(donated);
}

string Donor::getID(){
	return userid;
}

string Donor::getPW(){
	return pw;
}

void Donor::setDonated(float d){
  donated = d;
}

string Donor::getLast(){
  return last;
}
string Donor::getFirst(){
  return first;
}
int Donor::getAge(){
  return age;
}
int Donor::getHouse(){
  return house_num;
}
string Donor::getStreet(){
  return street_name;
}
string Donor::getTown(){
  return town;
}
State Donor::getState(){
  return state;
}
string Donor::getZip(){
  return zip_code;
}
float Donor::getDonated(){
  return donated;
}
bool Donor::getValidInput(){
  return validInputs;
}
