#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#include "DonorDatabase.h"
#include <string.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	bool numArg = true;
	for(int i = 0; i < strlen(argv[1]); i++){
  		if(!isdigit(argv[1][i])){
  			numArg = false;
  		}
  	}
  	
  if(argc != 1 && argc <= 3 && numArg){
    //using command line arguments
    int maxSize = atoi(argv[1]);

    if(maxSize >= 1 && maxSize <= 1000){
      DonorDatabase *db_ptr = new DonorDatabase(maxSize);

      if(argc == 3){
        string inputFile = argv[2];
        db_ptr->load(inputFile);
      }

      //main menu
      bool continue_program = true;
      string com = "";
      string outputFile = "";
      string inputFile = "";
      while(continue_program){
        cout << "DONOR DATABASE\n";
        cout << "\nEnter a command.\nChoose from [\"Login\" \"Add\" \"Save\" \"Load\" \"Report\" \"Quit\"]\n";
        cout << ": ";
        cin >> com;
        if(com == "Quit"){
          cout << "Quitting program";
          continue_program = false;
        } else if(com == "Login"){
          db_ptr->login();
        } else if(com == "Add"){
          db_ptr->add();
        } else if(com == "Save"){
          cout << "What is the name of the file you would like to save to?";
          cin >> outputFile;
          db_ptr->save(outputFile);
        } else if(com == "Load"){
          cout << "What is the name of the file you would like to load from?";
          cin >> inputFile;
          db_ptr->load(inputFile);
        } else if(com == "Report"){
          db_ptr->report();
        } else{
          cout << "Command not recognized. Please try again.\n";
        }
      }
    } else {
      cout << "Size of donor database should be between 1 and 1000 donors.";
    }
  } else {
    cout << "Invalid number of arguments or one of the arguments is an invalid type, try again.";
  }

  return 0;
}
