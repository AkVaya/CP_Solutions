#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,val = 1;
        cin>>n;
        vector<long long>a(n+1),x(n+1,0),y(n+1,0),z(n+1,0);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        x[0]=y[0]=z[0]=a[0];
        for (int i = 1; i < n; ++i)
        {
        	x[i] = ((x[i-1]*a[i])%M + (val*a[i])%M);
        	y[i] = (z[i-1] + x[i])%M;
        	z[i] = (z[i-1] + y[i])%M;
        	val = (val*2)%M;
        }
        cout<<y[n-1]<<endl;
    }
    return 0;
}