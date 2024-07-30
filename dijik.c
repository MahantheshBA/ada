#include <stdio.h>

#define MAX 20

#define infinity  99

int n;

int a[MAX] [MAX];

void ReadMatrix();

void Dijkstras(int s);

int Extract_Min(int S[], int d[]);

int main()

{

int s = 0;

printf("Enter the number of vertices: ");

scanf("%d", &n);

ReadMatrix();

printf("Enter starting vertex: ");

scanf("%d", &s);

Dijkstras(s);

return 0;
}
void ReadMatrix()
{

int i, j;

printf("Enter the cost adjacency Matrix:\n");

for (i=1; i <= n; i++)
        for (j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);

}

void Dijkstras(int s)
{


int S[MAX], d[MAX];

int u, v, i;

for (i=1; i <= n; i++)

{
        S[i] = 0;
        d[i] = a[s] [i];

}
S[s] = 1 ;

d[s] = 1 ;

i = 2;

while (i <= n)

{

u = Extract_Min(S, d);
S[u] = 1 ;

i++;

for ( v = 1 ; v <= n; v++)

{
        if ((d[u] + a[u] [v] < d[v]) && (S[v] == 0 ))
          d[v] = d[u] + a[u] [v];
}
}
 for (i=1; i <= n; i++)

{

if (i!= s)
        printf("%d;%d\n", i, d[i]);

}

}

int Extract_Min(int S[], int d[])

{
        int i, j=1, min=infinity;
        for (i=1; i <= n; i++)

                {

if (d[i] < min && S[i] == 0)

{
        min = d[i];
        j = i;

}

}
return j;

}
