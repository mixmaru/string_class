a.out: main.o str.o
	g++ -Wall -o a.out main.o str.o
main.o: main.cpp
	g++ -Wall -c main.cpp
str.o: str.cpp
	g++ -Wall -c str.cpp

deb_a.out: deb_main.o deb_str.o
	g++ -g -O0 -Wall -o deb_a.out deb_main.o deb_str.o
deb_main.o: main.cpp
	g++ -g -O0 -Wall -c -o deb_main.o main.cpp 
deb_str.o: str.cpp
	g++ -g -O0 -Wall -c -o deb_str.o str.cpp


clean:
	rm -f *.o a.out
