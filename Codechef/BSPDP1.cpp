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
#define Se second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e8;
const ll nax=2e5+1;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll mx=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if(i+2<=n)
            {
                dp[i+1][j]=a[i]+max(dp[max(0,i-1)][j-1],dp[i][j-1]);
                dp[i+2][j]=max(dp[i+2][j],a[i]+max(dp[i][j-1],dp[i+1][j-1]));
            }
           else
                dp[i+1][j]=a[i]+max(dp[i-1][j-1],dp[i][j-1]);
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            mx=max(dp[i][j],mx);
        }
        //cout<<endl;
    }
    cout<<mx<<endl;
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