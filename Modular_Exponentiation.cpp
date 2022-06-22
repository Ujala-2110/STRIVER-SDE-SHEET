#include <bits/stdc++.h> 

    int binExp(int a, int b, int m)
    {
      int ans = 1;

      while(b>0)
      {
        if(b&1) ans = (ans * 1LL *a) % m;

        a = (a*1LL*a) % m;
        b >>= 1;
      }

      return ans;
    }
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    return binExp(x,n,m);
}