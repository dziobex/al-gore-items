#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// typ sortowania: deterministyczne (ZEGARMISTRZ UŻYTKOWNIK)
// jest jeszcze randomizowane, które polega na tym że pivot zamienia się przed użyciem z jakimś innym elementem

void szybcior(int tab[], int p, int q) {
    if (p >= q)
        return;
    
    int pivot = tab[q];
   
    int left = p - 1;
    
    for (int i = p; i <= q; ++i) {
        // korekty granicy lewej (tam laduja liczby mniejsze od pivot'a)
        if (tab[i] < pivot) {
            swap(&tab[++left], &tab[i]);
        }
    }

    // lewa granica right (liczby wieksze od pivota)
    int right = left + 1;
    swap(&tab[right], &tab[q]);
    
    szybcior(tab, p, right - 1);
    szybcior(tab, right + 1, q);
}

int main (int argc, char **argv) {
    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        printf("Nie moge odczytac pliku :("), 1;

    int tab[100] = {}, i = 0;

    while (!feof(in))
        fscanf(in, "%d", &tab[i++]);


    szybcior(tab, 0, 99);
    
    for (int i = 0; i < 100; ++i)
        printf("%d ", tab[i]);

    return 0;
}