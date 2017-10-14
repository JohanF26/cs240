#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUserLL.h"
#include "FBLUserNode.h"

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
