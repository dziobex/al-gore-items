#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

#define ull unsigned long long

int main () {

    map<string, ull> cubes;
    map<string, ull> keys;

    for (ull i = 10; i <= 10000;++i) {
        ull cube = i * i * i;
        string scube = to_string(cube);

        sort(scube.begin(), scube.end());

        if (cubes.count(scube) == 0) {
            cubes.insert(make_pair(scube, 1));
            keys.insert(make_pair(scube, i));
        }
        else {
            ++cubes[scube];
        }
    }

    for (auto& x : cubes) {
        if (x.second == 5) {
            cout << keys[x.first] * keys[x.first] * keys[x.first] << ' ';
            break;
        }
    }

    return 0;
}