#ifndef DIVIDECONQUER
#define DIVIDECONQUER

#include "./create.h"

class DivideConquer {
 public:
   DivideConquer(int input);

   ~DivideConquer();

   int ans;

 private:
   double distance(Point& a, Point& b);

   bool comparePointX(Point a, Point b);

   bool comparePointY(Point a, Point b);

   double bruteforce(Point p[], int n);

   double closestPair(Point p[], int n);

};

#endif
