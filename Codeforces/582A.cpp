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
void solve(){
    ll n,x;
    cin>>n;
    set<ll>s;
    map<ll,ll> m;
    for (int i = 0; i < n*n; ++i)
    {
        cin>>x;
        m[x]++;
        s.ins(x);
    }
    vector<ll> ans;
    auto it = s.end();
    --it;
    ans.pb(*it);
    while(ans.size()<n){
        m[*it]--;
        if(m[*it]==0)
            s.erase(*it);
        for (int i = 0; i < ans.size()-1; ++i)
        {
            m[__gcd(ans[i],ans[ans.size()-1])]-=2;
            if(m[__gcd(ans[i],ans[ans.size()-1])]<=0)
                s.erase(__gcd(ans[i],ans[ans.size()-1]));
        }
        it=s.end();
        --it;
        ans.pb(*it);
        //for(auto i : s)
        //    cout<<i<<" ";
        //cout<<endl;
    }
    for(auto i : ans)
        cout<<i<<" ";
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