#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

int N = 100;

int main() {
   string filename = "output.txt";
   filename.insert(6, to_string(N));

   ofstream file;
   file.open(filename);
   for(int i=0; i<N; i++) {
      int x, y;
      x = rand() % 20000 + -10000;
      y = rand() % 20000 + -10000;
      file<<x<<" "<<y<<endl;
   }
   file.close();
}
