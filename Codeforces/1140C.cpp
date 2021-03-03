#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	int n,k;
	cin>>n>>k;
	ll res = 0;
	vector<pair<ll,ll> > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i].second>>v[i].first;
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for (int i = n-1; i >= 0; --i)
	{
		if(pq.size()<k){
			pq.push(v[i].second);
			sum+=v[i].second;
			res = max(res,v[i].first*sum);
		}
		else{
			if(pq.top()<v[i].second){
				sum-=pq.top();
				pq.pop();
				pq.push(v[i].second);
				sum+=v[i].second;
			}
			//cout<<v[i].second<<' '<<v[i].first<<endl;
			res = max(res, v[i].first*sum);
		}
	}
	cout<<res<<'\n';

   	return 0;
}