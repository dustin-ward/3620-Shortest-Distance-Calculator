#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <fstream>
using namespace std;

int main() {
  int N = 5000;
  string filename = "output.txt";
  filename.insert(6, to_string(N));

  ofstream file;
  file.open(filename);

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(-10000, 10000);

  for(int i=0; i<N; i++) {
    int x, y;
    x = dist(rng);
    y = dist(rng);
    file<<x<<" "<<y<<endl;
  }
  file.close();
}
