#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n,res = 0;
	cin>>n;
	string s;
	cin>>s;
	map<int,int> start;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]=='S')
			continue;
		int cnt = 0,st = i;
		while(i<n && s[i]=='G'){
			i++;
			cnt++;
		}
		i--;
		start[st] = cnt;
	}
	for(auto i : start){
		int curr = i.first,val = i.second;
		//cout<<curr<<' '<<val<<endl;
		auto it = start.upper_bound(curr+1);
		res = max(res, val);
		if(start.size()>1){
			res = max(res, val + 1);
		}
		if(it==start.end())
			continue;
		//cout<<it->first<<' '<<it->second<<endl;
		if(it->first==curr+val+1){
			res = max(res, val + it->second + (start.size()>2 ? 1 : 0) );
		}
		//cout<<endl;
	}
	cout<<min(res,n)<<'\n';
	return 0;
}