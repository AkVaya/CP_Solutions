#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	int n;
	cin>>n;
	int a[n];
	vector<pair<int,int> > sec, last(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		last[i] = {0, a[i]};
	}
	int q,t,x,y;
	cin>>q;
	vector<int> mx(q+1,0);
	for(int i = 0; i < q; ++i){
		cin>>t;
		if(t==1){
			cin>>x>>y;
			last[x-1] = {i+1, y};
		}
		else{
			cin>>x;
			mx[i+1] = x;
		}
	}
	for (int i = q-1; i >= 0; --i)
	{
		mx[i] = max(mx[i],mx[i+1]);
	}
	for (int i = 0; i < n; ++i){
		a[i] = max(last[i].second, mx[last[i].first]);
	}

	
	for (int i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}