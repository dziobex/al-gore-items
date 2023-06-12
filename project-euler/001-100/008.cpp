#include <iostream>
#include <fstream>

using namespace std;

#define ull unsigned long long

const ull caterpillarSize = 13;
string patch;

ull caterpillarGathers(int s) {
    ull gathers = 1;

    for (int i = s; i < s + caterpillarSize; ++i)
        gathers *= (patch[i] - '0');
    
    return gathers;
}

int main () {

    ifstream in("dane/adj.txt");
    in >> patch;
    in.close();

    ull maxMp = caterpillarGathers(0), localMp = 1;

    for (int i = 1; i < 1000 - caterpillarSize; ++i) {
        localMp = caterpillarGathers(i);
        if (localMp > maxMp)
            maxMp = localMp;
    }

    cout << maxMp;

    return 0;
}