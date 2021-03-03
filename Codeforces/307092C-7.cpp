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
    ll res = 0, f = 0;
    for (int i = 0; i < m; ++i)
    {
    	while(f<n && b[i]>a[f])
    		f++;
    	//cout<<a[f]<<' '<<b[i]<<endl;
    	if(b[i]!=a[f])
    		continue;
       	ll cnt1 =0, cnt2 = 1;
    	while(f<n && b[i]==a[f]){
    		cnt1++;
    		f++;
    	}
    	while(i<m-1 && b[i+1]==b[i]){
    		cnt2++;
    		i++;
    	}
    	//cout<<i<<' '<<cnt1<<' '<<cnt2<<endl;
    	if(cnt2>1)
    		i--;
    	res+=cnt1*cnt2;

    }
    cout<<res<<'\n';
    return 0;
}