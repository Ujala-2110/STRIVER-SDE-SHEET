double multiply(double mid , int n)
{
    double ans = 1.0;
    for(int i=1;i<=n;i++)
    {
        ans = ans * mid;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
	// Write your code here.
    double low = 1;
    double high = m;
    double eps = 1e-8; 

    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        double mul = multiply(mid, n);
        if(mul == m) return mid;
        else if(mul < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    return low;
}







