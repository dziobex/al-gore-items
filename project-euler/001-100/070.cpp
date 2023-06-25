#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ull;

ull phi(ull n) {
    ull ph = n;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0)
            continue;
        ph -= ph / i;

        while (n % i == 0)
            n /= i;
    }

    if (n == 1)
        return ph;

    return ph - ph / n;
}

const ull LIMIT = 10000000;
const ull BOUND = LIMIT - LIMIT / 5;

int main () {

    double maxPhi = 6.9;

    ull index = 0;
    for (ull i = LIMIT - 1; i >= BOUND; --i) {
        ull phied = phi(i);

        double newPhi = (double)i / (double)phied;

        if (newPhi < maxPhi) {
            string s1 = to_string(i);
            string s2 = to_string(phied);

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if (s1 != s2)
                continue;
            
            maxPhi = newPhi;
            index = i;
        }
    }

    cout << index;
    
    return 0;
}