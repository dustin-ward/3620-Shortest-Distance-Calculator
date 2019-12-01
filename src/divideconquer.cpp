#include "../include/divideconquer.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <float.h>
#include <chrono>
#include "../include/create.h"

/**
* Runs the divideconquer algorithm on size 'n'
*/
DivideConquer::DivideConquer(int input, bool testing) {
    int N = input;
    // Create empty Point array
    Point* p = new Point[N];

    // Find the correct input file
    std::string filename = "output.txt";
    filename.insert(6, std::to_string(N));

    // Open file
    std::ifstream file;
    file.open(filename);

    // Fill array with Points from file
    for (int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p[i] = temp;
    }

    // Start clock
    auto begin = std::chrono::high_resolution_clock::now();

    // Sort all Points by x value. Ascending
    std::sort(p, p+N, [](Point const & a, Point const & b) -> bool
          { return a.x < b.x; });

    // Begin the recursive process
    minDistance ans = closestPair(p, N);

    // End the timer and calculate time taken
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    // If testing is false, output the distance info
    if(!testing) {
        std::cout << "Minimum Distance is " << ans.val << " between points ";
        std::cout << ans.p1.x << "," << ans.p1.y << " and "<< ans.p2.x << "," << ans.p2.y << std::endl;
    }

    // Store time taken in class
    ans1 = ms;

    delete[] p;
}

/**
* Destructor
*/
DivideConquer::~DivideConquer(){}

/**
* Returns the distance between two given points
*/
double DivideConquer::distance(Point& a, Point& b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

/**
* Implementation of the bruteforce version of this algorithm.
* Used when arrays reach a small enough size (2 or 3)
*/
minDistance DivideConquer::bruteforce(Point p[], int n) {
    // Initialize a max value to compare against
    minDistance min = {
        DBL_MAX
    };

    // For each point, check the distance to all other points
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            // Calculate distance between i & j
            minDistance temp = {
                distance(p[i], p[j])
            };
            // If the distance between i & j is smaller than the previous minimum,
            // i -> j is the new minimum
            if(temp.val < min.val) {
                min = {
                    temp.val,
                    {
                        p[i].x,
                        p[i].y
                    },
                    {
                        p[j].x,
                        p[j].y
                    }
                };
            }
        }
    }
    return min;
}

/**
* Recursive function to be called in main algorithm
*/
minDistance DivideConquer::closestPair(Point p[], int n) {
    // If the size of the array is less than 4, run the bruteforce algorithm
    if (n < 4) {
        return bruteforce(p, n);
    }

    // Calculate the minimum distance on the left and right half of the array
    minDistance l = closestPair(p, n/2);
    minDistance r = closestPair(p+(n/2), n-(n/2));
    minDistance min;
    // Take the minimum of the left and right
    if(l.val > r.val)
        min = r;
    else
        min = l;

    // Pickup all points that are less than the minimum distance away from the center
    int m = 0;
    Point closePoints[n];
    for (int i=0; i<n; i++) {
        if (abs(p[i].x - p[n/2].x) < min.val) {
            closePoints[m] = p[i];
            m++;
        }
    }

    // Sort the middle points by y value. Ascending
    std::sort(closePoints, closePoints+m, [](Point const & a, Point const & b) -> bool
          { return a.y < b.y; });

    // For each of the middle points, check if the distance between them is less than
    // the current minimum. It is proven that there is a maximum of 6 points that can
    // be considered valid, so runnning an n^2 solution here does not impact performance
    // in a meaningful way
    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m && (closePoints[j].y - closePoints[i].y) < min.val; j++) {
            minDistance temp = {
                distance(closePoints[i], closePoints[j])
            };
            if (temp.val < min.val) {
                min = {
                    temp.val,
                    {
                        closePoints[i].x,
                        closePoints[i].y
                    },
                    {
                        closePoints[j].x,
                        closePoints[j].y
                    }
                };
            }
        }
    }

    return min;
}
