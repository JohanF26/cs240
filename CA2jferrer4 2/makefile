all:	Donation

Donation:	Donor.o DonorDatabase.o manager.o
			g++ Donor.o DonorDatabase.o manager.o -o Donor

Donor.o:	Donor.cpp
			g++ -c Donor.cpp

DonorDatabase.o: DonorDatabase.cpp
			g++ -c DonorDatabase.cpp

manager.o: manager.cpp
			g++ -c manager.cpp

clean:
			rm -f *.o Donor
