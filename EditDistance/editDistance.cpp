#include <iostream>
#include <string.h>

using namespace std;

int mini(int a, int b, int c)
{
    if(a < b)
        return (a < c? a : c);
    else
        return (b < c? b : c);
}

int editDistance(char *X, char *Y, int m, int n)
{
    if(m == 0)
        return n;
    if(n == 0)
        return m;

    if(X[m-1] == Y[n-1])
    {
        return (editDistance(X, Y, m-1, n-1));
    }
    else
    {
        return ( 1 + mini(editDistance(X, Y, m-1, n), editDistance(X, Y, m, n-1), editDistance(X, Y, m-1, n-1)));
    }
}

int editDistDP(char * X, char * Y, int m, int n)
{
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(X[i-1] == Y[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = ( 1 + mini(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main()
{
    char * s1 = "ABCD";
    char * s2 = "ABDH";
    cout << "Edit distance Recursion : " << editDistance(s1, s2, strlen(s1), strlen(s2)) << endl;
	cout << "Edit distance DP : " << editDistDP(s1, s2, strlen(s1), strlen(s2)) << endl;

    return 0;
}
