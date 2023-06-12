#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ull unsigned long long

const int PRIMES[7] {2, 3, 5, 7, 11, 13, 17};

bool appear(string src, char look) {
    for (auto& s : src)
        if (s == look)
            return true;
    return false;
}

string divSubString(string src, int id) {
    if (id >= 7)
        return src;
    
    string num = src.substr(src.size() - 2, 2);

    for (char i = '0'; i <= '9'; ++i) {

        if (appear(src, i))
            continue;
        
        string test = num + i;
        int intiged = atoi(test.c_str());

        if (intiged % PRIMES[id] == 0) {
            
            string r = divSubString(src + i, id + 1);

            if (r == "-1")
                continue;
            else
                return r;
        }
    }

    return "-1";
}

int main () {

    ull sum = 0;

    for (int i = 1000; i < 9999; i += 2) {
        string src = to_string(i);

        bool valid = true;

        for (int a = 0; valid && a < 4; ++a)
            for (int b = a + 1; b < 4; ++b)
                if (src[a] == src[b]) {
                    valid = false;
                    break;
                }
        
        if (!valid)
            continue;
        
        string res = divSubString(src, 1);

        if (res != "-1") {
            sum += atoll(res.c_str());
        }
    }

    cout << sum;

    return 0;
}