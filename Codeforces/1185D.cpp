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
	ll n;
	cin>>n;
	vector<pii> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a.begin(), a.end());
	set<ll> d;
	for (int i = 1; i < n; ++i)
	{
		d.ins(a[i].first-a[i-1].first);
	}
	if(d.size()==1){
		cout<<a[0].second<<endl;
		return;
	}
	else if(d.size()>3){
		cout<<-1<<endl;
		return;
	}
	else{
		//cout<<"HERE"<<endl;
		for(auto j : d){
			ll cnt[2]={0,0},ind1=0,ind2=0,curr=0;
			for (int i = 0; i < n; ++i)
			{
				if(a[0].first+curr*j!=a[i].first){
					cnt[0]++;
					ind1=a[i].second;
				}
				else
					curr++;
			}
			if(a[1].first-j!=a[0].first){
				cnt[1]=1;
				ind2=a[0].second;
			}
			curr=1;
			for (int i = 2; i < n; ++i)
			{
				if(a[1].first+curr*j!=a[i].first){
					cnt[1]++;
					ind2=a[i].second;
				}
				else
					curr++;
			}
			//cout<<j<<" "<<cnt[0]<<" "<<cnt[1]<<endl;
			if(cnt[0]==1 || cnt[1]==1){
			//	cout<<ind1<<" "<<ind2<<endl;
				if(cnt[0]==1 && cnt[1]==1){
					cout<<( ind1 ? ind1 : (ind2==ind1 ? ind2 : 1))<<endl;
					return;
				}
				else if(cnt[0]==1){
					cout<<a[1].second<<endl;
					return;
				}
				else{
					cout<<a[0].second<<endl;
					return;
				}
			}
		}
	}
	cout<<-1<<endl;
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