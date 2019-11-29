#ifndef BRUTEFORCE
#define BRUTEFORCE

#include "./create.h"

class Bruteforce {
 public:
   Bruteforce(int input);

   ~Bruteforce();

   long long ans;
   
 private:
   double distance(Point& a, Point& b);

};

#endif
