#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int> >v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i].first.first>>v[i].first.second;
    	v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
    	bool check = false;
    	for (int j = 0; j < n; ++j)
    	{
    		if(j==i)
    			continue;
    		if(j && j!=i+1 && v[j-1].first.second>v[j].first.first){
    			check = true;
    			break;
    		}
    		else if(j==i+1 && j>1 && v[j-2].first.second>v[j].first.first){
    			check = true;
    			break;
    		}
    	}
    	if(!check)
    		res.push_back(v[i].second);
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto i : res)
    	cout<<i<<' ';
    return 0;
}