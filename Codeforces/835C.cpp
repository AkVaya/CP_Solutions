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
const ll M =1e18;
const ll nax=1e2+1;
ll dp[11][nax][nax];//count of number of stars with initial as i , and in between (1,1) && (j,k) 
ll n,q,c;
void solve(){
    cin>>n>>q>>c;
    ll x1,y1,z,x2,y2;
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        cin>>x1>>y1>>z;
        dp[z][x1][y1]++;
    }
    for (int i = 0; i <= c; ++i)
    {
        for (int j = 1; j < nax; ++j)
        {
            for (int k = 1; k < nax; ++k)
            {
                dp[i][j][k]+=dp[i][j-1][k]+dp[i][j][k-1]-dp[i][j-1][k-1];
            }
        }
    }

    while(q--){
        cin>>z>>x1>>y1>>x2>>y2;
        ll ans=0;
        for (int i = 0; i <= c; ++i)
        {
            ll temp1=(z+i)%(c+1);
            ll count=dp[i][x2][y2]-dp[i][x1-1][y2]-dp[i][x2][y1-1]+dp[i][x1-1][y1-1];
            ans+=count*temp1;
        }
        cout<<ans<<endl;
    }

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