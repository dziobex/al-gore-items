#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSumOfDivs(int n) {
    int sum = 0;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;

            if (i * i < n)
                sum += (n / i);
        }
    }

    return sum - n;
}

int main () {

    bool abunds[28125]{};

    int sum = 0;
    for (int i = 1; i <= 28123; ++i) {
        int divs = getSumOfDivs(i);

        if (divs > i)
            abunds[i] = true;
    }

    for (int i = 1; i <= 28123; ++i) {
        
        bool summed = true;
        for (int j = 0; j < i; ++j) {
            if (abunds[j] && abunds[i - j]) {
                summed = false;
                break;
            }
        }

        if (summed) {
            
            sum += i;
        }
    }

    cout << sum;

    return 0;
}