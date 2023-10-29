// =radix sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int numer(int liczba, int d) {
    return (liczba % d) / (d / 10);
}

void bombel(int tab[], int N, int d) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N - j - 1; ++j)
            if (numer(tab[j], d) > numer(tab[j + 1], d))
                swap(&tab[j + 1], &tab[j]);
}

void pozycyjne(int tab[], int N, int MX) {
    for (int i = 0, d = 10; d <= MX; ++i, d *= 10) {
        bombel(tab, N, d);
    }
}

int main (int argc, char **argv) {
    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        printf("Nie moge odczytac pliku :("), 1;

    int tab[100] = {}, i = 0;

    while (!feof(in))
        fscanf(in, "%d", &tab[i++]);

    pozycyjne(tab, 100, 1000);

    for (int i = 0; i < 100; ++i)
        printf("%d ", tab[i]);

    return 0;
}