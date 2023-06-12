#include <iostream>
#include <fstream>

using namespace std;

bool triangles[230]{};

int main () {

    for (int i = 1; i <= 20; ++i) {
        int index = i*(i + 1)/2;
        triangles[index] = true;
    }

    ifstream data("dane/words.txt");

    string word;
    int count = 0;

    while (data >> word) {
        int sum = 0;

        for (char& l : word)
            sum += (l - 'A' + 1);
        
        if (triangles[sum])
            ++count;
    }

    data.close();

    cout << count;

    return 0;
}