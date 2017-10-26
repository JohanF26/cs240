
all: FBLite

FBLite: Driver.o FBLPost.o FBLPostLL.o FBLPostNode.o FBLUser.o FBLUserLL.o FBLUserNode.o
				g++ Driver.o FBLPost.o FBLPostLL.o FBLPostNode.o FBLUser.o FBLUserLL.o FBLUserNode.o -o FBLite

Driver.o: Driver.cpp
				g++ -c -g Driver.cpp

FBLPost.o: FBLPost.cpp
				g++ -c -g FBLPost.cpp

FBLPostLL.o: FBLPostLL.cpp
				g++ -c -g FBLPostLL.cpp

FBLPostNode.o: FBLPostNode.cpp
				g++ -c -g FBLPostNode.cpp

FBLUser.o: FBLUser.cpp
				g++ -c -g FBLUser.cpp

FBLUserLL.o: FBLUserLL.cpp
				g++ -c -g FBLUserLL.cpp

FBLUserNode.o: FBLUserNode.cpp
				g++ -c -g FBLUserNode.cpp

clean:
				rm -f *.o FBLite
				cd ..; \
				cd ..; \
				rm -f Ferreras_Johan_jferrer4_CA3.tar.gz

compress: clean
				cd ..; \
				cd ..; \
				tar -cvvf Ferreras_Johan_jferrer4_CA3.tar CA3jferrer4
				cd ..; \
				cd ..; \
				gzip Ferreras_Johan_jferrer4_CA3.tar
