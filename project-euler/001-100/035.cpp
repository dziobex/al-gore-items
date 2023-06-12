#include <iostream>
#include <string>

using namespace std;

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

string moveOnce(string n) {
    string res = n;

    for (int i = 1; i < n.size(); ++i)
        res[i] = n[i - 1];
    res[0] = n[n.size() - 1];

    return res;
}

int main () {

    int total = 0;
    for (int i = 2; i < 1000000; ++i) {
        if (!isprime(i))
            continue;

        string stringed = to_string(i);
        int primes = 1;
        for (int j = 0; j < stringed.size() - 1; ++j) {
            stringed = moveOnce(stringed);
            if (isprime(atoi(stringed.c_str())))
                ++primes;
        }

        if (primes == stringed.size())
            ++total;
    }
    
    cout << total;

    return 0;
}