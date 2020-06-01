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
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll dp[n+1][2];
    dp[0][0]=b;
    dp[0][1]=inf;
    for (int i = 1; i <=n; ++i)
    {
    	if(s[i-1]=='0'){
    		dp[i][0]=min(a+dp[i-1][0]+b,dp[i-1][1]+2*a+b);
    		dp[i][1]=min(2*a+dp[i-1][0]+2*b,dp[i-1][1]+a+2*b);
    	}
    	else{
    		dp[i][0]=inf/2;
    		dp[i][1]=dp[i-1][1]+a+2*b;
    	}
    }
    cout<<dp[n][0]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
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