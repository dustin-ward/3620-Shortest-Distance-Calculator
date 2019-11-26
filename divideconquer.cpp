#include <iostream>
#include <fstream>
#include <algorithm>
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

bool comparePointX(Point a, Point b) {
    return a.x < b.x;
}

bool comparePointY(Point a, Point b) {
    return a.y < b.y;
}

double bruteforce(Point p[], int n) {
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

double closestPair(Point p[], int n) {
    if (n < 4) {
        return bruteforce(p, n);
    }

    double minDistance = min(closestPair(p, n/2), closestPair(p+(n/2), n-(n/2)));

    int m = 0;
    Point closePoints[n];
    for (int i=0; i<n; i++) {
        if (abs(p[i].x - p[n/2].x) < minDistance) {
            closePoints[m] = p[i];
            m++;
        }
    }

    sort(closePoints, closePoints+m, comparePointY);

    for (int i=0; i<m; i++) {
        for (int j=i+1; j<m && (closePoints[j].y - closePoints[i].y) < minDistance; j++) {
            double temp = distance(closePoints[i], closePoints[j]);
            if (temp < minDistance)
                minDistance = temp;
        }
    }

    return minDistance;
}

int main() {
    int N = 5000;
    Point* p = new Point[N];

    string filename = "output.txt";
    filename.insert(6, to_string(N));

    ifstream file;
    file.open(filename);

    for (int i=0; i<N; i++) {
        double a, b;
        file>>a>>b;
        Point temp;
        temp.x = a;
        temp.y = b;
        p[i] = temp;
    }

    auto begin = chrono::high_resolution_clock::now();

    sort(p, p+N, comparePointX);

    double ans = closestPair(p, N);

    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    cout << "Closest distance: " << ans << endl;
    cout << "Time taken: " << ms << "ms"<< endl;

    delete[] p;
}
