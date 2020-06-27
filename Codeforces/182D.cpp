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
    ll ans=0;
    ll ln = min(s.length(),t.length());
    set<ll>se; 
    for (int i = 1; i <= ln; ++i)
    {
        if(ln%i==0)
            se.ins(i);
    }
    for (auto j : se)
    {
        if(t.length()%j || s.length()%j)
            continue;
        bool check=true;
        string temp;
        for (int i = 0; i < j; ++i)
        {
            temp+=s[i];
        }
        for (int i = j; i < s.length(); i+=j)
        {
            if(temp!=s.substr(i,j)){
                check=false;
                break;
            }
        }
        for (int i = 0; i < t.length(); i+=j)
        {
            if(temp!=t.substr(i,j)){
                check=false;
                break;
            }
        }
        if(check)
            ans++;
    }
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