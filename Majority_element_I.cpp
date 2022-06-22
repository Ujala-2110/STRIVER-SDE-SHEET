#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n)
{
    // Write your code here.

    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
        ump[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (ump[arr[i]] > n / 2)
            return arr[i];

    return -1;
}

// Boyer-Moore Majority Voting Algorithm

int findMajorityElement(int arr[], int n)
{
    int num1 = -1, c1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1) c1++;
        else if (c1 == 0)
        {
            num1 = arr[i];
            c1 = 1;
        }

        else c1--;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == num1) cnt++;

    if (cnt > n / 2) return num1;
    else return -1;
}
// TC -> O(N)
// SC -> O(1)