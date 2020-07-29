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
const ll nax=100000000;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
	ll n,T;
	cin>>n>>T;
	multiset<ll> unused,used;
	ll a[n],sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		sum+=a[i];
		while(unused.size()){
			if(*(unused.begin())+sum<=T){
				used.ins(*unused.begin());
				sum+=*unused.begin();
				unused.erase(unused.begin());
			}
			else
				break;
		}
		while(sum>T){
			auto it=used.end();
			--it;
			unused.ins(*it);
			sum-=(*it);
			used.erase(it);
		}
		//cout<<"YAHA"<<endl;
		while(1){
			if(used.empty() || unused.empty())
				break;
			auto it1=unused.begin();
			auto it2=used.end();
			--it2;
			if(*it1<*it2){
				sum-=(*it2);
				sum+=(*it1);
				used.ins(*it1);
				unused.ins(*it2);
				unused.erase(it1);
				used.erase(it2);
			}
			else
				break;
		}
		//cout<<"YAHA"<<endl;
		while(!unused.empty()){
			if(sum+*unused.begin()<=T){
				sum+=(*unused.begin());
				used.ins(*unused.begin());
				unused.erase(unused.begin());
			}
			else
				break;
		}
		used.ins(a[i]);
		cout<<unused.size()<<" ";
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