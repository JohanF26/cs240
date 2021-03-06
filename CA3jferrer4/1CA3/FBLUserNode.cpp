#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUserNode.h"

using namespace std;

FBLUserNode::FBLUserNode(){
  user = nullptr;
  next = nullptr;

}

FBLUserNode::FBLUserNode(FBLUser* fblu){
  user = fblu;
  next = nullptr;

}

FBLUserNode::~FBLUserNode(){
  if(user != nullptr){
    //delete this user
    delete user;
  }
  if(next != nullptr){
    //call destructor for next user node
    delete next;
  }
}

FBLUser* FBLUserNode::getUser(){
  return user;
}

void FBLUserNode::setUser(FBLUser* fblu){
  user = fblu;
}

FBLUserNode* FBLUserNode::getNextUser(){
  return next;
}

void FBLUserNode::setNextUser(FBLUserNode* fblun){
  next = fblun;

}
