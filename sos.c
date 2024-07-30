#include <stdio.h>
int n, a[100], i, x[100], total, sol_no;
void sumOfSubset(int sum, int k, int rem);
void main() {
int rem = 0;
printf("Enter the number of elements(value of n): ");
scanf("%d", &n);
printf("Enter the elements(Set of n elements): ");
for (i = 1; i <= n; i++) {
scanf("%d", &a[i]);
rem += a[i];
}
printf("Enter the sum total to be computed(value of d): ");
scanf("%d", &total);
printf("The possible combinations are:\n");
sumOfSubset(0, 1, rem);
}
void sumOfSubset(int sum, int k, int rem) 
{
x[k] = 1;
if (sum + a[k] == total)
{
printf("Solution #%d:\t", ++sol_no);
for (i = 1; i <= k; i++)
if (x[i])
printf("%d\t", a[i]);
printf("\n");
} 
else if (sum + a[k] + a[k + 1] <= total)
sumOfSubset(sum + a[k], k + 1, rem - a[k]);
if ((sum + rem - a[k] >= total) && (sum + a[k + 1] <= total)) 
{
x[k] = 0;
sumOfSubset(sum, k + 1, rem - a[k]);
}
}
