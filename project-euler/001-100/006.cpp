#include <iostream>

using namespace std;

const int limit = 100;

int main () {

    int sumSquares = 0, sumSquare = 0;

    for (int i = 1; i <= limit; ++i)
        sumSquares += (i * i);
    
    sumSquare = (1 + limit) * limit / 2;
    sumSquare *= sumSquare;

    cout << sumSquare - sumSquares;

    return 0;
}