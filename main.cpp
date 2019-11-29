#include <iostream>
#include "./include/create.h"
#include "./include/bruteforce.h"
#include "./include/divideconquer.h"
using namespace std;

void run(int n) {
  long long bSum=0;
  int dSum=0;
  cout << "=================== " << n << "===================" << endl;
  Create c(n);
  cout << "Bruteforce: \n" << endl;
  for(int i=0; i<5; i++) {
    Bruteforce b(n);
    bSum += b.ans;
  }
  cout << bSum/5 << endl;
  cout << "Divide and Conquer: \n" <<endl;
  //DivideConquer d(n);
  for(int i=0; i<5; i++) {
    DivideConquer* d = new DivideConquer(n);
    cout << d->ans << endl;
    dSum += d->ans;
    delete d;
  }
  cout << dSum/5 << endl;
}

int main() {
  // int x = 100;
  // run(x);
  //
  // x = 200;
  // run(x);
  //
  // x = 300;
  // run(x);
  //
  // x = 400;
  // run(x);
  //
  // x = 500;
  // run(x);
  //
  // x = 600;
  // run(x);
  //
  // x = 700;
  // run(x);
  //
  // x = 800;
  // run(x);
  //
  // x = 900;
  // run(x);
  //
  // x = 1000;
  // run(x);
  //
  // x = 1500;
  // run(x);
  //
  // x = 2000;
  // run(x);
  //
  // x = 2500;
  // run(x);
  //
  // x = 3000;
  // run(x);
  //
  // x = 4000;
  // run(x);
  //
  // x = 5000;
  // run(x);
  //
  // x = 6000;
  // run(x);
  //
  // x = 7000;
  // run(x);
  //
  // x = 8000;
  // run(x);
  //
  // x = 9000;
  // run(x);

  int x = 100000;
  run(x);

  return 0;
}
