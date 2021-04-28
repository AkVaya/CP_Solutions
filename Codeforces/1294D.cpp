#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int q,x,min = 0,curr = 0;
	cin>>q>>x;
	vector<int> cnt(x+1,0);
	map<int,set<int> > m;
	for (int i = 0; i < x; ++i)
		m[0].insert(i);
	while(q--){
		int n;
		cin>>n;
		int rem  = n%x;
		m[cnt[rem]].erase(rem);
		cnt[rem]++;
		m[cnt[rem]].insert(rem);
		while(m[min].size()==0)
			min++;
		//cout<<min<<' ';
		//for(auto i : m[min])
		//	cout<<i<<' ';
		cout<<(((min)*x)+(*m[min].begin()))<<'\n';
	}
	return 0;
}