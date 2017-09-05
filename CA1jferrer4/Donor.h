#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class Donor{
	public:
		void add();
		void manage();
		void view();
		void donate();
		void total();
		void quit();

	private:
		string last;
		string first;
		int age;
		int street_num;
		string street_name;
		string town;
		string zip_code;
		float donated;
		
		Donor(string l, string f, int a, int snum, string sname, string t, string z, float d);
		void setLast(string l);
		void setFirst(string f);
		void setAge(int a);
		void setSNum(int snum);
		void setSName(string sname);
		void setTown(string t);
		void setZip(string z);
		void setDonated(int d);

}
