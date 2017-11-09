#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLComment.h"

using namespace std;

FBLComment::FBLComment(){
  comment = "";
  first = "";
  last = "";
}

FBLComment::FBLComment(string c, string f, string l){
  comment = c;
  first = f;
  last = l;
}

string FBLComment::getComment(){
  return comment;
}

void FBLComment::setComment(string c){
  comment = c;
}

string FBLComment::getFirst(){
  return first;
}

void FBLComment::setFirst(string f){
  first = f;
}

string FBLComment::getLast(){
  return last;
}

void FBLComment::setLast(string l){
  last = l;
}
