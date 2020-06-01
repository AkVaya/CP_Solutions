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
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    ll ans=0;
    for (int i = 1; i <= 30; ++i)
    {
    	ll curr=0;
    	for (int j = 0; j < n; ++j)
    	{
    		if(a[j]<=i)
    			curr+=a[j];
    		else 
    			curr=0;
    		if(curr<0)
    			curr=0;
    		ans=max(curr-i,ans);
    		//if(ans==curr){
    		//	cout<<i<<" "<<ans<<endl;
    		//}
    	}
    }
    cout<<ans;
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