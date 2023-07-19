#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

bool isprime(ull n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

ull replacement(ull src, char old, char neo) {
    string stringed = to_string(src);

    for (char &c : stringed)
        if (c == old)
            c = neo;

    return atoll(stringed.c_str());
}

int main () {

    for (ull i = 100000; ; ++i) {
        if (!isprime(i))
            continue;
        
        bool found = false;

        for (char u = '0'; u <= '9'; ++u) {
            string str = to_string(i);

            int cnt = 0;

            if (str.find(u) == string::npos)
                continue;

            for (char j = '0'; j <= '9'; ++j) {
                ull changed = replacement(i, u, j);

                if (isprime(changed) && changed >= 100000)
                    ++cnt;
            }

            if (cnt == 8) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << i;
            break;
        }
    }

    return 0;
}