#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =998244353;
const ll nax=1;
ll n;
void solve(){
    cin>>n;
    ll ans=1,x;
    vector<ll> v[1000001];
    set<ll>s;
    for (int i = 1; i <= n; ++i)
    {
        cin>>x;
        v[x].eb(i);
        s.ins(x);
    }
    for(auto i:s){
        for (auto j:s)
        {
            x=v[i][0];
            ll count=1;
            while(1){
                auto it=upper_bound(v[j].begin(),v[j].end(),x);
                if(it==v[j].end())
                    break;
                count++;
                x=*it;
                auto it2=upper_bound(v[i].begin(),v[i].end(),x);
                if(it2==v[i].end())
                    break;
                x=*it2;
                count++;
            }
            ans=max(ans,count);
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}