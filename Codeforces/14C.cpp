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
const ll nax=3e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	map<ll,ll> x,y;
	ll a,b,c,d;
	map <pii,ll>m;
	bool check=true;
	for (int i = 0; i < 4; ++i)
	{
		cin>>a>>b>>c>>d;
		if((a!=c) && b==d){
			m[mp(a,b)]++;
			m[mp(c,d)]++;
		}
		else if(a==c && b!=d){
			m[mp(a,b)]--;
			m[mp(c,d)]--;
		}
		else
			check=false;
	}
	if(!check){
		cout<<"NO"<<endl;
		return;
	}
	for(auto i : m)
		if(i.second)
			check=false;
	if(check)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
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