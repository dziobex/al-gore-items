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

    parent->next = (V**) realloc(parent->next, parent->next_count * sizeof(V*));
    parent->next[parent->next_count - 1] = child;
}

void BFS(V *v) {
    int queue_count = 1;

    V **queue;
    queue = (V**)malloc(sizeof(V*));
    queue[0] = v;

    while (queue_count-- > 0) {
        printf("%d ", queue[0]->value);
        
        V *temp = queue[0];

        // obsuwa elementow

        for (int i = 1; i < (queue_count + 1); ++i)
            queue[i - 1] = queue[i];
        
        // rozszerzam tablice o dodatkowe miejsca dla dzieci obecnego wierzcholka
        
        queue = (V**)realloc(queue, sizeof(V*) * (queue_count + temp->next_count));

        // dodam dzieci wierzcholka queue[0]

        for (int i = 0; i < temp->next_count; ++i)
            queue[queue_count + i] = temp->next[i];

        // update liczby wierzcholkow do przejscia

        queue_count += temp->next_count;

        free(temp);
    }

    free(queue);
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

    BFS(&vertices[8]);

    // czyszczenie
    
    for (int i = 0; i < 15; ++i)
        free(vertices[i].next);

    free(vertices);

    return 0;
}