#include <iostream>
#include <stdlib.h>
//#include "string"
//#include "FBLPost.h"
//#include "FBLPostLL.h"
//#include "FBLPostNode.h"
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
    string friendID;
    while(command != "QUIT"){
      //First Level Menu
      cout << "Enter a command.\nChoose from the following commands:\n\"CREATE <user id> <password> <first name> <last name>\"\n\"LOGIN <user id> <password>\"\n\"QUIT\"\n---------------" << endl;
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
              FBLPost* newPost = new FBLPost(tempPost);
              FBLPostNode* newPostNode = new FBLPostNode(newPost);
              loggedUser->getWall()->insertPost(newPostNode);

              FBLPost* forFriend = new FBLPost(tempPost);
              FBLPostNode* newForFriend = new FBLPostNode(forFriend);

              //add post to the feed of each friend
              for(int i = 0; i < loggedUser->getUserFriends().size(); i++){
                loggedUser->getUserFriends()[i]->getFeed()->insertPost(newForFriend);
              }
              cout << "Successfully posted!\n---------------" << endl;
            } else if(command == "READ"){
              loggedUser->getFeed()->readPost();
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
                  tempUser = tempNode->getUser();
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
            }
          }
        }
      } else if(command != "QUIT"){
        cout << "Command not supported. Please try again.\n---------------" << endl;
      }
    }
}






/////
