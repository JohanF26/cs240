all: Dish

Dish: CA4.o Dish.o
			g++ CA4.o Dish.o -o Dish

CA4.o: CA4.cpp
			g++ -c -g CA4.cpp

Dish.o: Dish.cpp
			g++ -c -g Dish.cpp

clean:
				rm -f *.o Dish
				cd ..; \
				rm -f Ferreras_Johan_jferrer4_CA4.tar.gz

compress: clean
				cd ..; \
				tar -cvvf Ferreras_Johan_jferrer4_CA4.tar CA4jferrer4
				cd ..; \
				gzip Ferreras_Johan_jferrer4_CA4.tar
