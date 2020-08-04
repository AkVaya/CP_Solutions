#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
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
const ll M =998244353;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pii> ans;
	ll cnt=0;
	bool check=false;
	for (int i = 2; i <= n; ++i)
	{
		ans.pb(mp(1,i));
		cnt++;
		if(cnt==m){
			check=true;
			break;
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if(check)
			break;
		for (int j = i+1; j <= n; ++j)
		{
			if(__gcd(i,j)==1){
				ans.pb(mp(i,j));
				cnt++;
				if(cnt==m){
					check=true;
					break;
				}
			}
		}
	}
	if(check && m>=n-1){
		cout<<"Possible"<<endl;
		for(auto i : ans)
			cout<<i.first<<' '<<i.second<<endl;
	}
	else
		cout<<"Impossible"<<endl;
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