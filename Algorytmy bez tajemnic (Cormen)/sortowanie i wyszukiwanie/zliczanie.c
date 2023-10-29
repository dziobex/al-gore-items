// ZLICZANIEC XDDD

#include <stdio.h>
#include <stdlib.h>

void zliczaniec(int tab[], int n) {
    int liczby[1010] = {};

    for (int i = 0; i < n; ++i)
        ++liczby[tab[i]];
    
    for (int i = 0, index = 0; index < n; ++i)
        if (liczby[i] != 0)
            for (int j = 0; j < liczby[i]; ++j)
                tab[index++] = i;
}

int main (int argc, char **argv) {
    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        printf("Nie moge odczytac pliku :("), 1;

    int tab[100] = {}, i = 0;

    while (!feof(in))
        fscanf(in, "%d", &tab[i++]);

    zliczaniec(tab, 100);

    for (int i = 0; i < 100; ++i)
        printf("%d ", tab[i]);

    return 0;
}