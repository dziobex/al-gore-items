#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data;

bool valid(string key) {
    for (int i = 0; i < data.size(); ++i) {
        int k = (int)(key[i % 3]);
        int xored = (data[i] ^ k);
        if (xored < 32 || xored > 122)
            return false;
    }
    return true;
}

bool decrypt (string key) {
    string text = "";

    for (int i = 0; i < data.size(); ++i) {
        int k = (int)(key[i % 3]);
        int xored = (data[i] ^ k);
        text += (char)(xored);
    }

    vector<string> commons{"Euler", "the"};

    for (string& c : commons)
        if (text.find(c) != string::npos)
            return true;
    return false;
}

int main () {

    string thatKey = "";
    int thatSum = 0;

    ifstream in("dane/0059_cipher.txt");
    int n;
    while (in >> n)
        data.push_back(n);
    in.close();

    for (char a = 'a'; a <= 'z' && thatKey == ""; ++a) {
        for (char b = 'a'; b <= 'z' && thatKey == ""; ++b) {
            for (char c = 'a'; c <= 'z' && thatKey == ""; ++c) {

                string key = "";
                key += a; key += b; key += c;

                if (valid(key) && decrypt(key))
                    thatKey = key;
            }
        }
    }

    for (int i = 0; i < data.size(); ++i) {
        int k = (int)(thatKey[i % 3]);
        thatSum += (data[i] ^ k);
    }

    cout << thatSum;

    return 0;
}