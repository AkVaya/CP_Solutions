#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,ans=0;
    cin>>n;
    ll a[n];
    ll prefsum[n+1]={0},is[n+1];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        prefsum[i+1]=prefsum[i]+a[i];
        is[a[i]]=false;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i+2; j <= n; ++j)
        {
            if((prefsum[j]-prefsum[i])<=n)
                is[prefsum[j]-prefsum[i]]=true;
            else
                break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        ans+=is[a[i]]==true;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}