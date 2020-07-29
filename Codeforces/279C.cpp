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
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
	ll n,m;
	cin>>n>>m;
	ll a[n],left[n],right[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		right[i]=left[i]=0;
	}
	left[0]=0;
	//cout<<left[0]<<" ";
	for (int i = 1; i < n; ++i)
	{
		if(a[i]<=a[i-1])
			left[i]=left[i-1];
		else
			left[i]=i;
	//	cout<<left[i]<<" ";
	}
	//cout<<endl;
	right[n-1]=n-1;
	for (int i = n-2; i >= 0; --i)
	{
		if(a[i]<=a[i+1])
			right[i]=right[i+1];
		else
			right[i]=i;
	}
	//for (int i = 0; i < n; ++i)
	//{
	//	cout<<right[i]<<" ";
	//}
	//cout<<endl;
	while(m--){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		if(left[y]<=right[x])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
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