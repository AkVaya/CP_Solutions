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
const ll nax=1e3+1;
void solve(){
    ll n,k;
    cin>>n>>k;
    char a[n];
    string ans="";
    ll dp[n+1][k],prev[n+1][k];
    for (int i = 0; i < n; ++i)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < k; ++i)
        dp[0][i]=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if(dp[i][j]>=0){
                for (int l = 0; l < k; ++l)
                {
                    if(j!=l){
                        ll next=dp[i][j] +(a[i]-'A' != l);
                        if(dp[i+1][l]<0 || dp[i+1][l]>next){
                            dp[i+1][l]=next;
                            prev[i+1][l]=j;
                        }
                    }
                }
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    ll temp=inf,ind=0;
    for (int i = 0; i < k; ++i)
    {
        //cout<<dp[n][i]<<" ";
        if(dp[n][i]>=0 && dp[n][i]<temp){
            temp=dp[n][i];
            ind=i;
        }
    }
    //cout<<endl;
    for (int i = 0; i < n; ++i)
    {
        ans+='A'+ind;
        ind=prev[n-i][ind];
    }
    reverse(ans.begin(), ans.end());
    cout<<temp<<endl;
    cout<<ans;
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