# Shortest Distace Calculator #
                                                                                   


## Make targets ##

clean : Remove all generated files from the directory

bruteforce : Interface for running the Brute-Force implementation

divideconquer : Interface for running the Divide & Conquer implementation

tests : Interface for testing both implementations at the same time with precision

## Using the Interfaces ##

### Brute-Force / Divide & Conquer ###

After running the program, the user will be promted to input an integer 'n'.
This is the number of points that the user wishes to generate and run the algorithm on.
The algorithm will then generate 'n' points between -10000 and 10000, and run the algorithm to determine
the smallest distance.
The program terminates when the user inputs '-1'

### Tests ###

The testing interface will also promt the user for an integer 'n', but also a precision value 'p'.
This precision is the number of times that the algorithm is run. The final result is then an average of
'p' runs of each algorithm.
The program terminates when the user inputs '-1'
