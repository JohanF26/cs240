#include <iostream>
#include <stdlib.h>
#include "string"
#ifndef FBLPOST_H
#define FBLPOST_H

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
