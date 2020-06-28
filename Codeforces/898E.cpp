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
    ll n,x;
    cin>>n;
    ll a[n],sqr=0;
    vector<ll> diff,squares;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        x=sqrt(a[i]);
        if(a[i]==x*x){
            sqr++;
            squares.eb(a[i]);
        }
        else{
            diff.eb(min(((x+1)*(x+1) - a[i]),a[i]-x*x));
        }
    }
    ll ans=0;
    if(sqr>=n/2){
        sort(squares.begin(), squares.end(),greater<int>());
        ll temp=sqr-n/2;
        for (int i = 0; i < temp; ++i)
        {
            if(squares[i])
                ans++;
            else
                ans+=2;
        }
        cout<<ans<<endl;
        return;
    }
    else{
        sort(diff.begin(), diff.end());
        ll ind=0;
        while(sqr<n/2){
            sqr++;
            ans+=diff[ind++];
        }
        cout<<ans<<endl;
        return;
    }

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