all: bruteforce divideconquer create

bruteforce: bruteforce.cpp
	g++ -std=c++11 -o bruteforce bruteforce.cpp -Wall

divideconquer: divideconquer.cpp
	g++ -std=c++11 -o divideconquer divideconquer.cpp -Wall

create: create.cpp
	g++ -std=c++11 -o create create.cpp -Wall

.PHONY: clean
clean:
	rm -rf *~ *.o
