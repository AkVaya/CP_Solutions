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
    ll n,x;
    cin>>n>>x;
    ll a[n],w[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i]>>w[i];
    }
    ll dp[n+1][x+1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]<=j){
                dp[i][j]=max(w[i-1] + dp[i-1][j-a[i-1]],dp[i-1][j]);
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][x];
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}