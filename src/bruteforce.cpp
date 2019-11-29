#include "../include/bruteforce.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <float.h>
#include <chrono>

/**
* Runs the bruteforce algorithm on size 'n'
*/
Bruteforce::Bruteforce(int input) {
    int N = input;
    std::vector<Point> p;

    std::string filename = "output.txt";
    filename.insert(6, std::to_string(N));

    std::ifstream file;
    file.open(filename);

    for(int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p.push_back(temp);
    }

    auto begin = std::chrono::high_resolution_clock::now();

    double minDistance = DBL_MAX;
    int idxA;
    int idxB;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
	        double currDistance = distance(p[i],p[j]);
	        if(currDistance<minDistance && currDistance != 0){
	            minDistance=currDistance;
	            idxA = i;
	            idxB = j;
	        }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    // std::cout << "Minimum Distance is " << minDistance << " between points ";
    // std::cout << p[idxA].x << "," << p[idxA].y << " and "<< p[idxB].x << "," << p[idxB].y << std::endl;
    // std::cout << "Time taken: " << ms << "us" << std::endl;

    ans = ms;

}

/**
* Destructor
*/
Bruteforce::~Bruteforce(){}

/**
* Returns the distance between two given points
*/
double Bruteforce::distance(Point& a, Point& b) {
   return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
