#include <iostream>

using namespace std;


int knapsack(int val[], int wt[], int n, int maxW)
{
    if(0 == n || 0 == maxW)
        return 0;

    if(maxW < wt[n-1])
    {
        return knapsack(val, wt, n-1, maxW);
    }
    else
    {
        return(max(val[n-1] + knapsack(val, wt, n-1, maxW-wt[n-1]), knapsack(val, wt, n-1, maxW)));
    }
}

void printMatrix(int * mat, int m, int n)
{
    cout << endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << *(mat + i*n + j) << " " ;
        }
        cout << endl;
    }
}


int knapsackDP(int val[], int wt[], int n, int maxW)
{
    int dp[n+1][maxW+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=maxW; j++)
        {
            if(0 == i || 0 == j)
                dp[i][j] = 0;
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);

            //cout << "dp[" << i << "]" << "[" << j << "] = " << dp[i][j] << endl;
        }
    }
    //printMatrix((int *)dp, n+1, maxW+1);
    return dp[n][maxW];
}


int main()
{

    int weight[] = {1,3,5,7};
    int value[] = {2,4,8,6};
    int maxVal;
    cin >> maxVal;

    cout << "maximum value: " << knapsack(value, weight, 4, maxVal) << endl;
    cout << "maximum value DP: " << knapsackDP(value, weight, 4, maxVal) << endl;

    return 0;
}
