#include <iostream>
#include <stdlib.h>
#include "string"
#include "state.h"
#ifndef DONOR_H
#define DONOR_H

using namespace std;

class Donor{
	private:

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

		bool validInputs;

	public:
		
		void setDonor(string l_name, string f_name, string u_ID, string p_word, int a, int s_num, string s_name, string t, State s, string zc);
    	Donor();

		void donorMenu();
		void manage();
		void password();
		void view();
		void donate();
		float total();

		bool getValidInput();

		string getLast();
		string getFirst();
		string getID();
		string getPW();
		int getAge();
		int getHouse();
		string getStreet();
		string getTown();
		State getState();
		string getZip();
		float getDonated();

		void setDonated(float d);

};

#endif
