#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,k;
    cin>>n>>q>>k;
    int a[n],val[n+1] = {0},pref[n+1] = {0};
    for (int i = 0; i < n; ++i)
    	cin>>a[i];
    val[0] = a[0]-1;
    for (int i = 1; i < n-1; ++i)
    {
    	val[i] = a[i+1] - a[i-1] - 2;
    }
    val[n-1] = (k-a[n-1]);
    pref[0] = 0;
    for (int i = 0; i < n; ++i)
    {
    	pref[i] = val[i];
    	if(i)
    		pref[i]+=pref[i-1];
    }
    while(q--){
    	int l,r;
    	cin>>l>>r;
    	l--;
    	r--;
    	if(l==r){
    		cout<<k-1<<'\n';
    		continue;
    	}
    	int res = pref[r]-(l ? pref[l-1] : 0);
    	res-=val[l] + val[r];
    	if(l<n-1)
    		res+=a[l+1]-2;
    	if(r)
    		res+=k-a[r-1]-1;
    	cout<<res<<endl;
    }
    return 0;
}