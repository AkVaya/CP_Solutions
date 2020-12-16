#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,n,a[nax];
    cin>>t;
    while(t--){ 
    	cin>>n;
    	map<int,vector<int> > m;
    	for (int i = 1; i <= n; ++i)
    	{
    		cin>>a[i];
    		if(!m[a[i]].size())
    			m[a[i]].push_back(0);
    		m[a[i]].push_back(i);
    	} 
    	vector<int> ans(n+1,nax);
    	for(auto i : m){
    		i.second.push_back(n+1);
    		int currval = 0;
    		for (int j = 1; j < i.second.size(); ++j)
    		{
    			currval = max(currval,i.second[j]-i.second[j-1]);
    		}
    		ans[currval] = min(ans[currval],i.first);
    	}
    	for (int i = 1; i < n+1; ++i)
    	{
    		if(i>1)
    			ans[i] = min(ans[i],ans[i-1]);
    		cout<<(ans[i]==nax ? -1 : ans[i])<<' ';
    	}
    	cout<<'\n';
	}
    return 0;
}