#include <iostream>
#include <stdlib.h>
//#include "string"
//#include "FBLPost.h"
//#include "FBLPostLL.h"
#include "FBLPostNode.h"
#include "FBLUser.h"
#include "FBLUserLL.h"
#include "FBLUserNode.h"

using namespace std;

int main(int argc, char *argv[]){
    cout << "Facebook Lite Version" << endl;
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
            cout << "Enter a command.\nChoose from the following commands:\n\"LOGOUT\"\n\"POST <text>\"\n\"READ\"\n\"FRIEND <userid>\"\"MYFRIENDS\"\"MYFEED\"\"MYWALL\"\n---------------" << endl;
            cin >> command;
            cout << "---------------" << endl;
            if(command == "POST"){
              getline(cin, tempPost);
              //create new post and add it to linked list
              FBLPost* newPost = new FBLPost(tempPost);
              FBLPostNode* newPostNode = new FBLPostNode(newPost);
              loggedUser->getWall()->insertPost(newPostNode);
              cout << "Successfully posted!\n---------------" << endl;
            } else if(command == "READ"){
              loggedUser->getWall()->readPost();
            } else if(command == "FRIEND"){
              //get friend's ID from command line
              cin >> friendID;
            } else if(command == "MYFRIENDS"){
              //print out friend list
            } else if(command == "MYFEED"){
              //print out friend list
            } else if(command == "MYWALL"){
              //print out friend list
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
