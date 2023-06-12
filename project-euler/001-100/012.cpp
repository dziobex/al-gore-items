#include <iostream>

using namespace std;

#define ull unsigned long long

int divsCount(ull n) {
    int dc = 0;

    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0)
            dc += (i * i == n ? 1 : 2);
    
    return dc;
}

int main () {

    ull triangle = 0;

    for (int t = 0;; ++t) {
        triangle += t;
        
        if (divsCount(triangle) >= 500) {
            cout << triangle;
            break;
        }
    }

    return 0;
}