#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 1;  
vector<long long> phi(nax,0),val(nax,0);
void sieve(){
	for (int i = 0; i < nax; ++i)
	{
		if(i%2)
			phi[i] = i;
		else
			phi[i] = i/2;
	}
	for (int i = 3; i < nax; i+=2)
	{
		if(phi[i]==i){
			for (int j = i; j < nax; j+=i)
			{
				phi[j] -= (phi[j]/i);
			}
		}
	}
	for (int i = 1; i < nax; ++i)
	{
		for (int j = 2; i*j < nax; j++)
		{
			val[i*j] = (val[i*j] + i*phi[j]);
		}
	}
	for (int i = 2; i < nax; ++i)
	{
		val[i] = (val[i] + val[i-1]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	sieve();
	long long x;
	while(1){
		cin>>x;
		if(!x)
			break;
		cout<<val[x]<<'\n';
	}
	return 0;
} 