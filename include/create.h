#ifndef CREATE
#define CREATE

/**
* Definition of a 'Point'
*/
struct Point {
   double x;
   double y;
};

class Create {
  public:
    /**
    * Runs the point creator algorithm with a size 'n'
    */
    Create(int input);

    /**
    * Destructor
    */
    ~Create();
};

#endif
