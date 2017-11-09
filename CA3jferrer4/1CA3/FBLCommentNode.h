#ifndef FBLCOMMENTNODE_H
#define FBLCOMMENTNODE_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLComment.h"

using namespace std;

class FBLCommentNode{
  private:
    FBLComment* comment;
    FBLCommentNode* next;
    FBLCommentNode* prev;

  public:
    FBLCommentNode();
    FBLCommentNode(FBLComment* fblc);

    //destructor
    ~FBLCommentNode();

    FBLComment* getComment();
    void setComment(FBLComment* fblc);

    FBLCommentNode* getNextComment();
    void setNextComment(FBLCommentNode* fblcn);

    FBLCommentNode* getPrevComment();
    void setPrevComment(FBLCommentNode* fblcn);

};

#endif
