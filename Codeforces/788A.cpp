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
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e5+1;
void solve(){
    ll n,t=-1;
    cin>>n;
    ll a[n],b[n-1],c[n-1];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n-1; ++i)
    {
        b[i]=( i%2 == 0 ? abs(a[i]-a[i+1]) : -abs(a[i]-a[i+1]) );
        c[i]=-b[i];
    }
    ll pref1[n],pref2[n];
    pref1[0]=b[0];
    pref2[0]=c[0];
    for (int i = 1; i < n-1; ++i)
    {
        pref1[i]=pref1[i-1]+b[i];
        pref2[i]=pref2[i-1]+c[i];
    }
    ll ans=-inf,mini=0;
    for (int i = 0; i < n-1; ++i)
    {
        ans=max(ans,pref1[i]-mini);
        mini=min(pref1[i],mini);
    }
    mini=0;
    for (int i = 0; i < n-1; ++i)
    {
        ans=max(ans,pref2[i]-mini);
        mini=min(pref2[i],mini);
    }
    cout<<ans<<endl;
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