#include <iostream>

using namespace std;

int main () {

    int powers[10]{};

    for (int i = 0; i < 10; ++i)
        powers[i] = i*i*i*i*i;
    
    int sum = 0;

    for (int i = 2; i <= powers[9] * 5; ++i) {
        int c = i, ls = 0;

        while (c > 0) {
            ls += powers[c % 10];
            c /= 10;
        }

        if (ls == i)
            sum += i;
    }

    cout << sum;

    return 0;
}