#ifndef FBLCOMMENT_H
#define FBLCOMMENT_H
#include <iostream>
#include <stdlib.h>
#include "string"

using namespace std;

class FBLComment{
  private:
    string comment;
    string first;
    string last;

  public:
    FBLComment();
    FBLComment(string c, string f, string l);

    string getComment();
    void setComment(string c);

    string getFirst();
    void setFirst(string f);

    string getLast();
    void setLast(string l);

};

#endif
