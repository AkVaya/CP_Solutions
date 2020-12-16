#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int main()
{
	string s;
	cin>>s;
	long long res = 1,cnt1=0,cnt2 = 0;
	int n = s.length();
	vector<long long> fib(n+5,0);
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i <= n; ++i)
	{
	 	fib[i] = (fib[i-1] + fib[i-2])%M;
	} 
	fib[1] = 0;
	for (auto i : s)
	{
		if(i=='m' || i=='w'){
			cout<<"0\n";
			return 0;
		}
		if(i=='u'){
			cnt1++;
		}
		else{
			if(cnt1>1)
				res = (res*fib[cnt1])%M;
			cnt1=0;
		}
		if(i=='n')
			cnt2++;
		else{
			if(cnt2>1)
				res = (res*fib[cnt2])%M;
			cnt2=0;
		}
	}
	if(cnt1>1)
		res = (res*fib[cnt1])%M;
	if(cnt2>1)
		res = (res*fib[cnt2])%M;
	cout<<res<<'\n';
	return 0;
}