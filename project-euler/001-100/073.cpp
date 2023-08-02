#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int nwd(int a, int b) {
    if (a != b)
        return nwd(a > b ? a - b : a, b > a ? b - a : b);
    return a;
}

int main () {

    // bounds: (1/3; 1/2)
    set<string> fracts;

    for (int d = 4; d <= 12000; ++d) {
        int ded = d * 2 * 3; // what a nice name! (ded joke)
        int start = d * 2;
        int stop = d * 3;

        for (int p = start + 1; p < stop; ++p) {
            int nwded = nwd(p, ded);

            if ((float)ded / (float)nwded <= 12000.0) {
                string stringed = to_string(p/nwded);
                stringed += "/";
                stringed += to_string(ded/nwded);

                fracts.insert(stringed);
            }
        }
    }


    cout << fracts.size();

    return 0;
}
