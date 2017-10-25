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

    string getPost();
    void setPost(string p);

};

#endif
