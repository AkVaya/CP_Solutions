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
#define M 1000000000
using namespace std;
ll n;
ll dp[2001][2001] = {0};
ll fun(ll *a,ll start,ll end){
    ll days =(n+start-end);
    if(start>end || start==n || end==-1){
        return 0;
    }
    else if(dp[start][end]){
        return dp[start][end];
    }
    else{
        dp[start][end] = max(days*(*(a+start))+fun(a,start+1,end),days*(*(a+end))+fun(a,start,end-1));
      //  cout<<dp[start][end]<<endl;
        return dp[start][end];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cout<<fun(a,0,n-1);
    return 0 ;
}
