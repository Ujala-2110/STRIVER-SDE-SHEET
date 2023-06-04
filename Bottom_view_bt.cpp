#include <bits/stdc++.h>

vector<int> bottomView(Node *root)
{
    // Your Code Here

    vector<int> ans;
    queue<pair<Node *, int>> q;
    map<int, int> mp;

    if (!root)
        return ans;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();

        mp[h] = curr->data;

        if (curr->left)
            q.push({curr->left, h - 1});
        if (curr->right)
            q.push({curr->right, h + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}