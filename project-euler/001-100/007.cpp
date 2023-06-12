#include <iostream>

using namespace std;

bool nprimes[1000000]{};

const int dest = 10001;

int main () {

    int primescounter = 0, nthprime = 0;

    for (int i = 2; primescounter < dest; ++i) {

        if (!nprimes[i]) {
            if (++primescounter == dest) {
                nthprime = i;
                break;
            }

            for (int j = i * 2; j < 1000000; j += i)
                nprimes[j] = true;
        }
    }

    cout << nthprime;

    return 0;
}