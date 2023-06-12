#include <iostream>
#include <string>

using namespace std;

#define ull unsigned long long

const ull LIM = 1000000;

bool sieve[LIM + 2]{};

bool left(int n) {
    string stringed = to_string(n);

    while (stringed.size() >= 1) {
        int num = atoi(stringed.c_str());

        if (sieve[num]) {
            
            return false;
        }
        stringed = stringed.substr(1, stringed.size() - 1);

    }
    return true;
}

bool right(int n) {
    string stringed = to_string(n);

    while (stringed.size() >= 1) {
        int num = atoi(stringed.c_str());
        if (sieve[num]) {            
            return false;
        }
        stringed = stringed.substr(0, stringed.size() - 1);
    }
    return true;
}

int main () {
    sieve[0] = sieve[1] = true;

    for (int i = 2; i * i <= LIM; ++i) {
        if (!sieve[i]) {
            for (int j = i*2; j <= LIM; j += i)
                sieve[j] = true;
        }
    }

    int sum = 0;
    for (int i = 20, c = 0; c < 11; ++i) {
        if (left(i) && right(i)) {
            sum += i;
            ++c;
        }
    }

    cout << sum;

    return 0;
}