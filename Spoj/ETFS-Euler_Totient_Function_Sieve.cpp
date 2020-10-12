#include<bits/stdc++.h>
using namespace std;
bitset<10000001> bs;
vector<long long int> primes;
void sieve(){
	bs[0] = bs[1] = 1;
	primes.emplace_back(2);
	for (long long int i = 3; i <= 1e7; i+=2)
	{
		if(!bs[i]){
			primes.emplace_back(i);
			for (long long int j = i*i; j <= 1e7; j+=i)
			{
				bs[j] = 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	long long int a,b;
	sieve();
	cin>>a>>b;
	vector<long long int> phi(b-a+1,0),val(b-a+1,0);
	for (long long int i = a; i <= b; ++i)
	{
		phi[i-a] = i;
		val[i-a] = i; 
	}
	for(auto j : primes){
		if(j>b)
			break;
		for (long long int i = ((a+j-1)/j) * j; i <= b; i+=j)
		{
			phi[i-a]-=(phi[i-a]/j);
			while(val[i-a]%j==0)
				val[i-a]/=j; 
		}
	}
	for (int i = 0; i <= b-a; ++i)
	{
		if(val[i]>1)
			phi[i]-=(phi[i])/val[i];
		cout<<phi[i]<<'\n';
	}
	return 0;
}