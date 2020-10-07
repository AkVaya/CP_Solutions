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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define endl '\n'
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,l,x,y;
ll a[nax];
bool c1,c2;
bool fun(ll val){
	return true;
}
void solve(){
	c1=c2=false;
    cin>>n>>l>>x>>y;
    set<ll> s;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    	s.ins(a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
    	if(s.find(a[i]+x)!=s.end())
    		c1=true;
    	if(s.find(a[i]+y)!=s.end())
    		c2=true;
    }
    if(c1||c2){
    	if(c1&&c2)
    		cout<<0<<endl;
    	else if(c1)
    		cout<<1<<endl<<y<<endl;
    	else
    		cout<<1<<endl<<x<<endl;
    	return;
    }
    for (int i = 0; i < n; ++i)
    {
    	if(s.find(a[i]+x+y)!=s.end()){
    		if(a[i]+x<=l)
    		{
    			cout<<1<<endl;
    			cout<<a[i]+x<<endl;
    			return;
    		}
    		if(a[i]+y<=l){
    			cout<<1<<endl;
    			cout<<a[i]+y<<endl;
    			return;
    		}
    	}
    	else if(s.find(a[i]-x+y)!=s.end()){
    		if(a[i]-x>=0)
    		{
    			cout<<1<<endl;
    			cout<<a[i]-x<<endl;
    			return;
    		}
    		if(a[i]+y<=l){
    			cout<<1<<endl;
    			cout<<a[i]+y<<endl;
    			return;
    		}
    	}
    	else if(s.find(a[i]+x-y)!=s.end()){
    		if(a[i]+x<=l)
    		{
    			cout<<1<<endl;
    			cout<<a[i]+x<<endl;
    			return;
    		}
    		if(a[i]-y>=0){
    			cout<<1<<endl;
    			cout<<a[i]-y<<endl;
    			return;
    		}
    	}
    }
    cout<<2<<endl;
    cout<<x<<' '<<y<<endl;
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