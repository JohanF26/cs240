#include <iostream>
#include <stdlib.h>
#include "string"
#include "Donor.h"

using namespace std;

class DonorDatabase{
	public:
    DonorDatabase(int dbSize);

    void login();
		void add();
		void save();
		void load();
		void report();
		void quit();

	private:
		Donor donorList[1000];
		int maximumSize;
		int donorsInBase;
		float totalDonated;

};
