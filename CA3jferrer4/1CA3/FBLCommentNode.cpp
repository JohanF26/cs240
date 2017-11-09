#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLCommentNode.h"

using namespace std;

FBLCommentNode::FBLCommentNode(){
  comment = nullptr;
  next = nullptr;
  prev = nullptr;
}

FBLCommentNode::FBLCommentNode(FBLComment* fblc){
  comment = fblc;
  next = nullptr;
  prev = nullptr;
}

FBLCommentNode::~FBLCommentNode(){
  if(comment != nullptr){
    delete comment;
  }
  if(next != nullptr){
    delete next;
  }
  if(prev != nullptr){
    delete prev;
  }
}

FBLComment* FBLCommentNode::getComment(){
  return comment;
}

void FBLCommentNode::setComment(FBLComment* fblc){
  comment = fblc;
}

FBLCommentNode* FBLCommentNode::getNextComment(){
  return next;
}

void FBLCommentNode::setNextComment(FBLCommentNode* fblcn){
  next = fblcn;
}

FBLCommentNode* FBLCommentNode::getPrevComment(){
  return prev;
}

void FBLCommentNode::setPrevComment(FBLCommentNode* fblcn){
  prev = fblcn;
}
