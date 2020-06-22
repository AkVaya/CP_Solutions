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
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e3+1;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    vector<ll> cnt(26,0);
    char x;
    set<ll> s;
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        cnt[x-'a']++;
    }
    for (int i = 1; i <= k; ++i)
    {
        if(k%i==0)
            s.ins(i);
    }
    for(auto val : s){
        for (int i = 1; i < nax; ++i)
        {
            ll x=0;
            for (int j = 0; j < 26; ++j)
            {
                x+=cnt[j]/i;
            }
            //if(x){
            //    cout<<val<<" "<<x<<" "<<i<<endl;
            //}
            if(x>=val)
                ans=max(ans,val*i);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}