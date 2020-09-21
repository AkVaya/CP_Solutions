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
const ll nax=5e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n;
double a[nax][2];
bool fun(double val){
	double l=-M,r= M;
	for (int i = 0; i < n; ++i)
	{
		l=max(l,(-(double)a[i][1])*val+(double)a[i][0]);
		r=min(r,((double)a[i][1])*val+(double)a[i][0]);
	}
	//cout<<val<<' '<<l<<' '<<r<<endl;
	return l<=r;
}
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i][0]>>a[i][1];
    }    
    double l = (double)-1e9, r =(double)1e9;
    for (int i = 0; i < 100; ++i)
    {
    	double mid = (l+r)/2;
    	if(fun(mid))
    		r = mid;
    	else 
    		l = mid;
    }
    cout<<fixed<<setprecision(15);
    cout<<l<<endl;
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
