#include <iostream>
#include "./include/create.h"
#include "./include/divideconquer.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of points to run the Divide & Conquer algorithm on: (Type '-1' to stop)" << endl;
    cin>>n;
    while(n > 1) {
        cout << "\n=================== " << n << " ===================" << endl;
        Create c(n);
        DivideConquer d(n, false);
        long double time = d.ans1;
        cout << "Time taken: ";
        if (time > 9999) {
          time /= 1000;
          cout << time << "ms" << endl;
        }
        else {
          cout << time << "us" << endl;
        }
        cout << "\nEnter the number of points to run the Divide & Conquer algorithm on: (Type '-1' to stop)" << endl;
        cin>>n;
    }

    return 0;
}
