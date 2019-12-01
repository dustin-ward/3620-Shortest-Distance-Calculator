#include "../include/bruteforce.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <float.h>
#include <chrono>
#include "../include/create.h"

/**
* Runs the bruteforce algorithm on size 'n'
*/
Bruteforce::Bruteforce(int input, bool testing) {
    int N = input;
    // Create empty Point vector
    std::vector<Point> p;

    // Find the correct input file
    std::string filename = "output.txt";
    filename.insert(6, std::to_string(N));

    // Open file
    std::ifstream file;
    file.open(filename);

    // Fill array with Points from file
    for(int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p.push_back(temp);
    }

    // Start clock
    auto begin = std::chrono::high_resolution_clock::now();

    // For each point, check the distance to all other points
    minDistance min = {
        DBL_MAX
    };
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // Calculate distance between i & j
	        minDistance currDistance = {
                distance(p[i],p[j])
            };
            // If the distance between i & j is smaller than the previous minimum,
            // i -> j is the new minimum
	        if(currDistance.val < min.val && currDistance.val != 0){
	            min = {
                    currDistance.val,
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

    // End the timer and calculate time taken
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    // If testing is false, output the distance info
    if (!testing) {
        std::cout << "Minimum Distance is " << min.val << " between points ";
        std::cout << min.p1.x << "," << min.p1.y << " and "<< min.p2.x << "," << min.p2.y << std::endl;
    }

    // Store time taken in class
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
