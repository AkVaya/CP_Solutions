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
const ll M =1e8;
const ll nax=1e2+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector<ll> cnt(n+1,0);
    cnt[0]=0;
    for (int i = 0; i < n; ++i)
    {
        if(s[i]=='0')
            cnt[i+1]=1+cnt[i];
        else
            cnt[i+1]=cnt[i]-1;
    }
    ll ans=0,check=0;
    for (int i = 0; i < n; ++i)
    {
        if(cnt[n] && (x-cnt[i])%cnt[n]==0 && (x-cnt[i])*cnt[n]>=0)
            ans++;
        else if(!cnt[n] && cnt[i]==x){
            check=1;
            break;
        }
    }
    if(!check)
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