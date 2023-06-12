#include <iostream>
#include <string>

using namespace std;

bool unique (string n) {
    int tab[12]{};

    for (int i = 0; i < n.size(); ++i)
        if (++tab[n[i] - '0'] != 1)
            return false;
    
    return tab[0] != 1;
}

int main () {

    string maxNum = "0";

    for (int i = 1; i < 10000; ++i) {

        string stringed = to_string(i);

        for (int j = 2; stringed.size() < 9; ++j)
            stringed += to_string(j * i);
        
        if (stringed.size() == 9 && unique(stringed))
            maxNum = stringed;
    }

    cout << maxNum;

    return 0;
}