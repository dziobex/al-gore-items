#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    ifstream in("dane/names.txt");

    string name;
    unsigned long long totalSum = 0;

    vector<string> names;

    while (in >> name)
        names.push_back(name);
    
    sort(names.begin(), names.end());

    for (int i = 1; i <= names.size(); ++i) {
        unsigned long long value = 0;
        for (auto& c : names[i-1])
            value += (c - 'A' + 1);
        
        value *= i;
        totalSum += value;
    }

    cout << totalSum << '\n';

    in.close();

    return 0;
}