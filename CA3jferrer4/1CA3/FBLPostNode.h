#ifndef FBLPOSTNODE_H
#define FBLPOSTNODE_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPost.h"

using namespace std;

class FBLPostNode{
  private:
    FBLPost* post;
    FBLPostNode* next;

  public:
    FBLPostNode();
    FBLPostNode(FBLPost* fblp);

    ~FBLPostNode();

    FBLPost* getPost();
    void setPost(FBLPost* fblp);

    FBLPostNode* getNextPost();
    void setNextPost(FBLPostNode* fblpn);

};

#endif
