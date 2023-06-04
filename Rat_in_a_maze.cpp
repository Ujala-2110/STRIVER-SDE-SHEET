#include <bits/stdc++.h>

bool is_safe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &vis)
{
    if (x < 0 || x == n || y < 0 || y == n || vis[x][y] == 1)
        return false;

    return true;
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

string dir = "DLRU";

void func(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string s,
          vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }

    for (int ind = 0; ind < 4; ind++)
    {
        int nx = i + dx[ind];
        int ny = j + dy[ind];

        if (is_safe(nx, ny, m, n, vis) && m[nx][ny] == 1)
        {
            vis[i][j] = 1;
            func(nx, ny, m, n, ans, s + dir[ind], vis);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string s = "";
    func(0, 0, m, n, ans, s, vis);
    return ans;
}