#include "../include/divideconquer.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <float.h>
#include <chrono>

/**
* Runs the divideconquer algorithm on size 'n'
*/
DivideConquer::DivideConquer(int input, bool testing) {
    int N = input;
    Point* p = new Point[N];

    std::string filename = "output.txt";
    filename.insert(6, std::to_string(N));

    std::ifstream file;
    file.open(filename);

    for (int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p[i] = temp;
    }

    auto begin = std::chrono::high_resolution_clock::now();

    std::sort(p, p+N, [](Point const & a, Point const & b) -> bool
          { return a.x < b.x; });

    double ans = closestPair(p, N);

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    if(!testing) {
        std::cout << "Closest distance: " << ans << std::endl;
    }

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
double DivideConquer::bruteforce(Point p[], int n) {
    double minDistance = DBL_MAX;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            double temp = distance(p[i], p[j]);
            if (temp < minDistance) {
                minDistance = temp;
            }
        }
    }
    return minDistance;
}

/**
* Recursive function to be called in main algorithm
*/
double DivideConquer::closestPair(Point p[], int n) {
    if (n < 4) {
        return bruteforce(p, n);
    }

    double minDistance = std::min(closestPair(p, n/2), closestPair(p+(n/2), n-(n/2)));

    int m = 0;
    Point closePoints[n];
    for (int i=0; i<n; i++) {
        if (abs(p[i].x - p[n/2].x) < minDistance) {
            closePoints[m] = p[i];
            m++;
        }
    }

    std::sort(closePoints, closePoints+m, [](Point const & a, Point const & b) -> bool
          { return a.y < b.y; });

    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m && (closePoints[j].y - closePoints[i].y) < minDistance; j++) {
            double temp = distance(closePoints[i], closePoints[j]);
            if (temp < minDistance)
                minDistance = temp;
        }
    }

    return minDistance;
}
