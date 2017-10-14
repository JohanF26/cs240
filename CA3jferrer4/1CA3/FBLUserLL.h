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

    FBLUserNode* getHead();
    void setHead(FBLUserNode* fblun);

};
