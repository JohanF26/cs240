#ifndef FBLPOST_H
#define FBLPOST_H
#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLCommentLL.h"

using namespace std;

class FBLPost{
  private:
    unsigned int postID;
    string post;
    int likes;

    FBLCommentLL* comments;

  public:
    FBLPost();
    FBLPost(string p, unsigned int id);

    //does not need a destructor since it is just a string

    string getPost();
    void setPost(string p);

    FBLCommentLL* getCommentLL();
    void setCommentLL(FBLCommentLL* cs);
    void printCommentsAZ();
    void printCommentsZA();

    void likePost();
    int getLikes();

    void commentPost(string c, string f, string l);

    void setPostID(unsigned int newID);
    unsigned int getPostID();

};

#endif
