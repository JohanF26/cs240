#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUser.h"


using namespace std;

FBLUser::FBLUser(){
  userID = "";
  password = "";
  first = "";
  last = "";
  wall = new FBLPostLL();
  feed = new FBLPostLL();

}

FBLUser::FBLUser(string f, string l, string uID, string pw){
  userID = uID;
  password = pw;
  first = f;
  last = l;
  wall = new FBLPostLL();
  feed = new FBLPostLL();

}

//User ID
string FBLUser::getUserID(){
  return userID;

}

void FBLUser::setUserID(string uID){
  userID = uID;
}

//Password
string FBLUser::getPassword(){
  return password;

}

void FBLUser::setPassword(string pw){
  password = pw;

}

//First Name
string FBLUser::getFirst(){
  return first;

}

void FBLUser::setFirst(string f){
  first = f;

}

//Last Name
string FBLUser::getLast(){
  return last;

}

void FBLUser::setLast(string l){
  last = l;

}

//Wall functions
FBLPostLL* FBLUser::getWall(){
  return wall;
}

//Feed functions
FBLPostLL* FBLUser::getFeed(){
  return feed;
}

//Friend functions
void FBLUser::befriend(string id){
  if(id != userID){
    string currID;
    for(int i = 0; i < userFriends.size(); i++){}
  } else{
    cout << "You cannot befriend yourself. Try again with a different user ID." << endl;
  }
}

void FBLUser::printFriends(){

}


///Done 2
