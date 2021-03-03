#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
ll n, m, s, d, a[nax];
int main(){
	cin>>n>>m>>s>>d;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	vector<pair<int,int> > res;
	sort(a,a+n);
	if(a[n-1] + 1 < m)
		res.push_back({0,m- a[n-1] - 1});
	int last = a[n-1] + 1;
	for (int i = n-2; i >= 0; --i)
	{
		if(a[i+1]-a[i]-2>=s && a[i+1] - 1 + d>=last){
			res.push_back({1,last-a[i+1]+1});
			res.push_back({0,a[i+1]-a[i]-2});
			last = a[i] + 1;
		}
	}
	if(a[0] - 1 >= s && a[0] - 1 + d>=last){
		res.push_back({1,last - a[0] + 1});
		res.push_back({0,a[0] - 1});
	}
	else{
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for (int i = res.size()-1; i >= 0; --i)
	{
		cout<<(res[i].first ? "JUMP " : "RUN ")<<res[i].second<<'\n';
	}

   	return 0;
}