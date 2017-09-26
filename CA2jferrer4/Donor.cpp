#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#include "DonorDatabase.h"

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

Donor::Donor(string l_name, string f_name, string u_ID, string p_word, int a, int s_num, string s_name, string t, State s, string zc){
  if(isalpha(l_name)){
    last = l_name;
  }

  if(isalpha(f_name)){
    first = f_name;
  }

  if(isalnum(u_ID) && u_ID.length() >= 5 && u_ID.length() <= 10){
    userid = u_ID;
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
      password = p_word;
    }
  }

  if(a >= 18){
    age = a;
  }

  if(s_num > 0){
    house_num = s_num;
  }

  //this  basically doesn't need any checking
  street_name = s_name;
  town = t;

  if(s <= ME){
    state = s;
  }

  if(z.length() == 5 && isdigit(z)){
    zip_code = zc;
  }

  donated = 0.00;

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
  State s;
  string zc;

	while(choice != 9){
		cout << "1. Last Name\n2. First Name\n3. Age\n4. House Number\n5. Street Name\n6. Town\n7. State\n8. Zip Code";
		cout << "What would you like to change today? (Enter 9 to return)";
		cin >> choice;

		if(choice == 1){
			cout << "Last Name: ";
    	cin >> l_name;

      if(isalpha(l_name)){
        last = l_name;
        cout << "Last name was succesfully updated."
      }

		} else if(choice == 2){
			cout << "First Name: ";
    	cin >> f_name;

      if(isalpha(f_name)){
        first = f_name;
        cout << "First name was succesfully updated."
      }

		} else if(choice == 3){
			cout << "Age: ";
    	cin >> a;

      if(a >= 18){
        age = a;
        cout << "Age was succesfully updated."
      }

		} else if(choice == 4){
			cout << "House Number: ";
			cin >> s_num;

      if(s_num > 0){
        house_num = s_num;
        cout << "House number was succesfully updated."
      }

		} else if(choice == 5){
			cout << "Street Name: ";
    	cin >> street_name;
      cout << "Street name was succesfully updated."
		} else if(choice == 6){
			cout << "Town: ";
    	cin >> town;
      cout << "Town was succesfully updated"
		} else if(choice == 7){
			cout << "State: ";
			cin >> s;

      if(s <= ME){
        state = s;
        cout << "State was succesfully updated."
      }

		} else if(choice == 8){
			cout << "Zip Code: ";
    	cin >> zc;

      if(z.length() == 5 && isdigit(z)){
        zip_code = zc;
        cout << "Zip code was succesfully updated."
      }

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
