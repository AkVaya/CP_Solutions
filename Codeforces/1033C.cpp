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
#define pf push_front
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e5+1;
ll n, dp[nax],a[nax];
bool fun(ll i){
    //cout<<i<<" ";
    if(dp[i]!=-1)
        return dp[i];
    bool ans=false;
    ll ind=i-a[i];
    while(ind>0){
        if(a[i]<a[ind])
            if(!fun(ind))
               ans=true;
        ind-=a[i];
    }
    ind=i+a[i];
    while(ind<=n){
        if(a[ind]>a[i])
            if(!fun(ind))
                ans=true;
        ind+=a[i];
    }
    if(ans)
        dp[i]=1;
    else
        dp[i]=0;
    return ans;
}
void solve(){
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
        dp[i]=-1;
    }
    bool temp;
    for (int i = 1; i <= n; ++i)
    {
        if(dp[i]==-1)
            temp=fun(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(dp[i])
            cout<<"A";
        else cout<<"B";
    }
    cout<<endl;
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