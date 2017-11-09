#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPost.h"

using namespace std;

FBLPost::FBLPost(){
  post = "";
  likes = 0;
  postID = 0;
  comments = new FBLCommentLL();

}

FBLPost::FBLPost(string p, unsigned int id){
  post = p;
  likes = 0;
  postID = id;
  comments = new FBLCommentLL();
}

string FBLPost::getPost(){
  return post;

}

void FBLPost::setPost(string p){
  post = p;

}

FBLCommentLL* FBLPost::getCommentLL(){
  return comments;
}

void FBLPost::setCommentLL(FBLCommentLL* cs){
  comments = cs;
}

void FBLPost::printCommentsAZ(){
  FBLCommentNode* iterator = comments->getHead();
  //iterate through the list to get the last post
  //continue until there isn't a next post
  if(iterator != nullptr){
    while(iterator != nullptr){
      cout << iterator->getComment()->getFirst() << " " << iterator->getComment()->getLast() << ": " << iterator->getComment()->getComment() << endl;
      iterator = iterator->getNextComment();
    }
    cout << "---------------" << endl;
  } else{
    cout << "There are no comments." << "\n---------------" << endl;
  }
  delete iterator;
  iterator = nullptr;
}

void FBLPost::printCommentsZA(){
  FBLCommentNode* iterator = comments->getHead();
  //iterate through the list to get the last post
  //continue until there isn't a next post
  if(iterator != nullptr){
    //go to the very last one in the LL
    while(iterator->getNextComment() != nullptr){
      iterator = iterator->getNextComment();
    }
    //then iterate the array backwards
    while(iterator != nullptr){
      cout << iterator->getComment()->getFirst() << " " << iterator->getComment()->getLast() << ": " << iterator->getComment()->getComment() << endl;
      iterator = iterator->getPrevComment();
    }
    cout << "---------------" << endl;
  } else{
    cout << "There are no comments." << "\n---------------" << endl;
  }
  delete iterator;
  iterator = nullptr;
}

void FBLPost::likePost(){
  likes++;
}

int FBLPost::getLikes(){
  return likes;
}

void FBLPost::commentPost(string c, string f, string l){
  FBLCommentNode* tempNode = comments->getHead();
  while(tempNode != nullptr){
    if(tempNode->getNextComment() != nullptr){
      tempNode = tempNode->getNextComment();
    } else {
      break;
    }
  }
  FBLComment* newComment = new FBLComment(c, f, l);
  FBLCommentNode* newCommentNode = new FBLCommentNode(newComment);
  if(tempNode != nullptr){
    newCommentNode->setPrevComment(tempNode);
    tempNode->setNextComment(newCommentNode);
  } else{
    comments->setHead(newCommentNode);
  }
}

void FBLPost::setPostID(unsigned int newID){
  postID = newID;
}

unsigned int FBLPost::getPostID(){
  return postID;
}








////Done
