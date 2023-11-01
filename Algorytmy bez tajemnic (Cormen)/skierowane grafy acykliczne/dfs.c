#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 15

typedef struct V V;

struct V {
    int value;
    int visited;

    V **next;
    int next_count;
};

V createVertex(int value) {
    V v;

    v.value = value;
    v.visited = 0;
    v.next_count = 0;
    v.next = NULL;

    return v;
}

void addEdge(V *parent, V *child) {
    parent->next_count++;
    
    parent->next = (V **)realloc(parent->next, sizeof(V *) * parent->next_count);
    parent->next[parent->next_count - 1] = child;
}

void DFS(V *v) {
    v->visited = 1;

    printf("%d ", v->value);

    for (int i = 0; i < v->next_count; ++i) {
        if (v->next[i]->visited == 0)
            DFS((v->next[i]));
    }
}

int main(int argc, char **argv) {
    V *vertices = (V *)malloc(MAX_NODES * sizeof(V));

    for (int i = 0; i < MAX_NODES; ++i)
        vertices[i] = createVertex(i);
    
    // kilka obszarow pamięci nie bedzie w ogóle używanych - zalokowałam pamieć na nie dla wygody w posługiwaniu się indeksami-wierzchołkowymi
    vertices[0].value = vertices[2].value = vertices[5].value
        = vertices[9].value = vertices[11].value = vertices[12].value
        = -1;

    addEdge(&vertices[8], &vertices[3]);
    addEdge(&vertices[8], &vertices[10]);
    addEdge(&vertices[3], &vertices[6]);
    addEdge(&vertices[6], &vertices[4]);
    addEdge(&vertices[6], &vertices[7]);
    addEdge(&vertices[10], &vertices[14]);
    addEdge(&vertices[14], &vertices[13]);
    addEdge(&vertices[3], &vertices[1]);

    DFS(&vertices[8]);

    // czyszczenie
    
    for (int i = 0; i < 15; ++i)
        free(vertices[i].next);

    free(vertices);

    return 0;
}