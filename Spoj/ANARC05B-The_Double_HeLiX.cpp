#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e4 + 69;
using ll = long long;
int n1, n2;
ll a[nax], b[nax];
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n1){
    	if(!n1)
    		break;
    	ll pref1[n1];
    	for (int i = 0; i < n1; ++i)
    	{
    		cin>>a[i];
    		if(i)
    			pref1[i] = a[i] + pref1[i-1];
    		else
    			pref1[i] = a[i];
    	} 	
    	cin>>n2;
    	ll pref2[n2];
    	vector<int> same;
    	for (int i = 0; i < n2; ++i)
    	{
    		cin>>b[i];
    		auto it = lower_bound(a, a+n1, b[i]);
    		if(it!=a+n1 && *it==b[i])
    			same.push_back(b[i]);
    		if(i)
    			pref2[i] = b[i] + pref2[i-1];
    		else
    			pref2[i] = b[i];
    	}
    	ll ans = 0, last = INT_MAX;
    	for(auto i : same){
    		int fir = lower_bound(a, a+n1, i) - a;
    		ll val1 = pref1[fir];
    		if(last!=INT_MAX)
    			val1 -= pref1[lower_bound(a, a+n1, last) - a];
    		int sec = lower_bound(b, b+n2, i) - b;
    		ll val2 = pref2[sec];
    		if(last!=INT_MAX)
    			val2 -= pref2[lower_bound(b, b+n2, last) - b];
    		ans+=max(val1, val2);
    		//cout<<i<<' '<<val1<<' '<<val2<<endl;
    		last = i;
    	}
    	if(last!=INT_MAX)
    		ans+= max(pref1[n1-1] - pref1[lower_bound(a, a+n1, last) - a], pref2[n2-1] - pref2[lower_bound(b, b+n2, last) - b]);
    	if(ans==0)
    		ans = INT_MIN;
    	ans = max(ans, pref1[n1-1]);
    	ans = max(ans, pref2[n2-1]);
    	cout<<ans<<'\n';
    }
	return 0;
}