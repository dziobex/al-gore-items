#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int setsize = 52;
int nums[setsize]{};

int main () {

    ifstream in("dane/digiters.txt");

    for (int i = 0; i < 100; ++i) {
        string num; in >> num;

        for (int j = 0; j < 50; ++j)
            nums[setsize - 1 - j] += (num[50-1-j] - '0');
    }

    in.close();

    for (int i = setsize-1; i >= 1; --i) {
        int sure = nums[i] % 10;
        int package = (nums[i] - sure) / 10;

        nums[i] = sure;
        nums[i - 1] += package;
    }

    for (int i = 0; i < 10; ++i)
        cout << nums[i];

    return 0;
}