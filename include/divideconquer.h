#ifndef DIVIDECONQUER
#define DIVIDECONQUER

#include "./create.h"

class DivideConquer {
 public:
   /**
   * Runs the divideconquer algorithm on size 'n'
   */
   DivideConquer(int input, bool testing);

   /**
   * Destructor
   */
   ~DivideConquer();

   /**
   * Total time taken.
   * To be used in main function
   */
   long double ans1;

 private:
   /**
   * Returns the distance between two given points
   */
   double distance(Point& a, Point& b);

   /**
   * Implementation of the bruteforce version of this algorithm.
   * Used when arrays reach a small enough size (2 or 3)
   */
   minDistance bruteforce(Point p[], int n);

   /**
   * Recursive function to be called in main algorithm
   */
   minDistance closestPair(Point p[], int n);

};

#endif
