#include <stdio.h>
struct Kruskal {
    int parent[10]; 
};
int find(struct Kruskal *k, int m) {
    int p = m;
    while (k->parent[p] != 0)
        p = k->parent[p];
    return p;
}

void union_set(struct Kruskal *k, int i, int j) {
    if (i < j)
        k->parent[i] = j;
    else
        k->parent[j] = i;
}

void kruskal_algorithm(int a[10][10], int n) {
    struct Kruskal k;
    int u, v, min, k_count = 0, i, j, sum = 0;

    for (i = 1; i <= n; i++)
        k.parent[i] = 0;

    while (k_count < n - 1) {
        min = 99; 
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (a[i][j] < min && i != j) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(&k, u);
        j = find(&k, v);

        if (i != j) {
            union_set(&k, i, j);
            printf("(%d,%d)=%d\n", u, v, a[u][v]);
            sum += a[u][v];
            k_count++;
        }

        a[u][v] = a[v][u] = 99;
    }

    printf("The cost of minimum spanning tree = %d\n", sum);
}

int main() {
    int a[10][10];
    int i, j, n;

    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);

    printf("Enter the weighted matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    kruskal_algorithm(a, n);

    return 0;
}
