#include <iostream>
#include <string>
#include <set>

using namespace std;

bool unique (string n) {
    int tab[11]{};

    for (int i = 0; i < n.size(); ++i)
        if (++tab[n[i] - '0'] != 1)
            return false;
    
    for (int i = 1; i < 10; ++i)
        if (tab[i] != 1)
            return false;
    
    return tab[0] == 0;
}

int main () {

    set<int> nums;

    for (int i = 1; i < 2000; ++i) {
        for (int j = 1; j < 50; ++j) {
            int tog = i * j;
            string s1 = to_string(i) + to_string(j), s2 = to_string(tog);

            if (unique(s1 + s2)) {
                // cout << i << "x" << j << " = " << tog << '\n';
                nums.insert(tog);
            }
        }
    }

    int sum = 0;
    for (auto& n : nums)
        sum += n;
    
    cout << sum;

    return 0;
}