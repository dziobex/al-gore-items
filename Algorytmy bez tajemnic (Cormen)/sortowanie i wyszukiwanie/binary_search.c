#include <stdio.h>
#include <stdlib.h>

int binarySearch(int tab[], int n, int dest, int p, int q) {
    if (p == q)
        return tab[p] == dest ? p : -1;
    
    int s = (p + q) / 2;

    if (tab[p] == dest)
        return p;
    if (tab[q] == dest)
        return q;

    if (tab[s] > dest)
        return binarySearch(tab, n, dest, p, s);
        
    return binarySearch(tab, n, dest, s, q);
}

int main (int argc, char **argv) {
    if (argc != 2)
        return printf("Podaj JEDNA liczbe"), 1;
    
    int inted = atoi(argv[1]);

    int tab[1000] = {};

    for (int i = 0; i < 1000; ++i)
        tab[i] = i + 1;
    
    int index = binarySearch(tab, 1000, inted, 0, 1000);
    printf("Liczba %d stoi na msc: %d", inted, index);
    

    return 0;
}