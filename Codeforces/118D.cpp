#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
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
const ll nax=1e2+5;
const ll inf=1e18;
using pii = pair<ll,ll>; 
ll dp[nax][nax][2],n1,n2,k1,k2;
void add(ll &a,ll b){
    a+=b;
    if(a>=M)
        a%=M;
}
ll fun(ll x, ll y, ll last){
    if(dp[x][y][last]!=-1)
        return dp[x][y][last];
    ll ans=0;
    if(!last)
        for (int i = 1; i <= k1 ; ++i)
        {
            if(x-i>=0)
                add(ans,fun(x-i,y,1-last));
        }
    else
        for (int i = 1; i <= k2; ++i)
        {
            if(y-i>=0)
                add(ans,fun(x,y-i,1-last));
        }
    dp[x][y][last]=ans;
    return ans;
}
void solve(){
    cin>>n1>>n2>>k1>>k2;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=dp[0][0][1]=1;// 0 for footmen and 1 for horsemen
    cout<<((fun(n1,n2,0)+fun(n1,n2,1))%M)<<endl;

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