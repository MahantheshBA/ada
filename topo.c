#include <stdio.h>
int topologicalSort(int a[10][10], int n, int indegree[10]);
int main() {
int a[10][10], indegree[10] = {0}, i, j, n;
printf("Enter the number of nodes: ");
scanf("%d", &n);
printf("Enter the Adjacency Matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &a[i][j]);
if (a[i][j] == 1)
indegree[j]++;
}
}
printf("The Topological Sorted Order is:\n");
topologicalSort(a, n, indegree);
return 0;
}
int topologicalSort(int a[10][10], int n, int indegree[10]) {
int i, j;
for (i = 1; i <= n; i++) {
if (indegree[i] == 0) {
printf("%d\t", i);
indegree[i]--;
for (j = 1; j <= n; j++)
if (a[i][j] == 1)
indegree[j]--;
i = 1;
}
}
}
