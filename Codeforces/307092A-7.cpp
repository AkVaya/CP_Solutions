#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < m; ++i)
    {
    	cin>>b[i];
    }
    int f = 0, s = 0;
    int res[n+m], ind = 0;
    while(f<n && s<m){
    	while(f<n && a[f]<=b[s]){
    		res[ind++] = a[f++];
    	}
    	while(s<m && a[f]>=b[s]){
    		res[ind++] = b[s++];
    	}
    }
    while(f<n){
    	res[ind++] = a[f++];
    }
    while(s<m){
   		res[ind++] = b[s++];
    }
    for (int i = 0; i < n+m; ++i)
    {
    	cout<<res[i]<<' ';
    }
    return 0;
}