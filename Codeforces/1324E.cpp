#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define pb push_back
#define Fir first
#define Sec second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=2e3+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll n,h,l,r,a[nax];
ll dp[nax][nax];
ll fun(ll ind,ll curr){
    if(ind>n)
        return 0;
    if(dp[ind][curr]!=-1) return dp[ind][curr];
    if(ind && curr>=l && curr <=r)
        dp[ind][curr]=1;
    else
        dp[ind][curr]=0;
    dp[ind][curr]+=max(fun(ind+1,(curr+a[ind])%h),fun(ind+1,(curr+a[ind]-1+h)%h));
    //cout<<ind<<" "<<curr<<" "<<dp[ind][curr]<<endl;
    return dp[ind][curr];
}
void solve(){
    cin>>n>>h>>l>>r;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,0)<<endl;
    //for (int i = 0; i < n; ++i)
    //{
    //    for (int j = 0; j < nax; ++j)
    //    {
    //        cout<<dp[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

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