#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x=0,temp;
    cin>>n;
    ll a[n];
    set<ll> s;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        temp=(a[i]+i)%n;
        if(temp<0)
            temp+=n;
        if(!x && s.find(temp)==s.end())
            s.insert(temp);
        else
            x=1;
    }
    if(x)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,q,x;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}