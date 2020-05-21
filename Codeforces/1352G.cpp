#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
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
    ll n;
    cin>>n;
    if(n>=4){
        deque<ll> dq;
        dq.pb(3);dq.pb(1);dq.pb(4);dq.pb(2);
        for (int i = 5; i <=n; ++i)
        {
            if(i%2)
                dq.push_front(i);
            else
                dq.push_back(i);
        }
        for (int i = 0; i < dq.size(); ++i)
        {
            cout<<dq[i]<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"-1"<<endl;

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