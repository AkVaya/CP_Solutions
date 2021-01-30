#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 69;
const int M = 1e9 + 7;
using ll = long long;
bool cmp(const pair<double,double>&a,const pair<double,double>&b){
	if(a.first==b.first)
		return a.second<b.second;
	return a.first>b.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n,m,sum=0;
		cin>>n>>m;
		priority_queue<ll> one,two;
		ll a[n],b[n],res = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			sum+=a[i];
			one.push(-INT_MAX);
			two.push(-INT_MAX);
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>b[i];
			if(b[i]==1)
				one.push(a[i]);
			else
				two.push(a[i]);
		}
		if(sum<m){
			cout<<"-1\n";
			continue;
		}
		sum = 0;
		while(sum<m){
			int fir = one.top();
			one.pop();
			int sec =  one.top();
			one.pop();
			int val = two.top();
			two.pop();
			if(fir>=val || sum+fir>=m){
				sum+=fir;
				two.push(val);
				one.push(sec);
				res++;
			}
			else if(fir!=-INT_MAX && sec!=-INT_MAX && fir+sec>=val){
				sum+=fir;
				one.push(sec);
				two.push(val);
				res++;
			}
			else{
				sum+=val;
				one.push(fir);
				one.push(sec);
				res+=2;
			}
			//cout<<sum<<' '<<fir<<' '<<sec<<' '<<val<<' '<<endl;
		}
		cout<<res<<'\n';
	}
	return 0;
}