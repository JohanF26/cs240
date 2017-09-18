#include <iostream>
#include <stdlib.h>
#include "string"
#include "Donor.h"

using namespace std;

int main(int argc, char *argv[]){
    bool continue_program = true;
    string com;
    Donor *donor_ptr = new Donor();
    while(continue_program){
        cout << "\nEnter a command.\nChoose from [\"Add\" \"Manage\" \"View\" \"Donate\" \"Total\" \"Quit\"]\n";
        cout << ": ";
        cin >> com;
        if(com == "Quit"){
            continue_program = false;
        } else if(com == "Add"){
        	donor_ptr = new Donor();
            donor_ptr->add();
        } else if(com == "Manage"){
            donor_ptr->manage();
        } else if(com == "View"){
            donor_ptr->view();
        } else if(com == "Donate"){
            donor_ptr->donate();
        } else if(com == "Total"){
            donor_ptr->total();
        } else{
            cout << "Command not recognized. Please try again.\n";
        }
    }
    return 0;
}
