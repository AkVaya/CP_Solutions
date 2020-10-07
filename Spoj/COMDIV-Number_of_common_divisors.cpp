#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,a,b,g;
	cin>>t;
	while(t--){
		cin>>a>>b;
		g = __gcd(a,b);
		int ans = 1;
		for (int i = 2; i*i <= g; ++i)
		{
			if(g%i==0){
				if(i!=g/i)
					ans++;
				ans++;
			}
		}
		if(g!=1)
			ans++;
		cout<<ans<<'\n';
	}
	return 0;
}