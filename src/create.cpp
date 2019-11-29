#include "../include/create.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <fstream>

/**
* Runs the point creator algorithm with a size 'n'
*/
Create::Create(int input) {
  int N = input;
  std::string filename = "output.txt";
  filename.insert(6, std::to_string(N));

  std::ofstream file;
  file.open(filename);

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(-10000, 10000);

  for(int i=0; i<N; i++) {
    int x, y;
    x = dist(rng);
    y = dist(rng);
    file<<x<<" "<<y<<std::endl;
  }
  file.close();
}

/**
* Destructor
*/
Create::~Create() {}
