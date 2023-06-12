#include <iostream>
#include <fstream>

using namespace std;

#define ull unsigned long long

const ull caterpillarSize = 4;
ull yard[20][20]{};

ull caterpillarGathers(int x, int y, string dir) {
    ull gathers = 1;

    if (dir == "-")
        for (int i = 0; i < caterpillarSize; ++i)
            gathers *= (yard[y][x + i]);
    else if (dir == "|")
        for (int i = 0; i < caterpillarSize; ++i)
            gathers *= (yard[y + i][x]);
    else if (dir == "\\") 
        for (int i = 0; i < caterpillarSize; ++i)
            gathers *= (yard[y + i][x + i]);
    else if (dir == "//") 
        for (int i = 0; i < caterpillarSize; ++i)
            gathers *= (yard[y + i][x - i]);
    
    return gathers;
}

int main () {

    ifstream in("dane/yard.txt");
    int vegetable;

    for (int y = 0; y < 20; ++y)
        for (int x = 0; x < 20; ++x)
            in >> yard[y][x];
    
    in.close();

    ull maxMp = 0;

    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            ull g[4]{};

            if (x < 20 - caterpillarSize)
              g[0] = caterpillarGathers(x, y, "-");
            if (y < 20 - caterpillarSize)
                g[1] = caterpillarGathers(x, y, "|");
            if (y < 20 - caterpillarSize && x < 20 - caterpillarSize)
                g[2] = caterpillarGathers(x, y, "\\");
            if (y < 20 - caterpillarSize && x >= caterpillarSize)
                g[3] = caterpillarGathers(x, y, "//");

            for (int a = 0; a < 4; ++a)
                if (g[a] > maxMp)
                    maxMp = g[a];
        }
    }

    cout << maxMp;

    return 0;
}