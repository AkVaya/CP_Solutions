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
const ll nax=69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
void solve(){
    string s;
    cin>>s;
    ll a,b;
    cin>>a>>b;
    vector<ll>rem1(s.length(),-1),rem2(s.length(),-1);
    rem1[0]=(s[0]-'0')%a;
    rem2[s.length()-1]=(s[s.length()-1]-'0')%b;
    for (int i = 1; i < s.length(); ++i)
    {
        rem1[i]=(rem1[i-1]*10+(s[i]-'0'))%a;
        //cout<<rem1[i]<<" "<<i<<endl;
    }
    if(rem1[s.length()-2]==0 && rem2[s.length()-1]==0 && s[s.length()-1]!='0'){
            cout<<"YES"<<endl;
            cout<<s.substr(0,s.length()-1)<<endl<<s.substr(s.length()-1,1)<<endl;
            return;
    }
    for (int i = s.length()-2; i >= 0; --i)
    {
        rem2[i]=(rem2[i+1]+(s[i]-'0')*binpow(10,s.length()-i-1,b))%b;

        //cout<<rem2[i]<<" "<<i<<endl;
        if(rem1[i-1]==0 && rem2[i]==0 && s[i]!='0'){
            cout<<"YES"<<endl;
            cout<<s.substr(0,i)<<endl<<s.substr(i,s.length()-i)<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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