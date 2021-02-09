#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n+69]={0};
    vector<vector<int> >v(n+1);
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    	v[a[i]].push_back(i);
    }
    if(n==1){
    	cout<<1<<'\n';
    	return 0;
    }
    int f = a[0], s = 0,res = 1;
    for (int i = 1; i < n; ++i)
    {
    	if(a[i]==f || a[i]==s)
    		continue;
    	if(!s){
    		res++;
    		s = a[i];
    		continue;
    	}
    	auto it1 = lower_bound(v[f].begin(),v[f].end(),i);
    	auto it2 = lower_bound(v[s].begin(),v[s].end(),i);
    	if(it1==v[f].end()){
    		f = a[i];
    		res++;
    	}
    	else if(it2==v[s].end() || *it1<*it2){
    		s = a[i];
    		res++;
    	}
    	else{
    		f = a[i];
    		res++;
    	}
    }
    cout<<res<<'\n';
    return 0;
}