#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node {
    int vertex;
    struct node *next;
};
typedef struct node* Gnode;
Gnode graph[MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

int isEmptyQueue() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int deleteQueue() {
    int deleteItem;
    if (front == -1 || front > rear) {
        printf("Queue Underflow.\n");
        exit(1);
    }
    deleteItem = queue[front];
    front++;
    return deleteItem;
}

void insertQueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow.\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

void BFS(int v) {
    Gnode g;
    int w;
    insertQueue(v);
    visited[v] = 1;
    printf("%d ", v);
    while (!isEmptyQueue()) {
        v = deleteQueue();
        g = graph[v];
        while (g != NULL) {
            w = g->vertex;
            if (visited[w] == 0) {
                insertQueue(w);
                visited[w] = 1;
                printf("%d ", w);
            }
            g = g->next;
        }
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
        visited[i] = 0;
    }
    int startVertex;
    printf("Enter Start Vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS of graph: \n");
    BFS(startVertex);
    printf("\n");
    return 0;
}
