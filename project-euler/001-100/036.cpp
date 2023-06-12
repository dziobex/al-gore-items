#include <iostream>
#include <string>

using namespace std;

string toBin(int n) {
    string result = "";

    while (n > 0) {
        result = (char)((n % 2) + '0') + result;
        n /= 2;
    }

    return result;
}

bool isPalindrome(string n) {
    for (int i = 0; i < n.size() / 2; ++i)
        if (n[i] != n[n.size() - 1 - i])
            return false;
    return true;
}

int main () {

    int sum = 0;

    for (int i = 1; i <= 1000000; ++i) {
        string binaried = toBin(i);

        if (isPalindrome(binaried) && isPalindrome(to_string(i)))
            sum += i;
    }

    cout << sum;

    return 0;
}