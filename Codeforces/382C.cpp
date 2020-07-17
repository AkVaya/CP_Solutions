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
const ll nax=1e7+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){ 
    ll n,d=M;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    sort(a,a+n);
    map<ll,ll> m;
    for (int i = 1; i < n; ++i)
    {
        m[a[i]-a[i-1]]++;
    }
    for(auto i : m){
        if(i.second>=n-2){
            d=i.first;
            break;
        }
    }
    if(d==M){
        cout<<0<<endl;
        return;
    }
    ll curr=-M;
    //cout<<d<<endl;
    for (int i = 1; i < n; ++i)
    {
        if(a[i]-a[i-1]!=d){
            if(curr==-M && (a[i]-a[i-1])==2*d)
                curr=a[i]-d;
            else{
                cout<<0<<endl;
                return;
            }
        }
    }
    if(curr==-M){
        if(n==2){
            if((a[1]-a[0])%2==0){
                set<ll> s;
                s.ins(a[0]-d);
                s.ins(a[1]+d);
                s.ins((a[0]+a[1])/2);
                cout<<s.size()<<endl;
                for(auto i : s)
                    cout<<i<<" ";
                cout<<endl;
            }
            else{
                set<ll> s;
                s.ins(a[0]-d);
                s.ins(a[1]+d);
                cout<<s.size()<<endl;
                for(auto i : s)
                    cout<<i<<" ";
                cout<<endl;
            }
        }
        else{
            set<ll> s;
            s.ins(a[0]-d);
            s.ins(a[n-1]+d);
            cout<<s.size()<<endl;
            for(auto i : s)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    else{
        cout<<1<<endl<<curr<<endl;
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