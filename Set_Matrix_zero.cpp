#include <bits/stdc++.h>
using nameespace std;
void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> indx, indy;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                indx.push_back(i);
                indy.push_back(j);
            }
        }
    }

    for (int indj = 0; indj < indy.size(); indj++)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][indy[indj]] = 0;

    for (int indi = 0; indi < indx.size(); indi++)
        for (int j = 0; j < m; j++)
            matrix[indx[indi]][j] = 0;
}
