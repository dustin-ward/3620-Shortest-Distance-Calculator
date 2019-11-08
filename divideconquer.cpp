#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
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

   for(auto i:p){
      cout<<i.x<<" "<<i.y<<endl;
   }
   
   double c = (p[(N/2)-1].x + p[N/2].x)/2;

   cout<<c<<endl;

   
}
