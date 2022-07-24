#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    // Write your code here.
    if (str1.length() != str2.length())
        return false;

    map<char, int> mp, mp1;
    for (int i = 0; i < str1.length(); i++)
    {
        mp[str1[i]]++;
        mp1[str2[i]]++;
    }

    for (int i = 0; i < str1.length(); i++)
    {
        if (mp[str1[i]] != mp1[str1[i]])
            return false;
    }

    return true;
}

// Method -> 2
bool isAnagram(string str1, string str2)
{

    if (str1.length() != str2.length())
        return false;

    unordered_map<char, int> mp;
    for (int i = 0; i < str1.length(); i++)
    {
        mp[str1[i]]++;
        mp[str2[i]]--;
    }

    for (auto it : mp)
        if (it.second)
            return false;

    return true;
}


//Method->3
bool isAnagram(string s, string t)
{

    if (s.size() != t.size()) return false;

    vector<int> v(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a']++;
        v[t[i] - 'a']--;
    }
    for (auto it : v)
    {
        if (it != 0) return false;
    }
    return true;
}