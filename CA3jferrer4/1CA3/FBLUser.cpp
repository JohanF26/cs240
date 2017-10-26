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

FBLUser::~FBLUser(){
  if(feed != nullptr){
    delete feed;
  }
  if(wall != nullptr){
    delete wall;
  }
  //userFriends.clear();
  //This leaves the vector on the stack so it is automatically deallocated
  userFriends = vector<FBLUser*>();
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

void FBLUser::printWall(){
  FBLPostNode* iterator = wall->getHead();
  //iterate through the list to get the last post
  //continue until there isn't a next post
  if(iterator != nullptr){
    while(iterator != nullptr){
      cout << iterator->getPost()->getPost() << endl;
      iterator = iterator->getNextPost();
    }
    cout << "---------------" << endl;
  } else{
    cout << "The wall is empty." << "\n---------------" << endl;
  }
  delete iterator;
  iterator = nullptr;
}

//Feed functions
FBLPostLL* FBLUser::getFeed(){
  return feed;
}

void FBLUser::printFeed(){
  FBLPostNode* iterator = feed->getHead();
  //iterate through the list to get the last post
  //continue until there isn't a next post
  if(iterator != nullptr){
    while(iterator != nullptr){
      cout << iterator->getPost()->getPost() << endl;
      iterator = iterator->getNextPost();
    }
    cout << "---------------" << endl;
  } else{
    cout << "The feed is empty." << "\n---------------" << endl;
  }
  delete iterator;
  iterator = nullptr;
}

vector<FBLUser*> FBLUser::getUserFriends(){
  return userFriends;
}

//Friend functions
bool FBLUser::befriend(FBLUser* newFriend){
  string currID = newFriend->getUserID();
  string myFriendID;
  string newFullName = newFriend->getFirst() + " " + newFriend->getLast();
  //check that newFriend is not the current user
  if(currID != userID){
    //make sure newFriend is not in the friends vector
    for(int i = 0; i < userFriends.size(); i++){
      myFriendID = userFriends[i]->getUserID();
      if(currID == myFriendID){
        break;
      }
    }
    if(currID == myFriendID){
      cout << newFullName << " is already your friend." << "\n---------------" << endl;
      return false;
    } else {
      userFriends.push_back(newFriend);
      return true;
    }
  } else{
    cout << "You cannot befriend yourself. Try again with a different user ID." << "\n---------------" << endl;
    return false;
  }
}

void FBLUser::printFriends(){
  string fullName = "";
  //check if there are any friends in the list
  if(userFriends.size() == 0){
    cout << "You do not have any friends." << "\n---------------" << endl;
  } else{
    //otherwise loop through the vector and print out their full names
    for(int i = 0; i < userFriends.size(); i++){
      fullName = userFriends[i]->getFirst() + " " + userFriends[i]->getLast();
      cout << fullName << endl;
    }
    cout << "---------------" << endl;
  }
}


///Done 2
