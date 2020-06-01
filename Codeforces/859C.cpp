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
const ll nax=51;
ll n ;
ll a[nax];
pair<ll,ll> dp[nax][2];
ll key=0;// 0 means Bob has the key
pair<ll,ll> fun(ll ind,ll key){
    if(dp[ind][key]!=mp(-1LL,-1LL))
        return dp[ind][key];
    if(ind==n)
        return {0,0};
    pair<ll,ll> p,q;//
    if(key==0){
        p=fun(ind+1,1);
        p.first+=a[ind];
        q=fun(ind+1,0);
        q.second+=a[ind];
        if(p.first>q.first)
            dp[ind][key]=p;
        else
            dp[ind][key]=q;
    }
    else{
        p=fun(ind+1,1);
        p.first+=a[ind];
        q=fun(ind+1,0);
        q.second+=a[ind];
        if(p.second>q.second)
            dp[ind][key]=p;
        else
            dp[ind][key]=q;
    }
    //cout<<ind<<" "<<key<<" "<<dp[ind][key].first<<" "<<dp[ind][key].second<<endl;
    return dp[ind][key];
}
void solve(){
    cin>>n;
    ll sum=0;
    for (int i = 0; i < nax; ++i)
    {
        dp[i][0]={-1,-1};
        dp[i][1]={-1,-1};
    }
    for (int i = 0; i < n; ++i)  // ans still has the token
    {
        cin>>a[i];
    }
    pair<ll,ll> p;
    p=fun(0,0);
    cout<<p.second<<" "<<p.first<<endl;
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