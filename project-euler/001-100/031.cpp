#include <iostream>

using namespace std;

int ways[200 + 10]{};
const int coins[8]{1, 2, 5, 10, 20, 50, 100, 200};

int main () {
    ways[0] = 1;

    for (int i = 0; i < 8; ++i)
        for (int j = coins[i]; j <= 200; ++j)
            ways[j] += ways[j - coins[i]];

    cout << ways[200];

    return 0;
}