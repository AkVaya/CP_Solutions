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
const ll M =1e8;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
void solve(){
    ll n,ans=0;
    cin>>n;
    ll a[n],ending;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    map<ll,ll> m;
    for (int i = 0; i < n; ++i)
    {
        m[a[i]]=1+m[a[i]-1];
        if(ans<m[a[i]]){
            ans=m[a[i]];
            ending=i;
        }
    }
    vector<ll> pos;
    pos.pb(ending);
    ll curr=a[ending]-1;
    for (int i = ending-1; i >= 0; --i)
    {
        if(a[i]==curr){
            pos.pb(i);
            curr--;
        }
    }
    reverse(pos.begin(), pos.end());
    cout<<ans<<endl;
    for(auto i : pos)
        cout<<i+1<<" ";
    cout<<endl;
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