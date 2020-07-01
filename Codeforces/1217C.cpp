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
    string s;
    cin>>s;
    ll ans=0,n=s.length();
    vector<ll> last(n,-1);
    last[0] = (s[0]=='1' ? 0 : -1);
    for (int i = 1; i < n; ++i)
    {
        if(s[i]=='1')
            last[i]=i;
        else
            last[i]=last[i-1];
    }
    for (int i = 0; i < s.length(); ++i)
    {
        ll curr=0;
        for (int j = i; j >= 0 && (i-j)<25 ; --j)
        {
            if(s[j]=='0')
                continue;
            curr+=(1<<(i-j));
            if(curr<=i-(j==0 ? -1 : last[j-1]))
                ans++;
        }
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