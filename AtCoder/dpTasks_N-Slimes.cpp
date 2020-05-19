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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 1e9+7
#define inf 1000000000000000000
using namespace std;
ll sum(ll*a, ll ind1,ll ind2){
    ll ans=0;
    if(ind1>ind2){
        ll temp=ind2;
        ind2=ind1;
        ind1=temp;
    }
    for (int i = ind1; i <= ind2; ++i)
    {
        ans+=a[i];
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll dp[n][n];// min val when starting from i and ending on j
    for (int i = n-1; i >=0; --i)
    {
        for (int j = i; j <n; ++j)
        {
            dp[i][j]=inf;
            if(i==j){
                dp[i][j]=0;
            }
            else{
                ll s=sum(a,i,j);
                for (int k = i; k<=j; ++k)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s);
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    return 0 ;
}