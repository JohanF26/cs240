#include <iostream>
#include <stdlib.h>
#include "FBLUser.h"
#include "FBLUserLL.h"
#include "FBLUserNode.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "Facebook Lite Version" << "\n---------------" << endl;
    FBLUserLL* userList = new FBLUserLL();
    string command;
    //it is not possible to pass cin directly to a function so I will
    //have to create temporary variables for input
    string first;
    string last;
    string userID;
    string password;
    string tempPost;
    string tempComment;
    string friendID;
    int uniqueID = 0;
    unsigned int currPostID = 0;
    bool postFound = false;
    while(command != "QUIT"){
      //First Level Menu
      cout << "Enter a command.\nChoose from the following commands:\n\"CREATE <user id> <password> <first name> <last name>\"\n\"LOGIN <user id> <password>\"\n\"USERS\"\n\"SORTUSERS\"\n\"QUIT\"\n---------------" << endl;
      cin >> command;
      cout << "---------------" << endl;
      if(command == "CREATE"){
        //get input separated by whitespace
        cin >> userID;
        cin >> password;
        cin >> first;
        cin >> last;
        //create a user with this information
        userList->create(first, last, userID, password);
      } else if(command == "LOGIN"){
        cin >> userID;
        cin >> password;
        //login returns user or nullptr to keep menus in the driver file
        FBLUser* loggedUser = userList->login(userID, password);
        if(loggedUser != nullptr){
          //Second Level Menu
          cout << "Successfully logged in.\n---------------" << endl;
          while(command != "LOGOUT"){
            cout << "Enter a command.\nChoose from the following commands:\n\"LOGOUT\"\n\"POST <text>\"\n\"READ\"\n\"FRIEND <userid>\"\n\"MYFRIENDS\"\n\"MYFEED\"\n\"MYWALL\"\n---------------" << endl;
            cin >> command;
            cout << "---------------" << endl;
            if(command == "POST"){
              getline(cin, tempPost);
              //create new post and add it to linked list
              //make a new post ID and give it to post for our wall and friends feed
              uniqueID++;
              FBLPost* newPost = new FBLPost(tempPost, uniqueID);
              FBLPostNode* newPostNode = new FBLPostNode(newPost);
              loggedUser->getWall()->insertPost(newPostNode);

              //add post to the feed of each friend and every post will have the same ID
              for(int i = 0; i < loggedUser->getUserFriends().size(); i++){
                FBLPost* forFriend = new FBLPost(tempPost, uniqueID);
                FBLPostNode* newForFriend = new FBLPostNode(forFriend);
                loggedUser->getUserFriends()[i]->getFeed()->insertPost(newForFriend);
              }
              cout << "Successfully posted!\n---------------" << endl;
            } else if(command == "READ"){
              //read a post and retrieve its unique ID
              currPostID = loggedUser->getFeed()->readPost();
              if(currPostID != 0){
                string postCommand = "";
                while(postCommand != "DONE"){
                  cout << "What would you like to do with this post?:\n\"LIKE\"\n\"COMMENT <text>\"\n\"READ_AZ\"\n\"READ_ZA\"\n\"DONE\"\n---------------" << endl;
                  cin >> postCommand;
                  cout << "---------------" << endl;
                  if(postCommand == "LIKE"){
                    //go through EACH post of EACH user
                    postFound = false;
                    FBLUserNode* uNIterator = userList->getHead();
                    FBLPostNode* pNIterator;
                    while(uNIterator!= nullptr){
                      //get the first post in current user's post linked list
                      pNIterator = uNIterator->getUser()->getWall()->getHead();
                      while(pNIterator != nullptr){
                        if(pNIterator->getPost()->getPostID() == currPostID){
                          //if the ID matches then like that post and break
                          pNIterator->getPost()->likePost();
                          postFound = true;
                          break;
                        }
                        //if post isnt found go to the next post
                        pNIterator = pNIterator->getNextPost();
                      }
                      if(postFound){
                        //if post is found there is no need to get next user
                        break;
                      }
                      //if post is not found get the next user node
                      uNIterator = uNIterator->getNextUser();
                    }
                  } else if(postCommand == "COMMENT"){
                    getline(cin, tempComment);
                    postFound = false;
                    FBLUserNode* uNIterator = userList->getHead();
                    FBLPostNode* pNIterator;
                    while(uNIterator!= nullptr){
                      //get the first post in current user's post linked list
                      pNIterator = uNIterator->getUser()->getWall()->getHead();
                      while(pNIterator != nullptr){
                        if(pNIterator->getPost()->getPostID() == currPostID){
                          //if the ID matches then like that post and break
                          pNIterator->getPost()->commentPost(tempComment, loggedUser->getFirst(), loggedUser->getLast());
                          postFound = true;
                          break;
                        }
                        //if post isnt found go to the next post
                        pNIterator = pNIterator->getNextPost();
                      }
                      if(postFound){
                        //if post is found there is no need to get next user
                        break;
                      }
                      //if post is not found get the next user node
                      uNIterator = uNIterator->getNextUser();
                    }
                    cout << "Comment successfuly added!\n---------------" << endl;
                  } else if(postCommand == "READ_AZ"){
                    postFound = false;
                    FBLUserNode* uNIterator = userList->getHead();
                    FBLPostNode* pNIterator;
                    while(uNIterator!= nullptr){
                      //get the first post in current user's post linked list
                      pNIterator = uNIterator->getUser()->getWall()->getHead();
                      while(pNIterator != nullptr){
                        if(pNIterator->getPost()->getPostID() == currPostID){
                          //if the ID matches then like that post and break
                          pNIterator->getPost()->printCommentsAZ();
                          postFound = true;
                          break;
                        }
                        //if post isnt found go to the next post
                        pNIterator = pNIterator->getNextPost();
                      }
                      if(postFound){
                        //if post is found there is no need to get next user
                        break;
                      }
                      //if post is not found get the next user node
                      uNIterator = uNIterator->getNextUser();
                    }
                  } else if(postCommand == "READ_ZA"){
                    postFound = false;
                    FBLUserNode* uNIterator = userList->getHead();
                    FBLPostNode* pNIterator;
                    while(uNIterator!= nullptr){
                      //get the first post in current user's post linked list
                      pNIterator = uNIterator->getUser()->getWall()->getHead();
                      while(pNIterator != nullptr){
                        if(pNIterator->getPost()->getPostID() == currPostID){
                          //if the ID matches then like that post and break
                          pNIterator->getPost()->printCommentsZA();
                          postFound = true;
                          break;
                        }
                        //if post isnt found go to the next post
                        pNIterator = pNIterator->getNextPost();
                      }
                      if(postFound){
                        //if post is found there is no need to get next user
                        break;
                      }
                      //if post is not found get the next user node
                      uNIterator = uNIterator->getNextUser();
                    }
                  } else if(postCommand != "DONE"){
                    cout << "Command not supported. Please try again.\n---------------" << endl;
                  }
                }
              }
            } else if(command == "FRIEND"){
              //get friend's ID from command line
              cin >> friendID;
              //no need to check if head is nullptr because if we are logged in
              //then there has to be at least a one user in the list
              FBLUserNode* tempNode = userList->getHead();
              FBLUser* tempUser = tempNode->getUser();
              while(tempUser != nullptr){
                //if this ID matches the ID of a user
                if(friendID == tempUser->getUserID()){
                  //add add to each other's friend list and return true if successful
                  if(loggedUser->befriend(tempUser)){
                    tempUser->befriend(loggedUser);
                    cout << tempUser->getFirst() << " " << tempUser->getLast() << " is now your friend!" << "\n---------------" << endl;
                  }
                  //break because otherwise it will be an infinite loop
                  break;
                } else{
                  //if not then update the node and redefine the user
                  tempNode = tempNode->getNextUser();
                  if(tempNode != nullptr){
                    tempUser = tempNode->getUser();
                  } else{
                    tempUser = nullptr;
                  }
                }
              }
              //this will be true when no one with this ID is found
              if(tempUser == nullptr){
                cout << "This user does not exist" << "\n---------------" << endl;
              }
            } else if(command == "MYFRIENDS"){
              //print out friend list
              loggedUser->printFriends();
            } else if(command == "MYFEED"){
              //print out friend list
              loggedUser->printFeed();
            } else if(command == "MYWALL"){
              //print out friend list
              loggedUser->printWall();
            } else if(command != "LOGOUT"){
              cout << "Command not supported. Please try again.\n---------------" << endl;
            } else{

            }
          }
        }
      } else if(command == "USERS"){
        FBLUserNode* uNIterator = userList->getHead();
        while(uNIterator!= nullptr){
          cout << uNIterator->getUser()->getLast() << ", " << uNIterator->getUser()->getFirst() << " <" << uNIterator->getUser()->getUserID() << ">" << endl;
          uNIterator = uNIterator->getNextUser();
        }
        cout << "---------------" << endl;
      } else if(command == "SORTUSERS"){
        FBLUserNode* it1 = nullptr;
        FBLUserNode* it2 = userList->getHead();
        FBLUserNode* it3 = it2->getNextUser();

        FBLUserNode* beforeMin = nullptr;
        FBLUserNode* minNode = userList->getHead();
        FBLUserNode* afterMin = nullptr;
        if(minNode != nullptr){
          afterMin = minNode->getNextUser();
        }

        FBLUserNode* lastObject = nullptr;

        FBLUserLL* newUserList = new FBLUserLL();

        while(it2 != nullptr){
          it1 = nullptr;
          it2 = userList->getHead();
          it3 = it2->getNextUser();

          beforeMin = nullptr;
          minNode = userList->getHead();
          afterMin = nullptr;
          if(minNode != nullptr){
            afterMin = minNode->getNextUser();
          }

          lastObject = nullptr;
          //loop to set minNode to smallest element
          while(it2!= nullptr){
            if(it2->getUser()->getLast() < minNode->getUser()->getLast()){
              beforeMin = it1;
              minNode = it2;
              afterMin = it3;
            }
            it1 = it2;
            it2 = it3;
            if(it3 != nullptr){
              it3 = it3->getNextUser();
            }
          }

          minNode->setNextUser(nullptr);
          if(newUserList->getHead() == nullptr){
            newUserList->setHead(minNode);
          } else {
            lastObject = newUserList->getHead();
            while(lastObject->getNextUser() != nullptr){
              lastObject = lastObject->getNextUser();
            }
            //add next smallest object to the new list
            lastObject->setNextUser(minNode);
          }
          //mends gap in original list
          if(beforeMin != nullptr){
            beforeMin->setNextUser(afterMin);
          } else {
            userList->setHead(afterMin);
          }
          it2 = userList->getHead();
        }

        if(newUserList->getHead() != nullptr){
          userList = newUserList;
        }

      } else if(command != "QUIT"){
        cout << "Command not supported. Please try again.\n---------------" << endl;
      }
    }
    delete userList;
}






/////
