#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define ins insert 
#define mp make_pair
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000000000000000
using namespace std;
int main(){
    //double start_time = clock();
    ll n,k,q;
    cin>>n>>k;
    ll a[n],dp[n]={0};
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        dp[i]=M;
    }
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for (ll i = 2; i < n; ++i)
        {
            q=0;
            for (ll j = i-1;j>=0 && j>=i-k; --j)
            {
                dp[i] = min(dp[i],dp[j]+abs(a[j]-a[i]));
            }
        }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    cout<<dp[n-1];
    return 0;
}