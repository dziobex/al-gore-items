#include <iostream>
#include <math.h>

using namespace std;

int pers[1000 + 2]{};

int main () {

    int pmax = 0, pmaxwhat = 0;

    for (int a = 1; a < 500; ++a) {
        for (int b = a + 1; b < 500; ++b) {
            int c = sqrt(a*a + b*b);

            if (c * c != a*a + b*b)
                continue;
            
            int per = a + b + c;
            if (per > 1000)
                continue;

            if (++pers[per] > pmax) {
                pmax = pers[per];
                pmaxwhat = per;
            }

        }
    }

    cout << pmaxwhat;

    return 0;
}