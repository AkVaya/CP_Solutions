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
const ll M =1e9+7;
const ll nax=2001;
void add(ll &a,ll b){
    a+=b;
    if(a>M)
        a%=M;
}
void solve(){
    ll n,l,r,num[3]={0,0,0};
    cin>>n>>l>>r;
    ll dp[n+1][3];
    ll templ=l;
    while((r-templ)%3){
        num[templ%3]++;
        templ++;
    }
    memset(dp,0,sizeof(dp));
    ll temp1=(r-templ)/3;
    num[r%3]++;
    for (int i = 0; i <3; ++i)
    {
        num[(i)%3]+=temp1;
    }
    for (int i = 0; i < 3; ++i)
    {
        dp[1][i]=num[i];
        dp[0][i]=0;
        //cout<<dp[1][i]<<" ";
    }
    //cout<<endl;
    for (int i = 2; i <=n; ++i)
    {
        add(dp[i][0],dp[i-1][0]*num[0]+dp[i-1][1]*num[2]+dp[i-1][2]*num[1]);
        add(dp[i][1],dp[i-1][1]*num[0]+dp[i-1][2]*num[2]+dp[i-1][0]*num[1]);
        add(dp[i][2],dp[i-1][2]*num[0]+dp[i-1][0]*num[2]+dp[i-1][1]*num[1]);
        //cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
    cout<<dp[n][0]%M;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
   // cin>>t;
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