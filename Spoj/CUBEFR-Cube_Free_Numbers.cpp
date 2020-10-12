#include<bits/stdc++.h>
using namespace std;
int nax = 1e6+69;
bitset<1000069> bs;
vector<int> ans(nax,0);
void sieve(){
	bs[0]=bs[1]=1;
	int cnt = 0;
	ans[1]=++cnt;
	for (long long i = 2; i < nax; ++i)
	{
		if(!bs[i]){
			ans[i]=++cnt;
			long long int cube = i*i*i;
			for (long long j = cube; j < nax; j+=cube)
			{
				bs[j] = 1;	
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,x=1;
	sieve();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case "<<x++<<": ";
		if(ans[n])
			cout<<ans[n]<<'\n';
		else
			cout<<"Not Cube Free"<<'\n';
	}
}