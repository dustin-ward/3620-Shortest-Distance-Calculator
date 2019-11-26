#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <float.h>
#include <chrono>
using namespace std;


struct Point {
   double x;
   double y;
};


double distance(Point& a, Point& b) {
   return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}


int main() {
    int N = 5000;
    vector<Point> p;

    string filename = "output.txt";
    filename.insert(6, to_string(N));

    ifstream file;
    file.open(filename);

    for(int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p.push_back(temp);
    }

    auto begin = chrono::high_resolution_clock::now();

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

    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    cout << "Minimum Distance is " << minDistance << " between points ";
    cout << p[idxA].x << "," << p[idxA].y << " and "<< p[idxB].x << "," << p[idxB].y << endl;
    cout << "Time taken: " << ms << "ms" << endl;
}
