
all: FBLite

FBLite: Driver.o FBLPost.o FBLPostLL.o FBLPostNode.o FBLUser.o FBLUserLL.o FBLUserNode.o
				g++ Driver.o FBLPost.o FBLPostLL.o FBLPostNode.o FBLUser.o FBLUserLL.o FBLUserNode.o -o FBLite

Driver.o: Driver.cpp
				g++ -c Driver.cpp

FBLPost.o: FBLPost.cpp
				g++ -c FBLPost.cpp

FBLPostLL.o: FBLPostLL.cpp
				g++ -c FBLPostLL.cpp

FBLPostNode.o: FBLPostNode.cpp
				g++ -c FBLPostNode.cpp

FBLUser.o: FBLUser.cpp
				g++ -c FBLUser.cpp

FBLUserLL.o: FBLUserLL.cpp
				g++ -c FBLUserLL.cpp

FBLUserNode.o: FBLUserNode.cpp
				g++ -c FBLUserNode.cpp

clean:
				rm -f *.o FBLite

compress: clean
				cd ..
				tar -cvvf Ferreras_Johan_jferrer4_CA3.tar CA3.1jferrer4
				gzip Ferreras_Johan_jferrer4_CA3.tar
