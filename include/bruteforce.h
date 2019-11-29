#ifndef BRUTEFORCE
#define BRUTEFORCE

#include "./create.h"

class Bruteforce {
 public:
   /**
   * Runs the bruteforce algorithm on size 'n'
   */
   Bruteforce(int input);

   /**
   * Destructor
   */
   ~Bruteforce();

   /**
   * Total time taken.
   * To be used in main function
   */
   long long ans;

 private:
   /**
   * Returns the distance between two given points
   */
   double distance(Point& a, Point& b);

};

#endif
