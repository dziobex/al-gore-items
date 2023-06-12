#include <iostream>
#include <math.h>

using namespace std;

#define ull unsigned long long

int main () {

    for (int a = 1; a <= 1000; ++a) {
        for (int b = 1; b <= 1000; ++b) {
            float third = a*a + b*b;
            float thirdsq = sqrt(third);

            if (thirdsq*thirdsq == third && a + b + thirdsq == 1000)
                cout << (ull)(a * b * thirdsq) << '\n';
        }
    }

    return 0;
}