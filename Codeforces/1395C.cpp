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
const ll nax=3e6+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll calc[205][205];
void solve(){
	ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    bool used[n][m];
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    for (int i = 0; i < m; ++i)
    {
    	cin>>b[i];
    }
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		calc[i][j]=(a[i]&b[j]);
    		used[i][j]=false;
    	}
    }
    ll ans=0;
    for (int i = 8; i >= 0; --i)
    {
    	bool check=false;
    	for (int k = 0; k < n; ++k)
    	{
    		bool x=true;
    		for (int j = 0; j < m; ++j)
    		{
    			if(calc[k][j]&(1<<i) || used[k][j]){
    				continue;
    			}
    			x=false;
    			break;
    		}
    		if(x){
    			//cout<<k<<endl;
    			check=true;
       			break;
    		}
    		//cout<<i<<' '<<k<<' '<<endl;
    	}
    	if(check){
    		//cout<<i<<' ';
    		ans|=(1<<i);
    	}
    	else{
    		for (int k = 0; k < n; ++k)
    		{
    			for (int j = 0; j < m; ++j)
    			{
    				if((calc[k][j]&(1<<i))){
    					used[k][j]=true;
    				}
    			}
    			//cout<<i<<' '<<k<<' '<<endl;
    		}

    	}
    }
    cout<<ans<<endl;

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