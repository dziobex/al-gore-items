#include <iostream>
#include <cmath>

using namespace std;

double phi = 1.6180;

int main () {

    double N = 999 * log(10) + log(sqrt(5));

    N /= log(phi);

    cout << (int)N;

    return 0;
}