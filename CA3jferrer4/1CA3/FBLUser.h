#ifndef FBLUSER_H
#define FBLUSER_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostLL.h"
#include "vector"

using namespace std;

class FBLUser {
	private:
		//data
		string userID;
		string password;
		string first;
		string last;
		//user's posts
		FBLPostLL* wall;
		//friends posts
		FBLPostLL* feed;

		vector<FBLUser*> userFriends;

	public:
		FBLUser();
		FBLUser(string f, string l, string uID, string pw);

		~FBLUser();

		string getUserID();
		void setUserID(string uID);

		string getPassword();
		void setPassword(string pw);

		string getFirst();
		void setFirst(string f);

		string getLast();
		void setLast(string l);

		//Wall functions
		FBLPostLL* getWall();
		void printWall();

		//Feed fundtions
		FBLPostLL* getFeed();
		void printFeed();
		vector<FBLUser*> getUserFriends();

		//Wall functions
		bool befriend(FBLUser* newFriend);
		void printFriends();

};

#endif
