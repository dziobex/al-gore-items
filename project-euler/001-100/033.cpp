#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int commonNum(int a, int b) {
    string as = to_string(a), bs = to_string(b);

    for (int i = 0; i < as.size(); ++i)
        for (int j = 0; j < bs.size(); ++j)
            if (as[i] == bs[j])
                return (as[i] - '0');

    return -1;
}

bool isFine(int a, int b, int cm) {
    string as = to_string(a), bs = to_string(b);
    char cmc = (char)(cm + '0');

    as.erase(std::remove(as.begin(), as.end(), cmc), as.end());
    bs.erase(std::remove(bs.begin(), bs.end(), cmc), bs.end());

    int asi = atoi(as.c_str()), bsi = atoi(bs.c_str());

    return (float)asi / (float)bsi == (float)a / (float)b;
}

int nwd(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main () {

    int aa = 1, bb = 1;
    for (int a = 10; a <= 99; ++a) {
        for (int b = a + 1; b <= 99; ++b) {
            int cm = commonNum(a, b);

            if (cm != -1 && cm != 0 && isFine(a, b, cm)) {
                int nw = nwd(a, b);
                aa *= (a / nw);
                bb *= (b / nw);
            }
        }
    }

    cout << bb / aa;

    return 0;
}