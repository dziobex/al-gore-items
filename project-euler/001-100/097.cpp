#include <iostream>
#include <math.h>

using namespace std;

#define ull unsigned long long

const ull POWER = 7830457;
const ull MULTIP = 28433;
const int ADD = 1;
const int DIGITS = 10;

void action(ull what, int (&digits)[DIGITS], string action="m") {
    if (action == "m")
        for (int a = DIGITS - 1; a >= 0; --a)
            digits[a] *= what;
    else if (action == "a")
        digits[DIGITS - 1] += what;
        
    for (int a = DIGITS - 1; a >= 0; --a) {
        int sure = digits[a] % 10;
        int package = (digits[a] - sure) / 10;

        digits[a] = sure;

        if (a >= 1)
            digits[a - 1] += package;
    }
}

int main () {
    int digits[DIGITS]{};   
    digits[DIGITS - 1] = 1;

    for (ull i = 1; i <= POWER; ++i) {
        action(2, digits);
    }

    action(MULTIP, digits);
    action(ADD, digits, "a");

    for (int i = 0; i < DIGITS; ++i)
        cout << digits[i];

    return 0;
}