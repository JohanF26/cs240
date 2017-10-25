#ifndef FBLUSERNODE_H
#define FBLUSERNODE_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUser.h"

using namespace std;

class FBLUserNode{
  private:
    FBLUser* user;
    FBLUserNode* next;

  public:
    FBLUserNode();
    FBLUserNode(FBLUser* fblu);

    FBLUser* getUser();
    void setUser(FBLUser* fblu);

    FBLUserNode* getNextUser();
    void setNextUser(FBLUserNode* fblun);

};

#endif
