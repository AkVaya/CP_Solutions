#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define M 1000000007
using namespace std;
void solve(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	bool dp[k+1];
	memset(dp,false,sizeof(dp));
	for (int i = 0; i <=k; ++i)
	{
		for (int j= 0; j<n; ++j)
		{
			if(a[j]<=i && !dp[i-a[j]])
				dp[i]=true;
		}
	}
	cout<<(dp[k]? "First" : "Second");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}
