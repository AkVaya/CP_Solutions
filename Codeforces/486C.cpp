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
const ll nax=2e5+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll diff(char a,char b){
    ll x=abs(a-b);
    ll y=26-x;
    return min(x,y);
}
void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=0,check=0;
    vector<pii> v;
    for (int i = 0; i < n/2; ++i)
    {
        if(s[i]!=s[n-i-1])
            v.eb(mp(diff(s[i],s[n-i-1]),i));
    }
    if(v.size()==0){
        cout<<0<<endl;
        return;
    }
    if(k>n/2)
        k=n-k+1;
    k--;
    ans+=(v[v.size()-1].Sec-v[0].Sec);
    for (int i = 0; i < v.size(); ++i)
    {
        ans+=v[i].first;
    }
    ans+=min(abs(k-v[0].Sec),abs(v[v.size()-1].Sec-k));
    cout<<ans<<endl;
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