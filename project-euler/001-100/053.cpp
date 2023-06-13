#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ull unsigned long long

vector<int> getDivs(int n){
    vector<int> result;

    for (int i = 2; i <= n; ++i)
        while (n % i == 0) {
            result.push_back(i);
            n /= i;
        }

    return result;
}

int main () {

    map<int, vector<int>> factorials;

    for (int i = 2; i <= 100; ++i) {
        vector<int> temp(102, 0);
        vector<int> divs = getDivs(i);

        for (auto& d : divs)
            ++temp[d];
        
        if (i >= 3)
            for (int x = 2; x <= 100; ++x)
                temp[x] += factorials[i - 1][x];

        factorials.insert(make_pair(i, temp));
    }

    int cnt = 0;
    for (int n = 23; n <= 100; ++n) {

        for (int r = 2; r <= n / 2; ++r) {

            vector<int> c = factorials[n];
            vector<int> a = factorials[r];
            vector<int> b = factorials[n - r];

            ull re = 1;

            for (int i = 2; i <= 100; ++i) {
                c[i] -= (a[i] + b[i]);


                while (c[i] > 0) {
                    re *= i;

                    if (re > 1000000)
                        break;
                    --c[i];
                }

                if (re > 1000000) {
                    if (r * 2 == n)
                        cnt++;
                    else
                        cnt += 2;
                    break;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}