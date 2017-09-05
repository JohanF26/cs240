#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Ferreras_Johan_jferrer4_Hello.o Hello_Class.o
	g++  Ferreras_Johan_jferrer4_Hello.o Hello_Class.o  -o Ferreras_Johan_jferrer4_Hello.exe

# Specify how the object files should be created from source files
Ferreras_Johan_jferrer4_Hello.o:	Ferreras_Johan_jferrer4_Hello.cpp Hello_Class.cpp
	g++ -c Ferreras_Johan_jferrer4_Hello.cpp
	
Hello_Class.o:	Hello_Class.cpp
	g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Ferreras_Johan_jferrer4_Hello.exe

