#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define Fir first
#define Sec second
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
using pii = pair<ll,ll>;
const ll M =1e9+7;
const ll nax=1e7+1;
void solve(){
	ll a,b,g;
	cin>>a>>b;
	g=__gcd(a,b);
	set<ll> div;
	div.ins(g);
	div.ins(1);
	for (int i = 2; i*i <= g; ++i)
	{
		if(g%i==0){
			div.ins(i);
			div.ins(g/i);
		}
	}
	ll q,l,r;
	cin>>q;
	//for(auto i : div)
	//	cout<<i<<' ';
	while(q--){
		cin>>l>>r;
		auto it = lower_bound(div.begin(), div.end(),r);
		if(it==div.end() || *it>r)
			--it;
		if(*it<l)
			cout<<-1<<endl;
		else
			cout<<*it<<endl; 

	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}
