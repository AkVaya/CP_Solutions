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
using namespace std;
const ll M =1e9+7;
const ll nax=200001;
ll dp[nax][3],n;
string s;
ll fun(ll ind,ll remainder){
	if(ind==n){
		if(remainder==0)
			return 1;
		else return 0;
	}
	if(dp[ind][remainder]!=-1)
		return dp[ind][remainder];
	ll x=s[ind]-'0';
	ll temp=0;
	if(remainder==0)
		temp=max(temp,1+fun(ind+1,x%3));
	else
		temp=max3(temp,fun(ind+1,(x+remainder)%3),fun(ind+1,x%3));
	dp[ind][remainder]=temp;
	return temp;
}
void solve(){
    cin>>s;
    n=s.length();
    for (int i = 0; i < n; ++i)
    {
    	dp[i][0]=-1;
    	dp[i][1]=-1;
    	dp[i][2]=-1;
    }
    cout<<fun(1,(s[0]-'0')%3)<<endl;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}