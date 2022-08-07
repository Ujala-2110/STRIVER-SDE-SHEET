#include<bits/stdc++.h>
int lcs(string X, string Y)
{
	//Write your code here
    int n = X.length();
    int m = Y.length();

    int L[n + 1][m + 1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
    return L[n][m];
}



