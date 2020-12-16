#include<bits/stdc++.h>
using namespace std;
const long long nax = 2e5 + 69;
long long n,a[nax],b[nax],m,curr;
bool check(long long val){
	for (long long i = 0; i < n; ++i)
	{
		b[i] = a[i] + (i+1)*val;
	}
	curr = 0;
	sort(b,b+n);
	for (long long i = 0; i < val; ++i)
	{
		curr+=b[i];
	}
	return curr<=m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for (long long i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    long long l = 0,r = n,ans=0;
    while(l<=r){
    	long long mid = (l+r)/2;
    	if(check(mid)){
    		ans = curr;
    		l = mid + 1;
    	}
    	else r = mid - 1;
    }
    cout<<l-1<<' '<<ans<<'\n';
    return 0;
}