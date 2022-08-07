#include <bits/stdc++.h>

int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here

    int ma = arr[0], mi = arr[0];
    int ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(ma, mi);

        ma = max(arr[i], ma * arr[i]);
        mi = min(arr[i], mi * arr[i]);

        ans = max(ans, ma);
    }

    return ans;
}

//Method -> 2

int maxProduct(vector<int> &nums)
{
    int n = nums.size(), res = nums[0], l = 1, r = 1;
    for (int i = 0; i < n; i++)
    {
        l = (l)*nums[i];
        r = (r)*nums[n - 1 - i];
        res = max(res, max(l, r));
        if (l == 0)
            l = 1;
        if (r == 0)
            r = 1;
    }
    return res;
}