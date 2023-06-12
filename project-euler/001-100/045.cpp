#include <iostream>
#include <map>

using namespace std;

#define ull unsigned long long

int main () {

    map<ull, ull> gonals;

    for (ull n = 2; ; ++n) {
        ull T = n * (n + 1) / 2;
        if (gonals.count(T) == 0) {
            gonals.insert(make_pair(T, 1));
        } else if (++gonals[T] >= 3 && T != 40755) {
            cout << T;
            break;
        }

        ull P = n * (3 * n - 1) / 2;
        if (gonals.count(P) == 0) {
            gonals.insert(make_pair(P, 1));
        } else if (++gonals[P] >= 3 && P != 40755) {
            cout << P;
            break;
        }

        ull H = n * (2 * n - 1);
        if (gonals.count(H) == 0) {
            gonals.insert(make_pair(H, 1));
        } else if (++gonals[H] >= 3 && H != 40755) {
            cout << H;
            break;
        }
    }


    return 0;
}