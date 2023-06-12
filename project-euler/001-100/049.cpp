#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main () {

    map<string, vector<int>> sets;

    for (int i = 1000; i < 9999; ++i) {
        if (!isprime(i))
            continue;
        string stringed = to_string(i);
        sort(stringed.begin(), stringed.end());

        if (sets.count(stringed) == 0) {
            vector<int> v;
            v.push_back(i);
            sets.insert(make_pair(stringed, v));
        } else {
            sets[stringed].push_back(i);
        }
    }
    

    for (auto& el : sets) {
        vector<int> V = el.second;
        sort(V.begin(), V.end());

        if (V.size() >= 3) {

            bool fine = false;

            for (int i = 0; i < V.size() && !fine; ++i) {
                for (int j = i + 1; j < V.size() && !fine; ++j) {

                    for (int k = j + 1; k < V.size(); ++k) {
                        if (V[j] - V[i] == V[k] - V[j]) {
                            cout << V[i] << V[j] << V[k] << '\n';
                            fine = true;
                            break;
                        }
                    }
                }
            }
        }
    }


    return 0;
}