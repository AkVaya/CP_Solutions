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
const ll nax=4e2+69;
void solve(){
	ll a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	ll ans= (a[0]/3+a[1]/3+a[2]/3);
	if(a[0] && a[1] && a[2]){
		ans= max((a[0]-1)/3+(a[1]-1)/3+(a[2]-1)/3+1,ans);
	}
	if(a[0]>1 && a[1]>1 && a[2]>1){
		ans= max((a[0]-2)/3+(a[1]-2)/3+(a[2]-2)/3+2,ans);
	}
	cout<<ans<<endl;
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
