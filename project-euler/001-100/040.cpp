#include <iostream>
#include <string>

using namespace std;

int main () {

    string frac = "";
    int res = 1;

    for (int i = 1; frac.size() <= 1000000; ++i)
        frac += to_string(i);

    for (int i = 1; i <= 1000000; i *= 10)
        res *= (frac[i - 1] - '0');

    cout << res;

    return 0;
}