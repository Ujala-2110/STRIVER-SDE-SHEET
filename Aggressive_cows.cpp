#include <bits/stdc++.h>

bool check(vector<int> &arr, int d, int k)
{
    int n = arr.size();
    int cows = 1;
    int cord = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - cord >= d)
        {
            cows++;
            cord = arr[i];
        }

        if (cows >= k)
            return true;
    }

    return false;
}

int solve(int n, int k, vector<int> &stalls)
{

    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    int ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(stalls, mid, k))
        {
            low = mid + 1;
            ans = mid;
        }

        else
            high = mid - 1;
    }

    return ans;
}