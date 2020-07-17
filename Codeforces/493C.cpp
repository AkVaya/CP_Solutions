#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<bitset>
#include<vector>
#include<iomanip>
#include<queue>
#define endl '\n'
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
#define LB lower_bound
#define UB upper_bound
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=569;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
    ll n,val1=0,val2=0,diff=-M;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll m;
    cin>>m;
    ll b[m];
    for (int i = 0; i < m; ++i)
    {
        cin>>b[i];
    }
    sort(b,b+m);
    for (int i = 0; i < m; ++i)
    {
        ll ind=UB(a,a+n,b[i])-a;
        ll temp1=(n-ind)*3;
        ll temp2=0;
        //cout<<ind<<" ";
        if(ind>=i+1){
            temp1+=(ind)*3;
            temp2+=m*3;
        }
        else{
            temp1+=ind*2;
            temp2+=(i+1)*2+(m-i-1)*3;
        }
        if(temp1-temp2>diff){
            diff=temp1-temp2;
            val1=temp1;
            val2=temp2;
        }
    }
    cout<<val1<<":"<<val2<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    //clock_t t3 = clock();
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}