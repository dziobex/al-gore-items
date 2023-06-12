#include <iostream>
#include <math.h>

using namespace std;

const int limit = 20;

int main () {

    int N = 1;

    int multis[limit + 1]{};

    for (int i = 2; i <= limit; ++i) {
        int copy = i;

        for (int a = 2; a * a <= copy; ++a) {
            int counter = 0;
            while (copy % a == 0) {
                copy /= a;

                if (counter++ >= multis[a])
                    multis[a] = counter;
            }
        }

        if (multis[copy] == 0)
            ++multis[copy];
    }

    for (int i = 1; i <= limit; ++i)
        for (int a = 0; a < multis[i]; ++a)
            N *= i;

    cout << N;

    return 0;
}
