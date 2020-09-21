#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
//#define endl '\n'
#include<bits/stdc++.h>
#define pb emplace_back
#define ins insert 
#define Fir first
#define Sec second
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
using pii = pair<ll,ll>;
const ll M =1e9+7;
const ll nax=2e5+69;
ll dp[nax][2],n,a[nax];
ll solve(ll ind,ll flip){
	if(ind>=n)
		return 0;
	if(dp[ind][flip]!=M)
		return dp[ind][flip];
	if(ind==n-1){
		if(flip){
			return dp[ind][flip]=0;
		}
		return dp[ind][flip]=a[ind];
	}
	if(flip){
		dp[ind][flip] = min(solve(ind+1,1-flip),solve(ind+2,1-flip));
	}
	else{
		if(a[ind]){
			dp[ind][flip] = 1 + solve(ind+1,1-flip);
			if(ind<n-1 && a[ind+1])
				dp[ind][flip] = min(dp[ind][flip],2 + solve(ind+2,1-flip));
			else if(ind<n-1)
				dp[ind][flip] = min(dp[ind][flip],1 + solve(ind+2,1-flip));
		}
		else{
			dp[ind][flip] = solve(ind+1,1-flip);			
			if(ind<n-1 && a[ind+1])
				dp[ind][flip] = min(dp[ind][flip],1 + solve(ind+2,1-flip));
			else if(ind<n-1)
				dp[ind][flip] = min(dp[ind][flip],solve(ind+2,1-flip));
		}
	}
	return dp[ind][flip];

}
void solve(){
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		dp[i][0]=dp[i][1]=M;
	}
	solve(0,0);
	//for (int i = 0; i < n; ++i)
	//{
	//	cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
	//}
	cout<<dp[0][0]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
    //clock_t t3 = clock();
    while(t--){
    //    cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}
