#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n], res = 0,curr = 0,l = 0,r = 0;
    map<int,int> cnt;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	if(!cnt[a[i]])
    		curr++;
    	cnt[a[i]]++;
    	while(curr>m){
    		if(cnt[a[l]]==1)
    			curr--;
    		cnt[a[l]]--;
    		l++;
		}
		//cout<<curr<<' '<<i<<' '<<l<<endl;
		if(curr<=m){
			res+=(i-l+1);
		}
    }    
    cout<<(res==INT_MAX ? -1 : res)<<'\n';
    return 0;
}