
#include <stdlib.h>
#include <stdio.h>

void print(int tab[], int n) {
    int *p = &tab[0];

    while (p != &tab[n - 1]) {
        printf("%d ", *(p++));
    }
}

void ins(int tab[], int n) {

    for (int i = 0; i < n; ++i) {
        int temp = tab[i];

        for (int j = i - 1; j >= 0; --j)
            if (tab[j] > temp) {
                tab[j + 1] = tab[j];
                tab[j] = temp;
            }
    }
}

int main (int argc, char **argv) {

    int tab[100] = {};

    FILE *in = fopen("rand/liczby.txt", "r");

    if (in == NULL)
        return printf("Nie udało się odczytać pliku :("), 1;
    
    int i = 0;

    while (!feof(in)) {
        fscanf(in, "%d", &tab[i++]);
    }

    fclose(in);

    ins(tab, 100);
    print(tab, 100);

    return 0;
}