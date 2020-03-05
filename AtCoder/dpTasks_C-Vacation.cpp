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
    ll n,prev,x,m;
    cin>>n;
    ll a[n][3],dp[n][3]={0};
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for (int i = 0; i < 3; ++i)
    {
        dp[0][i]=a[0][i];
    }
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = a[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = a[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = a[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    cout<<max3(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
    return 0;
}