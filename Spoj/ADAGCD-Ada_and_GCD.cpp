#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
vector<long long>spd(10000001,0);
void sieve(){
	for (int i = 1; i <= 1e7; ++i)
	{
		if(i%2)
			spd[i] = i;
		else
			spd[i] = 2;
	}
	for (long long i = 3; i <= 1e7; i+=2)
		if(spd[i]==i)
			for (long long j = i*i; j <= 1e7; j+=i)
				if(spd[j]==j)
					spd[j] = i; 
}
long long binpow(long long a,long long b){
	long long res = 1;
	while(b){
		if(b&1)
			res = (res * a)%M;
		a = (a * a)%M;
		b>>=1;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	long long n,m,x,ans = 1;
	cin>>n;
	unordered_map<long long,long long> final;
	bool check = false;
	for (int i = 0; i < n; ++i)
	{
		cin>>m;
		unordered_map<long long,long long> temp;
		while(m--){
			cin>>x;
			while(x>1){
				temp[spd[x]]++;
				x/=spd[x];
			}
		}
		if(!check){
			for(auto i : temp){
				final[i.first] = i.second;
			}
			check = true;
		}
		else{
			for(auto i : final){
				final[i.first] = min(i.second,temp[i.first]);
			}
		}
	}
	for(auto i : final){
		if(i.second){
			ans = (ans*binpow(i.first,i.second))%M;
		}
	}
	cout<<ans<<'\n';
	return 0;
}