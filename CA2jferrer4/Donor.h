#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class Donor{
	public:
        Donor();

		void manage();
		void password();
		void view();
		void donate();
		void total();
    
	private:
		enum State {NY, PA, RI, NH, VT, MA, CT, ME};
	
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
		
		

};
