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
    ll n,k,x,y;
    vector<ll> both,fi,se;
    cin>>n>>k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i]>>x>>y;
        if(x&&y)
            both.eb(a[i]);
        else if(x)
            fi.eb(a[i]);
        else if(y)
            se.eb(a[i]);
    }
    ll ans=0;
    sort(both.begin(), both.end());
    sort(fi.begin(), fi.end());
    sort(se.begin(), se.end());
    ll val1=0,val2=0;
    vector<ll> :: iterator it1=both.begin(),it2=fi.begin(),it3=se.begin();
    for (int i = 0; i < k; ++i)
    {
        if((it1==both.end() && it2!=fi.end() && it3!=se.end()) || (it2!=fi.end() && it3!=se.end() && *it1>(*it3+*it2))){
            ans+=*it3+*it2;
            it3++;
            it2++;
            val1++;
            val2++;
        }
        else if(it1!=both.end()){
            ans+=*it1;
            it1++;
            val1++;
            val2++;
        }
        else
            break;
    }
    //cout<<val1<<" "<<val2<<endl;
    if(val1>=k && val2>=k)
        cout<<ans<<endl;
    else
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