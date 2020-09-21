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
//#define endl '\n'
#include<bits/stdc++.h>
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
const ll nax=5e4+69;
ll n,h,w;
bool check(ll a){
	if(((a/h)*(a/w))>=n)
		return true;
	return false;

}
void solve(){
	cin>>w>>h>>n;
	ll l=1, r = 1;
	while(!check(r))
		r*=2;
	while(l<=r){
		ll mid = (l+r)/2 ;
		//cout<<mid<<endl;
		if(check(mid)){
			r=mid-1;
		}
		else
			l=mid+1;
	}
	cout<<l<<endl;

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
