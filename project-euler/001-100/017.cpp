#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main () {

    map<int, string> words;

    words = {
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
        {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
        {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"},
        {100, "hundred"}, {1000, "onethousand"}
    };

    int wordCount = 0;

    // pojedyncze cyfry: 1, 2, 3, ..., 21, 22, 23, ..., 101, 102, 103, ...
    for (int i = 1; i <= 9; ++i)
        wordCount += (words[i].size() * 90);
    
    // nastki
    for (int i = 10; i <= 19; ++i) {
        wordCount += (words[i].size() * 10);
    }

    // decymale
    for (int i = 20; i <= 90; i += 10) {
        wordCount += (words[i].size() * 100);
    }

    // setki
    for (int i = 100; i <= 999; ++i) {
        wordCount += words[100].size();
        wordCount += words[(i - (i % 100)) / 100].size();
    }
    
    // "and"
    for (int i = 100; i <= 999; ++i) {
        if (i % 100 != 0)
            wordCount += (3);
    }

    // i 1000
    wordCount += words[1000].size();

    cout << wordCount;

    return 0;
}