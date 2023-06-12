#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const int rowsCount = 15;

int main () {

    ifstream in("dane/triangleI.txt");

    vector< vector<int> > rows;

    for (int i = 1; i <= rowsCount; ++i) {
        vector<int> row;
        int r;

        for (int j = 0; j < i; ++j) {
            in >> r;
            row.push_back(r);
        }
        
        rows.push_back(row);
    }

    in.close();

    for (int i = rowsCount - 2; i >= 0; --i) {
        for (int j = 0; j < i + 1; ++j) {
            rows[i][j] += max(rows[i + 1][j], rows[i + 1][j + 1]);
        }
    }

    cout << rows[0][0];

    return 0;
}