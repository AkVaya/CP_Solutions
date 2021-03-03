#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69;
int n;
vector<ll>possible;
void fun(ll *a,int l,int r,ll *pref){
	if(l>r || l<0 || r>n)
		return;
	possible.push_back(pref[r+1]-pref[l]);
	if(a[r]==a[l])
		return;
	int mid = (a[l] + a[r])/2;
	int ind = upper_bound(a,a+n,mid)-a;
	fun(a,l,ind-1,pref);
	fun(a,ind,r,pref);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {	
    	int q;
        cin>>n>>q;
        ll a[n];
        ll pref[n+1];
        pref[0] = 0;
        for (int i = 0; i < n; ++i)
        	cin>>a[i];
        sort(a,a+n);
        for (int i = 0; i < n; ++i)
        	pref[i+1] = pref[i] + a[i];
        fun(a,0,n-1,pref);
        sort(possible.begin(),possible.end());
        //for (auto i : possible)
        //	cout<<i<<' ';
        //cout<<endl;
        while(q--){
        	ll s;
        	cin>>s;
        	auto it = lower_bound(possible.begin(),possible.end(),s);
        	if(it!=possible.end() && *it==s)
        		cout<<"Yes\n";
        	else
        		cout<<"No\n";
        }
        possible.clear();
    }    
   	return 0;
}