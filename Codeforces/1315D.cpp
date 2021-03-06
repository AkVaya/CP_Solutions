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
const ll M =1e9+7;
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n;
	cin>>n;
	vector<pii> a(n);
	map<ll,ll> m;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first;
		m[a[i].first]++;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].second;
	}
	sort(a.begin(), a.end());
	//for(auto i : a)
	//	cout<<i.first<<' '<<i.second<<endl;
	multiset<ll>s;
	ll sum=a[0].second,ans=0,i=1,val=a[0].first;
	s.insert(a[0].second);
	while(i<n){
		if(val==a[i].first){
			s.insert(a[i].second);
			sum+=a[i].second;
			i++;
		}
		else {
			if(s.empty()){
				val = a[i].first;
				continue;
			}
			auto it = s.end();
			--it;
			sum-=*it;
			s.erase(it);
			ans+=sum;
			val++;
		}
	}
	while(s.size()){
		auto it=s.end();
		--it;
		sum-=*it;
		ans+=sum;
		s.erase(it);
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