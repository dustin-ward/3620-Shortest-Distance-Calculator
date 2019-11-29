SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I {SRC_INCLUDE}

%.o: %.cpp
	g++ -std=c++11 -c $< -o $@

.PHONY: tests
tests: main.cpp $(SRC_DIR)
	g++ -std=c++11 $(INCLUDE) -o tests main.cpp \
	$(SRC_DIR)/*.cpp

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
	rm -rf *~ *.o *.txt *.
