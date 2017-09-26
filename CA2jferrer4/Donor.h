#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class Donor{
	public:
    Donor();
		Donor(string l_name, string f_name, string u_ID, string p_word, int a, int s_num, string s_name, string t, State s, string zc);

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
