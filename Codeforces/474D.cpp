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
ll dp[nax];// if we have length of i
void solve(){
    ll t,k;
    cin>>t>>k;
    dp[0]=1;
    ll sum[nax];
    sum[0]=1;
    for (int i = 1; i < nax; ++i)
    {
        if(i<k)
            dp[i]=1;
        else
            dp[i]=(dp[i-k]%M+dp[i-1]%M)%M;
       // if(i<10)
         //   cout<<dp[i]<<" ";
        sum[i]=(sum[i-1]%M+dp[i]%M)%M;
    }
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<((sum[b]-sum[a-1])%M+M)%M<<endl;
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}