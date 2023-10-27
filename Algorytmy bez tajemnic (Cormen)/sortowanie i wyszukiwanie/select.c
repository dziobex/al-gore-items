#include <stdio.h>
#include <stdlib.h>

void select (int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;

        for (int j = i + 1; j < n; ++j)
            if (tab[j] < tab[min])
                min = j;
        
        int temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
    }
}

int main (int argc, char **argv) {
    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        printf("Nie moge odczytac pliku :("), 1;

    int tab[100] = {}, i = 0;

    while (!feof(in))
        fscanf(in, "%d", &tab[i++]);

    select(tab, 100);

    for (int i = 0; i < 100; ++i)
        printf("%d ", tab[i]);

    return 0;
}