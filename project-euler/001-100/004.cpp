#include <iostream>
#include <string>

using namespace std;

bool palindrome(int n) {
    string stringed = to_string(n);

    for (int i = 0; i < stringed.size() / 2; ++i) {
        if (stringed[i] != stringed[stringed.size() - 1 - i])
            return false;
    }
    return true;
}

int main () {
    int maxN = 0;

    for (int a = 999; a >= 100; --a) {
        for (int b = 999; b >= 100; --b) {
            int multi = a * b;
            if (palindrome(multi) && multi > maxN) {
                maxN = multi;
                break;
            }
        }
    }

    cout << maxN;

    return 0;
}