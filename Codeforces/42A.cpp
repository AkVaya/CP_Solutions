#include<bits/stdc++.h>
using namespace std;
const long long nax = 69;
double n,a[nax],b[nax],v;
bool check(double val){
	for (int i = 0; i < n; ++i)
	{
		if(a[i]*val>b[i])
			return false;
	}
	return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>v;
    for (long long i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	cin>>b[i];
    }
    double l = 0,r = 2000000;
    for (int i = 0; i < 100; ++i)
    {
    	double mid = (l+r)/2.0;
    	if(check(mid))
    		l = mid;
    	else
    		r = mid;
    }
    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
    	ans+=(a[i]*l);
    }
    cout<<fixed<<setprecision(5);
    cout<<min(ans,v)<<'\n';
    return 0;
}