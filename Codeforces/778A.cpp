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
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll a[nax];
bool check(string s,string &t,ll m){
    for (int i = 0; i < m; ++i)
    {
        s[a[i]]='#';
    }
    ll ind=0;
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i]==t[ind])
            ind++;
        if(ind==t.length())
            return true;
    }
    return false;
}
void solve(){
    string s,t;
    cin>>s>>t;
    map<char,ll> m1,m2;
    for (int i = 0; i < s.length(); ++i)
    {
        m1[s[i]]++;
    }
    for (int i = 0; i < t.length(); ++i)
    {
        m2[t[i]]++;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        cin>>a[i];
        --a[i];
    }
    ll l=0,r=s.length()-1;
    //cout<<l<<" "<<r<<endl;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(s,t,mid))
            l=mid+1;
        else
            r=mid-1;
        //cout<<l<<" "<<r<<endl;
    }
    cout<<l-1<<endl;
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