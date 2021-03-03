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
    int res[m], f = 0;
    for (int i = 0; i < m; ++i)
    {
    	while(f<n && a[f]<b[i])
    		f++;
    	cout<<f<<' ';
    }
    return 0;
}