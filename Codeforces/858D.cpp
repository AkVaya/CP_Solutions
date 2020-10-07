#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<unordered_map>
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
const ll nax=5e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
    int n;
    cin>>n;
    string s[n];
    map<string,ll> cnt;
    for (int i = 0; i < n; ++i)
    {
    	cin>>s[i];
    	set<string> se;
    	for (int j = 1; j <= 9; ++j)
    	{
    		for (int k = 0; k <= 9-j; ++k)
    		{
    			se.ins(s[i].substr(k,j));
    		}
    	}
    	for(auto i : se)
    		cnt[i]++;
    }
    for (int i = 0; i < n; ++i)
    {
    	bool check = false;
    	for (int j = 1; j <= 9; ++j)
    	{
    		for (int k = 0; k <= 9-j; ++k)
    		{
    			string temp = s[i].substr(k,j);
    			if(cnt[temp]==1){
    				cout<<temp<<endl;
    				check=true;
    				break;
    			}
    		}
    		if(check)
    			break;
    	}
    }
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