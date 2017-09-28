#include <iostream>
#include <stdlib.h>
#include "string"
#include "Donor.h"
#include "state.h"

using namespace std;

class DonorDatabase{
	private:
		Donor* donorList;
		int maximumSize;
		int donorsInBase;
		float totalDonated;
		
	public:
    	DonorDatabase(int dbSize);

    	void login();
		void add();
		void save(string outputFile);
		void load(string inputFile);
		void report();
		bool usernameAvailable();

		Donor* getDonorList();

	

};
