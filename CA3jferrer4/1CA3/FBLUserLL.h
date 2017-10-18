#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLUserNode.h"
#include "FBLPostLL.h"

using namespace std;

class FBLUserLL{
  private:
    FBLUserNode* head;

  public:
    FBLUserLL();
    FBLUserLL(FBLUserNode* fblun);

    FBLUserNode* getHead();
    void setHead(FBLUserNode* fblun);

    void create(string fname, string lname, string uid, string pword);
    FBLUser* login(string uid, string pword);
    bool isUnique(string uid);

};
