a.out: main.o str.o
	g++ -Wall -o a.out main.o str.o
main.o: main.cpp
	g++ -Wall -c main.cpp
str.o: str.cpp
	g++ -Wall -c str.cpp
clean:
	rm -f *.o a.out
