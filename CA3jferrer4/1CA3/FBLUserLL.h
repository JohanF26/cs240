#ifndef FBLUSERLL_H
#define FBLUSERLL_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUserNode.h"

using namespace std;

class FBLUserLL{
  private:
    FBLUserNode* head;

  public:
    FBLUserLL();
    FBLUserLL(FBLUserNode* fblun);

    //destructor
    ~FBLUserLL();

    FBLUserNode* getHead();
    void setHead(FBLUserNode* fblun);

    void create(string fname, string lname, string uid, string pword);
    FBLUser* login(string uid, string pword);
    bool isUnique(string uid);

};

#endif
