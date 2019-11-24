all: bruteforce divideconquer create

.PHONY: bruteforce
bruteforce: bruteforce.cpp
	g++ -std=c++11 -o bruteforce bruteforce.cpp -Wall

.PHONY: divideconquer
divideconquer: divideconquer.cpp
	g++ -std=c++11 -o divideconquer divideconquer.cpp -Wall

.PHONY: create
create: create.cpp
	g++ -std=c++11 -o create create.cpp -Wall

.PHONY: clean
clean:
	rm -rf *~ *.o *.txt
