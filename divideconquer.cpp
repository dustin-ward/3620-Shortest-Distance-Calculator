#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <float.h>
using namespace std;

struct Point {
    double x;
    double y;
};

double distance(Point& a, Point& b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

bool comparePoint(Point a, Point b) {
    return a.x < b.x;
}

double bruteforce(vector<Point> &p, int n) {
    for (int i=0; i<start-n; i++) {
        for (int j=i; j<start-n; j++) {
            double temp = distance(p[i], p[j]);
            if (temp < minDistance) {
                cout << "Minimum is now " << temp << endl;
                minDistance = temp;
            }
        }
    }
    return minDistance;
}

double closestPair(vector<Point> &p, int start, int n) {
    double minDistance = DBL_MAX;
    if (n == 3 || n == 2) {
        return bruteforce(p, n);
    }
    double c = (p[((n+start)/2)-1].x + p[(n+start)/2].x)/2;
    minDistance = min(closestPair(p, start, n/2), closestPair(p, start+1, n/2));
    cout << "Minimum is now " << minDistance << endl;
    return minDistance;
}

int main() {
    int N = 100;
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

    sort(p.begin(), p.end(), comparePoint);

    //for(auto i:p) {
    //    cout<<i.x<<" "<<i.y<<endl;
    //}

    int ans = closestPair(p, 0, N);
    cout << "Closest distance: " << ans << endl;
}
