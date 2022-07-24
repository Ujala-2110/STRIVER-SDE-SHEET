#include<bits/stdc++.h>

string reverseString(string s)
{
    // Write your code here.
    string out,t;
    stringstream ss(s);
    for(ss>>out; ss>>s; out = s+" "+out); 
//     while(ss >> out) t = out+" "+t;
//     return t;
     return out;
}


string reverseString(string s)
{
    // Write your code here.
    if(s.size() == 0) return s;
    stack<string> st;
    string result;
    for(int i=0; i<s.size(); i++) {
        string word;
        if(s[i]==' ') continue;
        while(i<s.size() && s[i]!=' ' ) { 
            word += s[i]; i++;
        }
        st.push(word);
    }
    while(!st.empty()) {
        result += st.top(); st.pop();
        if(!st.empty()) result += " ";
    }
    return result;
}