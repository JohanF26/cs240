#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostLL.h"

using namespace std;

FBLPostLL::FBLPostLL(){
  head = nullptr;

}

FBLPostLL::FBLPostLL(FBLPostNode* p){
  //make the next post node a null pointer
  p->setNextPost(nullptr);
  //make the head a pointer to the post
  head = p;

}

FBLPostLL::~FBLPostLL(){
  if(head != nullptr){
    delete head;
  }
}

FBLPostNode* FBLPostLL::getHead(){
  return head;

}

void FBLPostLL::insertPost(FBLPostNode* p){
  //check if there is a post
  if(head != nullptr){
    //this moves the head to the next post
    p->setNextPost(head);
  }
  //sets a new head
  head = p;

}

unsigned int FBLPostLL::readPost(){
  int currPostID = 0;
  if(head == nullptr){
    //if the head is null then there is nothing to read
    cout << "Nothing to READ.\n---------------" << endl;
  } else if(head->getNextPost() == nullptr){
    //if head is not nullptr then we just need to make sure next post is nullptr
    //print out post and make it a nullptr
    cout << "Post:" << head->getPost()->getPost() << "\n---------------" << endl;
    //retrieves original post ID
    currPostID = head->getPost()->getPostID();
    //gets rid of this post
    head = nullptr;
  } else {
    //otherwise iterate through list to get last post
    //a node to iterate through the linked list
    FBLPostNode* iterator = head;
    //a node to set the new last post
    FBLPostNode* newLastPost = nullptr;

    //iterate through the list to get the last post
    //continue until there isn't a next post
    while(iterator->getNextPost() != nullptr){
      //if next post is last then this post is new last
      if(iterator->getNextPost()->getNextPost() == nullptr){
        newLastPost = iterator;
      }
      //otherwise set the iterator to the next post
      iterator = iterator->getNextPost();
    }
    //print out post, dealocate memory, and make it a nullptr
    cout << "Post:" << iterator->getPost()->getPost() << "\n---------------" << endl;
    //retrieves original post ID
    currPostID = iterator->getPost()->getPostID();
    delete iterator;
    iterator = nullptr;
    newLastPost->setNextPost(iterator);
    //newLastPost->getNextPost is set to iterator so all we need to do is make it a nullptr
    //for newLastPost to be last post the next should be a nullptr
    //newLastPost->setNextPost(nullptr);
  }
  //if 0 is returned there is nothing to read which is good since no posts have 0 ID
  return currPostID;
}














/////Done
