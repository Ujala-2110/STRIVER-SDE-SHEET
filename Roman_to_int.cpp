#include <bits/stdc++.h>
int romanToInt(string s)
{
    // Write your code here
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V')
        {
            num += 4;
            i++;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            num += 9;
            i++;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            num += 40;
            i++;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            num += 90;
            i++;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            num += 400;
            i++;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            num += 900;
            i++;
        }

        else
        {
            if (s[i] == 'I')
                num += 1;
            else if (s[i] == 'V')
                num += 5;
            else if (s[i] == 'X')
                num += 10;
            else if (s[i] == 'L')
                num += 50;
            else if (s[i] == 'C')
                num += 100;
            else if (s[i] == 'D')
                num += 500;
            else if (s[i] == 'M')
                num += 1000;
        }
    }

    return num;
}

int romanToInt(string s)
{
    // Write your code here
    unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    int ans = mp[s.back()];
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            ans = ans - mp[s[i]];
        }
        else
        {
            ans = ans + mp[s[i]];
        }
    }
    return ans;
}

// INTEGER TO ROMAN
int INT_To_ROMAN(int num)
{
    // Write your code here
    int intCode[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string s;
    for (int i = 0; i < 13; ++i)
    {
        while (num >= intCode[i])
        {
            s.append(code[i]);
            num -= intCode[i];
        }
    }
    return s;
}