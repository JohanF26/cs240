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
  postList = new FBLPostLL();

}

FBLUser::FBLUser(string f, string l, string uID, string pw){
  userID = uID;
  password = pw;
  first = f;
  last = l;
  postList = new FBLPostLL();

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

FBLPostLL* FBLUser::getPostList(){
  return postList;
}



///Done 2
