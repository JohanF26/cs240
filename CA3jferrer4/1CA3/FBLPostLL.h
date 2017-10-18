#include <iostream>
#include <stdlib.h>
#include "string"
#include "FBLPostNode.h"
#ifndef FBLPOSTLL_H
#define FBLPOSTLL_H

using namespace std;

class FBLPostLL{
	private:
		//This LL only needs a head for now
		FBLPostNode* head;

	public:
		FBLPostLL();
		FBLPostLL(FBLPostNode* p);

		FBLPostNode* getHead();

		//put post into linked list
		void insertPost(FBLPostNode* p);

		//read post and remove it from list
		void readPost();

};

#endif
