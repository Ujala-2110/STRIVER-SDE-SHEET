#include <bits/stdc++.h>

bool is_valid(vector<vector<char>> &grid, int i, int j, int val)
{
    for (int k = 0; k < 9; k++)
    {
        if (grid[i][k] == val)
            return false;
        if (grid[k][j] == val)
            return false;
        if (grid[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == val)
            return false;
    }

    return true;
}

bool solve(vector<vector<char>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                for (char val = '1'; val <= '9'; val++)
                {
                    if (is_valid(grid, i, j, val))
                    {
                        grid[i][j] = val;
                        if (solve(grid))
                            return true;
                        else
                            grid[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &grid)
{

    solve(grid);
}