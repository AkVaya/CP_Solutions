#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<bitset>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=5e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll avail[3],cost[3];
ll req[3]={0,0,0},money;
bool can(ll val){
	ll sum=0;
	for (int i = 0; i < 3; ++i)
	{
		ll mon = (req[i]*val>=avail[i] ? (req[i]*val-avail[i])*cost[i] : 0);
		sum+=mon;
	}
	//cout<<val<<':'<<sum<<endl;
	return sum<=money;
}
void solve(){
    string s;
    cin>>s;
    for (int i = 0; i < 3; ++i)
    {
    	cin>>avail[i];
    }
    for (int i = 0; i < 3; ++i)
    {
    	cin>>cost[i];
    }
    cin>>money;
    for (int i = 0; i < s.length(); ++i)
    {
    	if(s[i]=='B')
    		req[0]++;
    	else if(s[i]=='S')
    		req[1]++;
    	else
    		req[2]++;
    }
    ll l=0,r=1e13;
    while(l<=r){
    	ll mid=(l+r)/2;
    	//cout<<mid<<endl;
    	if(can(mid)){
    		l=mid+1;
    	}
    	else{
    		r=mid-1;
    	}
    }
    cout<<l-1<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}
