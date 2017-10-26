#ifndef FBLPOST_H
#define FBLPOST_H
#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class FBLPost{
  private:
    string post;

  public:
    FBLPost();
    FBLPost(string p);

    //does not need a destructor since it is just a string

    string getPost();
    void setPost(string p);

};

#endif
