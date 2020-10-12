#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const long long nax = 1e6 + 69;
long long n,a[nax],m;
bool check(long long val){
	long long curr = 0;
	for (int i = 0; i < n; ++i)
	{
		curr += max(0LL,a[i]-val);
	}
	return curr>=m;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	long long mx = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		mx = max(a[i],mx);
	}
	long long l = 0, r = mx;
	while(l<=r){
		long long mid = l + (r-l)/2;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout<<l-1<<'\n';
}