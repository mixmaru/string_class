a.out: main.cpp str.cpp
	c++ -Wall -o a.out main.o str.o
main.o: main.cpp
	c++ -Wall -c main.cpp
str.o: str.cpp
	c++ -Wall -c hello.cpp
clean:
	rm -f *.o a.out
