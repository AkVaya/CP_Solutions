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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
void solve(){
    ll n,;
    cin>>n;
    ll a[n],h[n],dp[n+1];
    for (int i = 0; i < n; ++i)
    {
        cin>>h[i];
    }
    dp[0]=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        for (int j = 0; j <i; ++j)
        {
            dp[i]=max(dp[j],a[i]+h[i]);
        }
    }
    cout<<*maxelement(dp,dp+n+1);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    return 0 ;
}