#include <iostream>
#include "./include/create.h"
#include "./include/bruteforce.h"
#include "./include/divideconquer.h"
using namespace std;

/**
* Helper function that runs both algorithms with the same point size.
* Prints out the average time taken by both algorithms.
*/
void run(int n, int p) {
  long double bSum=0;
  long double dSum=0;
  cout << "=================== " << n << " ===================" << endl;
  /**
  * Run the point generator with size 'n'
  */
  Create c(n);

  /**
  * Run the bruteforce algorithm 'p' times on size 'n'.
  * Then print the average time taken.
  */
  cout << "Bruteforce: ";
  for(int i=0; i<p; i++) {
    Bruteforce b(n, true);
    bSum += b.ans;
  }
  long double bAvg = bSum/p;
  if (bAvg > 9999) {
    bAvg /= 1000;
    cout << bAvg << "ms" << endl;
  }
  else {
    cout << bAvg << "us" << endl;
  }

  /**
  * Run the divide & conquer algorithm 'p' times on size 'n'.
  * Then print the average time taken.
  */
  cout << "\nDivide and Conquer: ";
  for(int i=0; i<p; i++) {
    DivideConquer d(n, true);
    dSum += d.ans1;
  }
  long double dAvg = dSum/p;
  if (dAvg > 9999) {
    dAvg /= 1000;
    cout << dAvg << "ms" << endl;
  }
  else {
    cout << dAvg << "us" << endl;
  }
}

/**
* Main responsible for user input
*/
int main() {
  int num;
  int pres;

  cout << "Enter the number of points to run both algorithms on, followed by the number of times to run the test: (Type -1 to stop)";
  cin>>num;
  while(num > 1) {
    cin>>pres;
    run(num, pres);
    cout << "\nEnter the number of points to run both algorithms on, followed by the number of times to run the test: (Type -1 to stop)";
    cin>>num;
  }

  return 0;
}
