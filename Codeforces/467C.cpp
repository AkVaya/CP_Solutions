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
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e8;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n],pref[n];
    vector<ll> all;
    vector<vector<ll> > dp(n+1,vector<ll>(k+1,0));
    ll sum=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        sum+=a[i];
        if(i>m-1)
            sum-=a[i-m];
        pref[i]=sum;
        //cout<<pref[i]<<" ";
    }
    //cout<<endl;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if(i>=m && j) 
                dp[i][j]=max(dp[i][j],pref[i-1]+dp[i-m][j-1]);
            if(i)
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[n][k]<<endl;
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