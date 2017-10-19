#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPost.h"

using namespace std;

FBLPost::FBLPost(){
  post = "";

}

FBLPost::FBLPost(string p){
  post = p;

}

string FBLPost::getPost(){
  return post;

}

void FBLPost::setPost(string p){
  post = p;

}

////Done
