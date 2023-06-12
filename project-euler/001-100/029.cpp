#include <iostream>
#include <set>
#include <string>

using namespace std;

int lowestPower (int n) {
    for (int i = 2; i * i <= n; ++i) {
        int j = i;
        while (j < n)
            j *= i;
        if (j == n)
            return i;
    }

    return n;
}

int countPower(int n, int x) { // n^x
    int counter = 0;

    while (n > 1) {
        n /= x;
        ++counter;
    }

    return counter;
}

int main () {

    set<string> dists;

    for (int i = 2; i <= 100; ++i){
        int lp = lowestPower(i);
        int cp = countPower(i, lp);
        
        for (int j = 2; j <= 100; ++j)
            dists.insert(to_string(lp) + " " + to_string(j * cp));
    }

    cout << dists.size();

    return 0;
}