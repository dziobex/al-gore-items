#include <iostream>

using namespace std;

bool nprimes[2000000]{};

const int limit = 2000000;

int main () {

    unsigned long long sum = 0;

    for (int i = 2; i < limit; ++i) {

        if (!nprimes[i]) {
            sum += i;

            for (int j = i * 2; j < limit; j += i)
                nprimes[j] = true;
        }
    }

    cout << sum;

    return 0;
}