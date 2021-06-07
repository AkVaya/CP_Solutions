#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=2;
        ll a[n];
        bool check = false;
        map<ll, ll> m;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i]%2)
                check = true;
            m[a[i]]++;
        }
        vector<ll> v;
        for(auto i : m){
            if(i.second!=2)
                check = true;
            v.push_back(i.first);
        }
        ll tempn = n/2;
        if(v.size()!=tempn)
            check = true;
        if(check){
            cout<<"NO\n";
            continue;
        }
        ll val = 0;
        set<ll> s;
        for (int i = tempn-1; i >= 0; --i)
        {
            ll curr = v[i] - val;
            //cout<<v[i]<<' '<<val<<' '<<curr<<endl;
            if(!curr || curr%(2*tempn) || curr<=0){
                check = true;
                break;
            }
            curr/=(2*tempn);
            if(s.find(curr)!=s.end()){
                check = true;
                break;
            }
            s.insert(curr);
            val+=2*curr;
            tempn--;
        }
        if(check)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}