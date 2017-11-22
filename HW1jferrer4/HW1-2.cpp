#include <iostream>
#include <stdlib.h>

using namespace std;

int nMultOf3rev(int n){
  if(n == 0){
    cout << 3 * n << endl;
    return n;
  } else{
    cout << 3 * n << endl;
    return nMultOf3rev(n-1);
  }
}

int main(int argc, char* argv[]){
  int input;
  if(argc == 1){
    cout << "Please input n as a command line input" << endl;
  } else if(argc == 2){
    input = atoi(argv[1]);
    nMultOf3rev(input);
  } else{
    cout << "Too many arguments" << endl;
  }
  return 0;
}
