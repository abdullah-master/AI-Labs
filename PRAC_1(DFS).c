#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};
typedef struct node* Gnode;
Gnode graph[20];
int visit[20];

void DFS(int i) {
    Gnode p;
    printf("%d ", i);
    visit[i] = 1;
    p = graph[i];
    while (p != NULL) {
        if (!visit[p->vertex]) {
            DFS(p->vertex);
        }
        p = p->next;
    }
}

int main() {
    int N, E, i, s, d;
    Gnode q, p;
    printf("Enter the number of vertices: ");
    scanf("%d", &N);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (i = 0; i < N; i++) {
        graph[i] = NULL; // Initialize adjacency list
    }
    for (i = 0; i < E; i++) {
        printf("Enter source: ");
        scanf("%d", &s);
        printf("Enter destination: ");
        scanf("%d", &d);
        q = (Gnode)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;
        if (graph[s] == NULL) {
            graph[s] = q;
        } else {
            p = graph[s];
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = q;
        }
    }
    for (i = 0; i < N; i++) {
        visit[i] = 0;
    }
    int startVertex;
    printf("Enter Start Vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS of graph: \n");
    DFS(startVertex);
    printf("\n");
    return 0;
}
