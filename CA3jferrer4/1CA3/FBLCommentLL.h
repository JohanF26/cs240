#ifndef FBLCOMMENTLL_H
#define FBLCOMMENTLL_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLCommentNode.h"

using namespace std;

class FBLCommentLL{
  private:
    FBLCommentNode* head;

  public:
    FBLCommentLL();
    FBLCommentLL(FBLCommentNode* fblcn);

    //destructor
    ~FBLCommentLL();

    FBLCommentNode* getHead();
    void setHead(FBLCommentNode* fblcn);

};

#endif
