#include <iostream>
#include <stdlib.h>

using namespace std;

int nMultOf3(int n, int counter){
  if(n == counter){
    cout << 3 * n << endl;
    return n*3;
  } else{
    cout << 3 * counter << endl;
    return nMultOf3(n, counter+1);
  }
}

int main(int argc, char* argv[]){
  int input;
  if(argc == 1){
    cout << "Please input n as a command line input" << endl;
  } else if(argc == 2){
    input = atoi(argv[1]);
    nMultOf3(input, 0);
  } else{
    cout << "Too many arguments" << endl;
  }
  return 0;
}
