#include <bits/stdc++.h>

truct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    vector<int> ans;
    if (!root)
        return ans;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();

        if (!mp[h])
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
