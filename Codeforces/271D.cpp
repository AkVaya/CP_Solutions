#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 2e5 + 69;
using ll = long long;
int main(){
	string s,t;
	cin>>s>>t;
	ll k,ans = 0;
	cin>>k;
	ll n = s.length();
    vector<ll> pref(n+1);
    for (int i = 0; i < n; i++){
        pref[i+1] = pref[i] + (t[s[i]-'a']=='0');
    }
	for (int l = 1; l <= n; ++l)
	{
		unordered_set<string> res;
        for (int i = 0; i <= n - l; i++) {
            if((pref[i+l]-pref[i])<=k){
            	string temp = s.substr(i,l);
            	if(res.find(temp)==res.end()){
            		res.insert(temp);
            		ans++;
            	}
          	}
        }
	}
	cout<<ans<<'\n';
	return 0;
}