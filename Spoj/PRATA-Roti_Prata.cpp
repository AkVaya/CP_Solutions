#include<bits/stdc++.h>
using namespace std;
const long long nax = 69;
long long n,m,a[nax];
bool check(long long t){
	long long curr = 0;
	for (int i = 0; i < m; ++i)
	{
		long long temp = t/a[i];
		if(temp<1)
			continue;
		curr += (-1 + sqrtl(temp*8 + 1))/2;
	}
	//cout<<t<<' '<<curr<<endl;
	return curr>=n;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
			cin>>a[i];
		}
		long long l = 1, r = 1e18;
		while(l<=r){
			long long mid = l + (r-l)/2;
			if(check(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		cout<<r+1<<'\n';
	}
	return 0;
}