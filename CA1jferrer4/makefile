#Specify the target
all:  Donate

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Donate:  CA1.o FerrerasJohanDonorFunctions.o
				g++  FerrerasJohanDonorFunctions.o CA1.o  -o Donate

# Specify how the object files should be created from source files
FerrerasJohanDonorFunctions.o:        FerrerasJohanDonorFunctions.cpp
				g++ -c FerrerasJohanDonorFunctions.cpp

CA1.o:  CA1.cpp
				g++ -c CA1.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
				rm -f *.o Donate
