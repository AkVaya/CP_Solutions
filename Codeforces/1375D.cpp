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
#include<bitset>
//#define endl '\n'
#define Fi first
#define Se second
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
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll mex(ll a[],ll n){
	bool check[n+1]={};
	for (int i = 0; i < n; ++i)
		check[a[i]]=true;
	for (int i = 0; i <= n; ++i)
	{
		if(!check[i])
			return i;
	}
	return 0;
}
void solve(){
	ll n;
	cin>>n;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//cout<<"YAHA"<<endl;
	vector<ll> ans;
	ll curr=0;
	while(curr<n)
	{
		ll temp=mex(a,n);
		if(temp<n){
			a[temp]=temp;
			ans.pb(temp);
		}
		else{
			a[curr]=temp;
			ans.pb(curr);
		}
		//cout<<curr<<endl;
		while(curr<n && a[curr]==curr)
			curr++;
	}
	cout<<ans.size()<<endl;
	for(auto i : ans)
		cout<<i+1<<" ";
	cout<<endl;
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
    cin>>t;
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