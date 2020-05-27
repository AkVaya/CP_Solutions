#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<unordered_map>
#include<string.h>
#include<ctime>
#include<cmath>
#define max3(a,b,c) max(c,max(a,b))
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
using ll = long long;
const ll M =1e9+7;
const ll nax=1e5+1;
vector<ll> fun(ll n){
    vector<ll> v;
    if(n%2==0){
        while(n%2==0)
            n/=2;
        v.eb(2);
    }
    for (int i = 3; i <=sqrt(n); i+=2)
    {
        if(n%i==0){
            while(n%i==0)
                n/=i;
            v.eb(i);
        }
        if(n==1)
            break;
    }
    if(n>1)
        v.eb(n);
    return v;
}
void solve(){
    ll n;
    cin>>n;
    ll a[n],dp[n],ans=0;
    map<ll,ll> m;
    ll all[nax];
    memset(all,0,sizeof(all));
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        dp[i]=1;
    }
    vector<ll> v;
    for (int i = 0; i < n; ++i)
    {
        v=fun(a[i]);
        ll temp=0;
        for (auto j : v)
        {
            temp=max(temp,all[j]);
        }
        all[a[i]]=temp+1;
        for (auto j : v)
        {
            all[j]=all[a[i]];
        //    cout<<j<<" "<<all[j]<<endl;
        }
        //cout<<all[a[i]]<<" ";
        dp[i]=all[a[i]];
    }
    cout<<*max_element(dp,dp+n)<<endl;
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}