#include <stdio.h>
#include <stdlib.h>

void wypisz(int tab[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", tab[i]);
}

// nazwałabym to merge
// ale merge to dosłownie scal

void scal(int tab[], int lp, int lq, int rp, int rq) {
    int prawo[200] = {}, lewo[200] = {};

    // uzupelniam lewo
    for (int i = lp; i <= lq; ++i)
        lewo[i] = tab[i];
    // uzupelniam prawo
    for (int i = rp; i <= rq; ++i)
        prawo[i] = tab[i];

    // zlaczam
    int guwniak = lp, odLewej = lp, odPrawej = rp;
    
    while (guwniak <= rq) {
        if ((odPrawej > rq) || (odLewej <= lq && lewo[odLewej] <= prawo[odPrawej]))
            tab[guwniak++] = lewo[odLewej++];

        else if ((odLewej > lq) || (odPrawej <= rq && lewo[odLewej] >= prawo[odPrawej]))
            tab[guwniak++] = prawo[odPrawej++];
    }
}

void sortownia(int tab[], int p, int q) {
    if (p == q)
        return;

    int s = (p + q) / 2;

    // lewa strona
    sortownia(tab, p, s);
    scal(tab, p, s, s + 1, q);
    
    // prawa strona
    sortownia(tab, s + 1, q);
    scal(tab, p, s, s + 1, q);
}

int main (int argc, char **argv) {
    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        printf("Nie moge odczytac pliku :("), 1;

    int tab[100] = {}, i = 0;

    while (!feof(in))
        fscanf(in, "%d", &tab[i++]);

    sortownia(tab, 0, 99);

    wypisz(tab, 100);

    return 0;
}