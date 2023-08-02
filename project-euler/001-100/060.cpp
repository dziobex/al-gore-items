#include <iostream>
#include <string>

using namespace std;

#define ull unsigned long long

bool nprime[99999999+1]{};

int main () {

    nprime[0] = nprime[1] = true;

    for (ull i = 2; i * i <= 99999999; ++i)
        for (int j = i * 2; j <= 99999999; j += i)
            nprime[j] = true;
    
    bool found = false;
    int sum = 0;

    for (int a = 3; (!found && a <= 9999); a += 2) {
        if (nprime[a])
            continue;
        
        string str_a = to_string(a);
        
        for (int b = a+2; (!found && b <= 9999); b += 2) {
            if (nprime[b])
                continue;

            string str_b = to_string(b);

            if (nprime[atoll( (str_a + str_b).c_str())] || nprime[atoll( (str_b + str_a).c_str())])
                continue;
        
            for (int c = b+2; (!found && c <= 9999); c += 2) {
                if (nprime[c])
                    continue;
                
                string str_c = to_string(c);

                if (nprime[atoll( (str_a + str_c).c_str())] || nprime[atoll( (str_c + str_a).c_str())]
                    || nprime[atoll( (str_c + str_b).c_str())] || nprime[atoll( (str_b + str_c).c_str())])
                    continue;
        
                for (int d = c+2; (!found && d <= 9999); d += 2) {
                    if (nprime[d])
                        continue;
                    
                    string str_d = to_string(d);

                    if (nprime[atoll( (str_a + str_d).c_str())] || nprime[atoll( (str_d + str_a).c_str())]
                        || nprime[atoll( (str_d + str_b).c_str())] || nprime[atoll( (str_b + str_d).c_str())]
                        || nprime[atoll( (str_c + str_d).c_str())] || nprime[atoll( (str_d + str_c).c_str())])
                        continue;
        
                    for (int e = d+2; (!found && e <= 9999); e += 2) {
                        string str_e = to_string(e);

                        if (nprime[atoll( (str_a + str_e).c_str())] || nprime[atoll( (str_e + str_a).c_str())]
                            || nprime[atoll( (str_e + str_b).c_str())] || nprime[atoll( (str_b + str_e).c_str())]
                            || nprime[atoll( (str_c + str_e).c_str())] || nprime[atoll( (str_e + str_c).c_str())]
                            || nprime[atoll( (str_e + str_d).c_str())] || nprime[atoll( (str_d + str_e).c_str())])
                            continue;

                        if (!nprime[e]) {
                            sum = a + b + c + d + e;
                            found = true;
                        }
                    }
                }
            }
        }

        cout << sum;
    }

    return 0;
}