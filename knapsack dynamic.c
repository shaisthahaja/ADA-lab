#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, i, j;
    int wt[20], val[20];
    int W;
    int dp[20][20];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits/values of items:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(wt[i] <= j)
            {
                dp[i][j] = max(val[i] + dp[i-1][j-wt[i]],
                               dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}
