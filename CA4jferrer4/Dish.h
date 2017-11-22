#include <iostream>
#include <stdlib.h>
#include "string"
#include "vector"

using namespace std;

class Dish {
private:
  string stringArr[1024];
  int size;

  int alphaHeap[1024];
  int lenHeap[1024];

public:
  Dish();

  int insert(string s);
  int find(string s);
  bool capitalize(int k);
  bool allcaps(int k);
  bool truncate(int k, int i);
  string getshortest();
  string getfirst();
  string* getStringArr();
  int* getAlphaArr();
  int* getLenArr();

  void maxHeapifyAlpha(int heap[], int i);
  void buildMaxAlphaHeap(int heap[]);

  void maxHeapifyLen(int heap[], int i);
  void buildMaxLenHeap(int heap[]);

};
