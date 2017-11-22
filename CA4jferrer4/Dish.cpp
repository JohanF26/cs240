#include <iostream>
#include <stdlib.h>
#include "string"
#include "vector"
#include "Dish.h"
#include <locale>
#include <math.h>

using namespace std;

Dish::Dish(){
  size = 0;
}

int Dish::insert(string s){
  //cout << "Pushing" << endl;
  //cout << s << endl;
  stringArr[size] = s;
  //cout << "after pushing" << endl;
  alphaHeap[size] = size;
  //cout << "after pushing ALPHA" << endl;
  lenHeap[size] = size;
  //cout << "after pushing len" << endl;
  size += 1;

  buildMaxAlphaHeap(alphaHeap);
  //cout << "after alpha heap" << endl;
  buildMaxLenHeap(lenHeap);
  //cout << "after len heap" << endl;

  return size-1;
}

int Dish::find(string s){
  for(int i = 0; i < size; i++){
    if(stringArr[i] == s){
      return i;
    }
  }
  return -1;
}

bool Dish::capitalize(int k){
  bool retVal = false;
  if(k < size){
    stringArr[k][0] = toupper(stringArr[k][0]);
    maxHeapifyLen(lenHeap, k);
    maxHeapifyAlpha(alphaHeap, k);
    retVal = true;
  }
  return retVal;
}

bool Dish::allcaps(int k){
  bool retVal = false;
  if(k < size){
    for(int i = 0; i < stringArr[k].length(); i++){
      stringArr[k][i] = toupper(stringArr[k][i]);
    }
    //use_facet<ctype<char>> (locale()).toupper(&stringArr.at(k)[0], &stringArr.at(k)[0] + stringArr.at(k).size());
    maxHeapifyLen(lenHeap, k);
    maxHeapifyAlpha(alphaHeap, k);
    retVal = true;
  }
  return retVal;
}

bool Dish::truncate(int k, int i){
  bool retVal = false;
  if(k < size){
    stringArr[k] = stringArr[k].substr(0, i);
    maxHeapifyLen(lenHeap, k);
    maxHeapifyAlpha(alphaHeap, k);
    retVal = true;
  }
  return retVal;
}

string Dish::getshortest(){
  return stringArr[lenHeap[size-1]];
}

string Dish::getfirst(){
  return stringArr[alphaHeap[size-1]];
}

string* Dish::getStringArr(){
  return stringArr;
}

int* Dish::getAlphaArr(){
  return alphaHeap;
}

int* Dish::getLenArr(){
  return lenHeap;
}

//Heap Functions
void Dish::maxHeapifyAlpha(int heap[], int i){
  int l = (2*i)+1;
  int r = (2*i)+2;
  int largest;
  //cout << "1" << endl;
  //cout << l << endl;
  //cout << size << endl;
  //cout << stringArr[heap[i]] << endl;
  //cout << heap[i] << endl;
  //cout << i << endl;
  //cout << l << endl;
  //cout << heap[l] << endl;
  //cout << stringArr[heap[l]] << endl;

  if(l <= (size-1)){
    if(stringArr[heap[l]] > stringArr[heap[i]]){
      //cout << "1.1" << endl;
      largest = l;
    } else{
      //cout << "1.2" << endl;
      largest = i;
    }
  } else{
    //cout << "1.2" << endl;
    largest = i;
  }
  //cout << "2" << endl;
  if(r <= (size-1)){
      if(stringArr[heap[r]] > stringArr[heap[largest]]){
      largest = r;
    }
  }
  //cout << "3" << endl;
  if(largest != i){
    //swap root with largest
    int temp = heap[i];
    heap[i] = heap[largest];
    heap[largest] = temp;
    //cout << "4" << endl;
    maxHeapifyAlpha(heap, largest);
    //cout << "5" << endl;
  }
}

void Dish::buildMaxAlphaHeap(int heap[]){
  for(int i = floor((size-1)/2); i > 0; i--){
    //cout << "build alpha " << i << endl;
    maxHeapifyAlpha(heap, i);
    //cout << "after heapify alpha " << i << endl;
  }
}

void Dish::maxHeapifyLen(int heap[], int i){
  int l = (2*i)+1;
  int r = (2*i)+2;
  int largest;

  //cout << l << endl;
  //cout << size << endl;

  if(l <= (size-1)){
    if(stringArr[heap[l]].length() > stringArr[heap[i]].length()){
      largest = l;
    } else{
      largest = i;
    }
  } else{
    largest = i;
  }
  if(r <= (size-1)){
    if(stringArr[heap[r]].length() > stringArr[heap[largest]].length()){
      largest = r;
    }
  }
  if(largest != i){
    //swap root with largest
    int temp = heap[i];
    heap[i] = heap[largest];
    heap[largest] = temp;
    maxHeapifyLen(heap, largest);
  }
}

void Dish::buildMaxLenHeap(int heap[]){
  for(int i = floor((size-1)/2); i > 0; i--){
    maxHeapifyLen(heap, i);
  }
}














////////////////
