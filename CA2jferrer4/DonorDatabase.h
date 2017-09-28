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
		void save(string outputFile);
		void load(string inputFile);
		void report();
		bool usernameAvailable();

	Donor[] getDonorList();

	private:
		Donor* donorList;
		int maximumSize;
		int donorsInBase;
		float totalDonated;

};
