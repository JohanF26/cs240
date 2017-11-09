#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLCommentLL.h"

using namespace std;

FBLCommentLL::FBLCommentLL(){
  head = nullptr;
}

FBLCommentLL::FBLCommentLL(FBLCommentNode* fblcn){
  head = fblcn;
}

FBLCommentLL::~FBLCommentLL(){
  if(head != nullptr){
    delete head;
  }
}

FBLCommentNode* FBLCommentLL::getHead(){
  return head;
}

void FBLCommentLL::setHead(FBLCommentNode* fblcn){
  head = fblcn;
}
