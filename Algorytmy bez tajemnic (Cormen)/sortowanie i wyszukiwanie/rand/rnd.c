#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, int **argv) {
    // wygeneruje 100 liczb do pliku liczby.txt, bym miała co sortować

    FILE *in = fopen("liczby.txt", "w");

    if (in == NULL)
        return printf("Coś nie działa :("), 1;

    srand(time(NULL));

    for (int i = 0; i < 100; ++i) {
        int num = rand() % 1000;
        fprintf(in, "%i\n", num);
    }
    fclose(in);

    return 0;
}