#include <iostream>

using namespace std;

int main () {

    int day = 1, counter = 0;
    for (int year = 1900; year <= 2000; ++year) {

        for (int month = 1; month <= 12; ++month) {            
            if (year >= 1901 && day % 7 == 0)
                ++counter;

            day += 31;

            if (month == 4 || month == 6 || month == 9 || month == 11)
                day -= 1;
            else if (month == 2 && year % 4 == 0 && year != 1900)
                day -= 2;
            else if (month == 2)
                day -= 3;
            
            day = day % 7;
        }
    }

    cout << counter;

    return 0;
}