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
#define pb push_back
#define Fir first
#define Sec second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,k;
    cin>>n>>k;
    bool check=false;
    ll a[n],curr=0,ans[n];
    map<ll,vector<ll> > m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        m[a[i]].pb(i);
        ans[i]=0;
    }
    sort(a,a+n);
    ll clr=1;
    for(auto i : m){
        if(i.second.size()>k){
            check=true;break;
        }
        for(auto j : i.second){
            ans[j]=clr;
            clr++;
            if(clr==k+1)
                clr=1;
        }
    }
    if(check)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for (int i = 0; i < n; ++i)
        {
            cout<<ans[i]<<" ";
        }
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