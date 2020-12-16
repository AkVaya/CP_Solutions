#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return (b ? gcd(b,a%b) : a );
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	long long t,a,g;
	cin>>t>>a;
	t--;
	g=a;
	while(t--){
		cin>>a;
		g = gcd(g,a);
	}
	int ans = 0;
	for (long long i = 1; i*i <= g; ++i)
	{
		if(g%i==0){
			ans++;
			if(i!=g/i)
				ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}