#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// adjacency list node
typedef struct Node {
    int city;
    struct Node* next;
} Node;

Node** graph;
bool* visited;

// add edge
void add_edge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->city = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

// DFS to explore connected component
int dfs(int u) {
    visited[u] = true;
    int count = 1;
    for (Node* temp = graph[u]; temp; temp = temp->next) {
        if (!visited[temp->city]) {
            count += dfs(temp->city);
        }
    }
    return count;
}

// free adjacency list
void free_graph(int n) {
    for (int i = 1; i <= n; i++) {
        Node* curr = graph[i];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(graph);
    free(visited);
}

long roadsAndLibraries(int n, int c_lib, int c_road, int m, int cities[m][2]) {
    if (c_lib <= c_road) return (long)n * c_lib;

    // init graph
    graph = (Node**)calloc(n + 1, sizeof(Node*));
    visited = (bool*)calloc(n + 1, sizeof(bool));

    // build graph
    for (int i = 0; i < m; i++) {
        int u = cities[i][0];
        int v = cities[i][1];
        add_edge(u, v);
        add_edge(v, u);
    }

    long total_cost = 0;

    // explore each component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int comp_size = dfs(i);
            total_cost += c_lib;                          // one library
            total_cost += (long)(comp_size - 1) * c_road; // roads for rest
        }
    }

    free_graph(n);
    return total_cost;
}

// -------- main ----------
int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n, m, c_lib, c_road;
        scanf("%d %d %d %d", &n, &m, &c_lib, &c_road);

        int (*cities)[2] = malloc(m * sizeof *cities);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &cities[i][0], &cities[i][1]);
        }

        long ans = roadsAndLibraries(n, c_lib, c_road, m, cities);
        printf("%ld\n", ans);

        free(cities);
    }

    return 0;
}
