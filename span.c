#include <stdio.h>

int main() {
    int w[10][10], sol[10];
    int n, i, j, s, k = 0;
    int min, sum = 0, u = 0, v = 0;
    int flag = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        sol[i] = 0;

    printf("Enter the weighted graph:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    sol[s] = 1;
    k = 1;

    while (k <= n - 1) {
        min = 99; // Assuming max weight is 99; adjust as per your graph constraints

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (sol[i] == 1 && sol[j] == 0 && w[i][j] < min) {
                    min = w[i][j];
                    u = i;
                    v = j;
                }

        sol[v] = 1;
        sum = sum + min;
        k++;
        printf("%d->%d=%d\n", u, v, min);
    }

    for (i = 1; i <= n; i++)
        if (sol[i] == 0)
            flag = 1;

    if (flag == 1)
        printf("No spanning tree\n");
    else
        printf("The cost of minimum spanning tree is %d\n", sum);

    return 0;
}
