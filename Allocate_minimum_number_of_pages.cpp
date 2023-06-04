#include<bits/stdc++.h>

bool is_possible(int br, int arr[], int k, int n)
{
    int st = 1;
    int sum = arr[0];

    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum >= br)
        {
            st++;
            sum = arr[i];
        }

        if (st >= k)
            return true;
    }

    return false;
}

int findPages(int arr[], int n, int m)
{
    // code here
    if (n < m)
        return -1;

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int mini = *min_element(arr, arr + n);
    int lo = mini, hi = sum;

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (is_possible(mid, arr, m, n))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return ans;
}