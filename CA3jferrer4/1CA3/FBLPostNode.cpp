#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostNode.h"

using namespace std;

FBLPostNode::FBLPostNode(){
  post = nullptr;
  next = nullptr;

}

FBLPostNode::FBLPostNode(FBLPost* fblp){
  post = fblp;
  next = nullptr;

}

FBLPostNode::~FBLPostNode(){
  if(post != nullptr){
    delete post;
  }
  if(next != nullptr){
    delete next;
  }
}

FBLPost* FBLPostNode::getPost(){
  return post;
}

void FBLPostNode::setPost(FBLPost* fblp){
  post = fblp;
}

FBLPostNode* FBLPostNode::getNextPost(){
  return next;
}

void FBLPostNode::setNextPost(FBLPostNode* fblpn){
  next = fblpn;

}



////Done
