#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSumOfDivs(int n) {
    int sum = 0;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            sum += (n / i);
        }
    }

    return sum - n;
}

int main () {

    int sum = 0;
    for (int i = 1; i <= 10000; ++i) {
        int divs = getSumOfDivs(i);

        if (getSumOfDivs(divs) == i && divs != i)
            sum += i;
    }

    cout << sum;

    return 0;
}