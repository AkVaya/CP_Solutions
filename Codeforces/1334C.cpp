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
const ll nax=5e2+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n;
	cin>>n;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first>>a[i].second;
	}
	vector<ll> end(n,0),start(n,0),final(n,0);
	end[0] = (a[n-1].second>=a[0].first ? 0 : a[0].first - a[n-1].second);
	for (int i = 1; i < n-1; ++i)
	{
		if(a[i-1].second<a[i].first)
			end[i]+=a[i].first-a[i-1].second;
		end[i]+=end[i-1];
	}
	//for(auto i : end)
	//	cout<<i<<' ';
	//cout<<endl;
	for (int i = n-2; i >= 0; --i)
	{
		start[i]+=start[i+1];
		if(a[i].second<a[i+1].first)
			start[i]+=a[i+1].first-a[i].second;
	}
	//for(auto i : start)
	//	cout<<i<<' ';
	//cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		final[i] = a[i].first+start[i];
		if(i)
			final[i]+=end[i-1];
	//	cout<<final[i]<<' ';
	}
	//cout<<endl;
	cout<<*min_element(final.begin(), final.end())<<endl;
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
