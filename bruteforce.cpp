#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int N = 100;

struct Point {
   double x;
   double y;
};


double distance(Point a, Point b) {
   return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}


int main() {
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
   
   double minDistance = 0.0;
   int idxA;
   int idxB;
   for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) {
	 double currDistance = distance(p[i],p[j]);
	 if(currDistance<minDistance){
	    cout<<"3"<<endl;
	    minDistance=currDistance;
	    idxA = i;
	    idxB = j;
	 }
      }

   }
   
   cout<<"Minimum Distance is "<<minDistance<<" between points ";
   cout<<p[idxA].x<<","<<p[idxA].y<<" and "<<p[idxB].x<<","<<p[idxB].y<<endl;
}
