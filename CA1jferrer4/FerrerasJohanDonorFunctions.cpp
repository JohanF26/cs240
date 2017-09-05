#include <iostream>
#include <stdlib.h>
#include "Donor.h"

Donor::Donor(string l, string f, int a, int snum, string sname, string t, string z, float d){
	last = l;
	first = f;
	age = a;
	street_num = snum;
	street_name = sname;
	town = t;
	zip_code = z;
	donated = d;
}
void setLast(string l){
	last = l;
}
void setFirst(string f){
	first = f;
}
void setAge(int a){
	age = a;
}
void setSNum(int snum, string sname){
	street_num = snum;
}
void setSName(string sname){
	street_name = sname;
}
void setTown(string t){
	town = t;
}
void setZip(string z){
	zip_code = z;
}
void setDonated(int d){
	donated = d;
}












