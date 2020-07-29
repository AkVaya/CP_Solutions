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
#include<unordered_set>
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
// find_by_order(k): returns an iterator to the kth largest element (0-base)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){ 
    ll n,height,width;
    cin>>n>>height>>width;
    vector<pair<pii,ll> > a(n);
    for(int i = 0; i < n; ++i){
        cin>>a[i].Fir.Fir>>a[i].Fir.Sec;
        a[i].Sec=i+1;
    }
    sort(a.begin(),a.end());
    vector<ll>dp(n,-1);
    vector<ll> prev(n,-1);
    for(int i = 0; i < n; ++i){
        ll mx=0,ind=-1;
        for(int j = 0; j < i; ++j){
            if(a[i].Fir.Fir>a[j].Fir.Fir && a[i].Fir.Sec>a[j].Fir.Sec && mx<dp[j]){
                mx=dp[j];
                ind=j;
            }
        }
        if(a[i].Fir.Fir>height && a[i].Fir.Sec>width){
            if(mx){
                prev[i]=ind;
                dp[i]=1+mx;
            }
            else{
                dp[i]=1;
                prev[i]=-1;
            }
        }
    //    cout<<prev[i]<<" ";
    }
    //cout<<endl;
    ll ans=0,ind=-1;
    for(int i = 0; i < n; ++i){
    //    cout<<dp[i]<<" ";
        if(ans<dp[i]){
            ans=dp[i];
            ind=i;
        }
    }
    //cout<<endl;
    //for(int i = 0; i < n; ++i)
    //    cout<<a[i].second<<" ";
    //cout<<endl;
    if(ans){
        cout<<ans<<endl;
        vector<ll> temp;
        while(ind!=-1){
            temp.pb(a[ind].Sec);
            ind=prev[ind];
        }
        ll x=temp.size();
        if(x<ans){
            for(int i = 0; i < n; ++i){
                if(a[i].Fir.Fir>height && a[i].Fir.Sec>width && a[temp[0]].Fir.Fir>a[i].Fir.Fir && a[temp[0]].Fir.Sec>a[i].Fir.Sec){
                    temp.pb(a[i].Sec);
                    break;
                }
            }
        }
        reverse(temp.begin(),temp.end());
        for(auto i : temp)
            cout<<i<<" ";
        cout<<endl;
    }
    else
        cout<<0<<endl;
    
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