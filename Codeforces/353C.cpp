#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 69;
using ll = long long ; 
int main(){
	int n;
	cin>>n;
	ll a[n],curr = 0,till=0,res=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	string s;
	cin>>s;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='1')
			curr+=a[i];
	}
	//cout<<curr<<endl;
	res = curr;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='1'){
			res = max(res,curr-a[i]+till);
		}
		else
			till+=a[i];
		//cout<<i<<' '<<res<<' '<<till<<endl;
	}
	cout<<res<<'\n';
	return 0;
}