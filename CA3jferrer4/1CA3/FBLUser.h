#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostLL.h"
#ifndef FBLUSER_H
#define FBLUSER_H

using namespace std;

class FBLUser {
	private:
		//data
		string userID;
		string password;
		string first;
		string last;
		FBLPostLL* postList;

	public:
		FBLUser();
		FBLUser(string f, string l, string uID, string pw);

		string getUserID();
		void setUserID(string uID);

		string getPassword();
		void setPassword(string pw);

		string getFirst();
		void setFirst(string f);

		string getLast();
		void setLast(string l);

		FBLPostLL* getPostList();

};

#endif
