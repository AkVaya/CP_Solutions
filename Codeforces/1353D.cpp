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
struct cmp{ 
	bool operator()(const pii &a, const pii &b ){
		ll lena = a.second-a.first+1;
		ll lenb = b.second-b.first+1;
		if(lena!=lenb)
			return lena>lenb;
		return a.first<b.first;
	}
};
void solve(){
	ll n,cnt=0;
	cin>>n;
	set<pii,cmp> s;
	vector<ll> a(n);
	s.ins({0,n-1});
	while(cnt<n){
		auto it = s.begin();
		ll mid = (it->first + it->second)/2;
		//cout<<mid<<' ';
		a[mid]=cnt+1;
		if(mid>=it->first)
			s.ins({mid+1,it->second});
		if(mid<=it->second)
			s.ins({it->first,mid-1});	
		s.erase(it);
		cnt++;   
	}
	for(auto i : a)
		cout<<i<<' ';
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
