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
#define mp make_pair
#define Fi first
#define Se second
#define ll long long
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
const ll M =1e9+7;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n;
    cin>>n;
    ll a[n],b[n],cnt=0,ans=0;
    map<ll,ll> fi,se;
    set<ll> s,s2;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        fi[a[i]]++;
        s.ins(a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>b[i];
        se[b[i]]++;
        s.ins(b[i]);
    }
    bool check=false;
    ll minVal=M;
    for(auto i : s){
        if((se[i]-fi[i])%2){
            check=true;
            break;
        }
        ll temp=abs(se[i]-fi[i]);
        cnt+=(temp)/2;
        if(temp)
            s2.ins(i);
        if(minVal==M)
            minVal=i;
    }
    if(check || cnt%2){
        cout<<-1<<endl;
        return ;
    }
    cnt/=2;
    for(auto i : s2){
        if(i>=2*minVal)
            break;
        ll val=min(cnt,(abs(se[i]-fi[i]))/2);
        ans+=(val*i);
        cnt-=val;
        if(cnt==0)
            break;
    }
    cnt*=2;
    //cout<<cnt<<" ";
    cout<<ans+cnt*minVal<<endl;

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