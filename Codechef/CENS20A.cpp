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
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n,m;
	cin>>n>>m;
	char a[n][m];
	ll pref[n+1][m+1];
	memset(pref,0,sizeof(pref));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}
	ll t,p,q,r,s;
	cin>>t;
	//cout<<"YAHA"<<endl;
	while(t--){
		cin>>p>>q>>r>>s;
		--p;
		--q;
		--r;
		--s;
		pref[p][q]--;
		pref[r+1][s+1]--;
		pref[p][s+1]++;
		pref[r+1][q]++;
	}
	//cout<<"VAHA"<<endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			pref[i][j]+=pref[i-1][j];
		}
	}
	//cout<<"2"<<endl;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			pref[i][j]+=pref[i][j-1];
		}
	}
	//cout<<"VAHA"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(pref[i][j]%2){
				if(a[i][j]=='1')
					a[i][j]='0';
				else
					a[i][j]='1';
			}
			cout<<a[i][j];
		}
		cout<<endl;
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
