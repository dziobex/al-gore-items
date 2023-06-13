#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ull unsigned long long

int main () {

    for (ull x = 1000; ; ++x) {
        string prev = to_string(x * 2), curr = "";
        sort(prev.begin(), prev.end());

        for (int i = 3; i <= 6; ++i) {
            ull eq = x * i;
            curr = to_string(eq);
            sort(curr.begin(), curr.end());

            if (prev != curr)
                break;
        }

        if (prev == curr) {
            cout << x;
            break;
        }
    }

    return 0;
}