#include <iostream>

using namespace std;

int main () {

    unsigned long long sum = 1;

    for (int SIZE = 0; SIZE <= 1001; SIZE += 2) {
        int sq = 1 + SIZE;
        sq *= sq;

        if (SIZE > 0) {
            sum += sq * 4 - SIZE * 6;
        }
    }

    cout << sum;

    return 0;
}