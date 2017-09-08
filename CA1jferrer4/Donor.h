#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class Donor{
	public:
        Donor();
    
		void add();
		void manage();
		void view();
		void donate();
		void total();
    
	private:
		string last;
		string first;
		int age;
		int street_num;
		string street_name;
		string town;
		string zip_code;
		float donated;

};
