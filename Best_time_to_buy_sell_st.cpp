#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = prices[0];
    int max_profit = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        max_profit = max(max_profit, cost);

        mini = min(mini, prices[i]); 
    }

    return max_profit;
}