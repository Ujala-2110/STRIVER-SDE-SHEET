#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    // Write your code here.
    string s = "1";
    if (n == 1) return s;
    while (n > 1)
    {
        int cnt = 1;
        string str = "";
        int m = s.length();
        for (int i = 0; i < m; i++)
        {
            if (s[i] == s[i + 1])
            {
                cnt++;
            }
            else
            {
                char c = ('0' + cnt);
                str = str + c + s[i];
                cnt = 1;
            }
        }
        s = str;
        n--;
    }

    return s;
}