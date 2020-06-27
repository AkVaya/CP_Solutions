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
    string s,t;
    cin>>s>>t;
    map<char,ll> m;
    vector<bool> check(s.size(),false);
    for (int i = 0; i < t.length(); ++i)
    {
        m[t[i]]++;
    }
    ll x=0,y=0;
    for (int i = 0; i < s.length() ; ++i)
    {
        if(m[s[i]]){
            x++;
            m[s[i]]--;
            check[i]=true;
        }
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if(check[i])
            continue;
        if((m[s[i]+32]>0 || m[s[i]-32]>0)){
            y++;
            m[s[i]+32]--;
            m[s[i]-32]--;
        }
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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