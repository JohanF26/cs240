#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUserLL.h"

using namespace std;

FBLUserLL::FBLUserLL(){
  head = nullptr;
}

FBLUserLL::FBLUserLL(FBLUserNode* fblun){
  head = fblun;
}

FBLUserNode* FBLUserLL::getHead(){
  return head;
}

void FBLUserLL::setHead(FBLUserNode* fblun){
  head = fblun;
}

void FBLUserLL::create(string fname, string lname, string uid, string pword){
  if(isUnique(uid)){
    //if userid is unique create a pointer to a new user
    FBLUser* newUser = new FBLUser(fname, lname, uid, pword);
    //add new user to linkedlist
    FBLUserNode* newUserNode = new FBLUserNode(newUser);
    if(head != nullptr){
      //make new ll object point to old first object
      //this is the easiest way of doing this since we don't have a tail
      newUserNode->setNextUser(head);
      head = newUserNode;
    } else {
      head = newUserNode;
    }
    cout << "Success!\n---------------" << endl;
  } else {
    cout << "User ID already in use. Please try a different User ID.\n---------------" << endl;
  }
}

FBLUser* FBLUserLL::login(string uid, string pword){
  FBLUser* retUser = nullptr;
  FBLUserNode* tempNode = head;
  if(tempNode == nullptr){
    cout << "There are no users" << endl;
  } else{
    FBLUser* tempUser = tempNode->getUser();
    while(tempNode != nullptr){
      tempUser = tempNode->getUser();
      if(tempUser->getUserID() == uid){
        if(tempUser->getPassword() == pword){
          //return the user if it exists and input is valid
          retUser = tempUser;
          break;
        } else {
          cout << "Wrong password.\n---------------" << endl;
          //I don't want it to keep looking so I'll call a break
          break;
        }
      } else {
        tempNode = tempNode->getNextUser();
      }
    }
    //this will not run when breaking out of the loop
    if(tempNode == nullptr){
      cout << "User does not exist. Please try again with a different User ID.\n---------------" << endl;
    }
  }
  return retUser;
}

bool FBLUserLL::isUnique(string uid){
  FBLUserNode* tempNode = head;
  while(tempNode != nullptr){
    if(tempNode->getUser()->getUserID() == uid){
      return false;
    }
    tempNode = tempNode->getNextUser();
  }
  return true;
}











//////
