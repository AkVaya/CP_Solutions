#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n], res = 0,curr = 0,l = 0,r = 0;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	curr+=a[i];
    	while(l<=i && curr>=m){
			curr-=a[l++];
		}
		//cout<<i<<' '<<l<<endl;
		res+=l;
    }    
    cout<<(res==INT_MAX ? -1 : res)<<'\n';
    return 0;
}