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
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
bool can(ll a){
	while(a){
		if(a%3==2)
			return false;
		a/=3;
	}
	return true;
}
ll binpow(ll a,ll b,ll m=inf) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
void solve(){
	ll n,ans=0;
	cin>>n;
	if(can(n)){
		cout<<n<<endl;
	}
	else{
		string ternary="",temp="";
		while(n){
			ternary+=((n%3)+'0');
			n/=3;
		}
		//reverse(ternary.begin(), ternary.end());
		ll last=0;
		for (int i = ternary.size()-1; i >= 0; --i)
		{
			if(ternary[i]=='2'){
				last=i;
				break;
			}
		}
		//cout<<ternary<<endl;
		//cout<<last<<" ";
		bool check=false;
		for (int i = last+1; i < ternary.size(); ++i)
		{
			if(ternary[i]=='1' && check){
				ans+=binpow(3,i);
			}
			else if(!check && ternary[i]=='0'){
				ans+=binpow(3,i);
				check=true;
			}
		}
		if(!check){
			ans=(binpow(3,ternary.size()));
		}
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