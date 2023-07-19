#include <iostream>
#include <math.h>

using namespace std;

int main () {

    int d = 1000000;

    while (d % 7 != 0)
        --d;
    
    cout << (d / 7) * 3 - 1;

    return 0;
}