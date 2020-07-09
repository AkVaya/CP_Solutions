#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mpe make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
vector<bool>vis;
vector<set<ll> > v;
void solve(){
    ll n,x,y;
    cin>>n;
    v.resize(n+1);
    for (int i = 0; i < n-1; ++i)
    {
        cin>>x>>y;
        v[x].ins(y);
        v[y].ins(x);
    }
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    queue<ll> q;
    q.push(1);
    bool check=true;
    ll ind=1;
    while(q.size()){
        ll p=q.front();
        q.pop();
        ll temp=(p==1 ? v[p].size() : v[p].size()-1);
        //cout<<p<<" "<<temp<<endl;
        while(temp--){
            if(ind>=n || v[p].find(a[ind])==v[p].end()){
            //    cout<<p<<" "<<a[ind]<<endl;
                check=false;
                break;
            }
            else{
            //    cout<<a[ind]<<" ";
                if(v[a[ind]].size())
                    q.push(a[ind]);
            }
            ind++;
        }
        if(!check)
            break;
    }
    if(check && a[0]==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
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