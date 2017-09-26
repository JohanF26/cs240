#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#include "DonorDatabase.h"
#include "string"

using namespace std;

void main(int argc, char *argv[]){
  if(argc != 1 && argc <= 3 && isdigit(argv[2])){
    //using command line arguments
    int maxSize = atoi(argv[2]);

    if(maxSize >= 1 && maxSize <= 1000){
      DonorDatabase *db_ptr = new DonorDatabase(maxSize);

      if(argc == 3 && argv[3].substr(argv[3].length() - 4, 4) == ".txt"){

      }

      //main menu
      bool continue_program = true;
      string com;
      while(continue_program){
        cout << "\nEnter a command.\nChoose from [\"Login\" \"Add\" \"Save\" \"Load\" \"Report\" \"Quit\"]\n";
        cout << ": ";
        cin >> com;
        if(com == "Quit"){
          db_ptr->quit();
          continue_program = false;
        } else if(com == "Login"){
          db_ptr->login();
        } else if(com == "Add"){
          db_ptr->add();
        } else if(com == "Save"){
          db_ptr->save();
        } else if(com == "Load"){
          db_ptr->load();
        } else if(com == "Report"){
          db_ptr->report();
        } else{
          cout << "Command not recognized. Please try again.\n";
        }
      }
    }
  }

  return 0;
}
