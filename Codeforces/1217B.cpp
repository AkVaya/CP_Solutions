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
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>; 
void solve(){
    ll n ,x;
    cin>>n>>x;
    vector<pii> v(n);
    vector<ll> diff,fi;
    bool check=true;
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i].first>>v[i].second;
        diff.eb(v[i].first-v[i].second);
        fi.eb(v[i].first);
        if(v[i].first-v[i].second>0 || v[i].first>=x)
            check=false;
    }
    if(check){
        cout<<-1<<endl;
        return;
    }
    ll cnt=0;
    sort(diff.begin(), diff.end(),greater<int>());
    sort(fi.begin(), fi.end(),greater<int>());
    ll val=fi[0];
    //cout<<val<<" ";
    x-=val;
    ll worst;
    if(x>0)
        worst=x/diff[0] + (x%diff[0]>0 ? 1 : 0);
    else
        worst=0;
    ///while(val>x-worst*diff[0]){
       // cout<<x-worst*diff[0]<<" ";
       // worst--;
    //}
    cout<<worst+1<<endl;
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