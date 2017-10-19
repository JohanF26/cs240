#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostNode.h"
#include "FBLPost.h"

using namespace std;

FBLPostNode::FBLPostNode(){
  post = nullptr;
  next = nullptr;

}

FBLPostNode::FBLPostNode(FBLPost* fblp){
  post = fblp;
  next = nullptr;

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
