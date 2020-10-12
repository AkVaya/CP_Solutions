#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e4 + 1;
vector<long long> phi(10001,0);
bitset<10001> bs;
void totient(){
	for (int i = 0; i < nax; ++i)
	{
		if(i%2)
			phi[i] = i;
		else
			phi[i] = i/2;
	}
	for (int i = 3; i < nax; i+=2)
	{
		if(!bs[i]){
			for (int j = i; j < nax; j+=i)
			{
				phi[j] -= (phi[j]/i);
				bs[j]=1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	totient();
	int t;
	cin>>t;
	long long n;
	vector<long long> all(nax,0);
	for (int i = 1; i < nax; ++i)
	{
		all[i] = all[i-1] + phi[i];
	}
	while(t--){
		cin>>n;
		cout<<all[n]*all[n]<<"\n";
	}
	return 0;
}