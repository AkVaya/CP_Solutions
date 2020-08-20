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
const ll nax=1e6+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;

void solve(){
    ll n;
    cin>>n;
    if(n<3){
    	cout<<n<<endl;
    }
    else if(n%2){
    	ll ans = (n*(n-1)*(n-2));
    	cout<<ans<<endl;
    }
    else{
    	ll val1 = (n-1)*(n-3)*(n-2);
    	ll val2 = ((n-1)*(n-3))/__gcd(n-1,n-3);
    	val2 = (val2*(n))/__gcd(n,val2);
    	ll ans = max3(n*(n-1)*(n-2)/2,val2,val1);
    	ll val3 = (n*(n-2))/2;
    	val3 = (n-3)*val3 / __gcd(val3,n-3);
    	ans=max(ans,val3);
    	cout<<ans<<endl;
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
