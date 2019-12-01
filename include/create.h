#ifndef CREATE
#define CREATE

/**
* Definition of a 'Point'
*/
struct Point {
   double x;
   double y;
};

/**
* Definition of a Minimum Distance
* Holds the pair of points with the distance
*/
struct minDistance {
    double val;
    Point p1;
    Point p2;
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
