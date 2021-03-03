#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
	int n;
	cin>>n;
	int a[n],g,res = 0;
	cin>>a[0];
	g = a[0];
	for (int i = 1; i < n; ++i)
	{
		cin>>a[i];
		g = __gcd(a[i],g);
	}
	if(g>1){
		cout<<"YES\n0\n";
		return 0;
	}
	for (int i = 0; i < n-1; ++i)
	{
		int v1 = a[i]&1 , v2 = a[i+1]&1;
		if(v1 && v2){
			int temp = a[i];
			a[i]-=a[i+1];
			a[i+1]+=temp;
			res++;
		}
	}
	for (int i = 0; i < n-1; ++i)
	{
		int v1 = a[i]&1 , v2 = a[i+1]&1;
		while(v1 || v2){
			int temp = a[i];
			a[i]-=a[i+1];
			a[i+1]+=temp;
			res++;
			v1 = a[i]&1;
			v2 = a[i+1]&1;
		}
	}
	cout<<"YES\n"<<res<<'\n';
   	return 0;
}