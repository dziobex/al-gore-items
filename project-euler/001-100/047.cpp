#include <iostream>

using namespace std;

const int LIM = 1000000;

bool sieve[LIM + 2]{};
int factors[LIM+2]{};

int main () {

    sieve[0]=sieve[1] = true;

    for (int i = 2; i * i <= LIM; ++i) {
        if (!sieve[i]) {
            for (int j = i * 2; j <= LIM; j += i)
                sieve[j] = true;
        }
    }

    for (int i = 2; i <= LIM; ++i) {

        for (int j = 2; j * j <= i; ++j) {
            if (i % j != 0)
            {
                continue;
            }

            if (!sieve[j]) {
                ++factors[i];
            }
            
            int r = i / j;

            if (!sieve[r] && r > j)
            {
                ++factors[i];
            }
        }

        if (i > 4 && factors[i] == 4 && factors[i - 1] == 4 && factors[i - 2] == 4 && factors[i - 3] == 4) {
            cout << i - 3;
            break;
        }
    }


    return 0;
}