#include <stdio.h>
#include <stdlib.h>

struct Node  {
    int value;
    int kids;
    int edges;

    struct Node **children;
};

struct Node *createNode(int value) {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->kids = 0;
    newNode->edges = 0;
    
    return newNode;
}

// to node child
// wskaznik do wskaznika zeby go zmodyfikowac
void createEdge(struct Node **parent, struct Node **child) {
    if ((*parent)->kids >= 1)
        realloc((*parent)->children, (*parent)->kids * sizeof(struct Node*));
    else
        (*parent)->children = malloc(sizeof(struct Node*));

    (*parent)->children[(*parent)->kids] = (child);
    
    (*parent)->kids++;

    (*child)->edges++;
}

int main (int argc, char **argv) {

    struct Node **nodes;
    nodes = malloc(12 * sizeof(struct Node));

    for (int i = 0; i < 12; ++i)
        nodes[i] = NULL;

    // wierzcholki
    nodes[5] = createNode(5);
    nodes[2] = createNode(2);
    nodes[11] = createNode(11);
    nodes[10] = createNode(10);
    nodes[3] = createNode(3);
    nodes[9] = createNode(9);
    nodes[8] = createNode(8);
    nodes[7] = createNode(7);

    // graf
    // graficznie graf mozna zobaczyc w pliku graf.png
    createEdge(&nodes[5], &nodes[11]);
    createEdge(&nodes[11], &nodes[2]);
    createEdge(&nodes[11], &nodes[10]);
    createEdge(&nodes[7], &nodes[11]);
    createEdge(&nodes[8], &nodes[9]);
    createEdge(&nodes[7], &nodes[8]);
    createEdge(&nodes[11], &nodes[9]);
    createEdge(&nodes[3], &nodes[10]);
    createEdge(&nodes[3], &nodes[8]);

    for (int i =  0; i < 12; ++i) {
        if (nodes[i] == NULL || nodes[i]->edges != 0)
            continue;
        
        // zapisane w rejestrze
        if (nodes[i]->edges == 0 && nodes[i]->kids == 0)
            continue;

        printf("%d, ", i);
        
        for (int k = 0; k < nodes[i]->kids; ++k) {

            struct Node **kiddo = (nodes[i]->children[k]);

            --(*kiddo)->edges;

            // niedobitki (kolejny obrot petli ich nie zczyta)
            if ((*kiddo)->edges == 0 && (*kiddo)->kids == 0)
                printf("%d, ", (*kiddo)->value);

            free(kiddo);
        }
    
        // usuwamy akta ze dzieci byly
        nodes[i]->kids = 0;

        // reset petli
        i = 0;
    }

    free(nodes);

    return 0;
}