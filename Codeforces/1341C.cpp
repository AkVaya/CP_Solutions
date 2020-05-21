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
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 100000000000000007
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,check=1;
    cin>>n;
    ll a[n];
    vector<pair<ll,ll> >v;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n-2; ++i)
    {
        if(a[i]<a[i+1] && a[i]+1==a[i+1])
            continue;
        else if(a[i]<a[i+1]){
            //cout<<a[i]<<" ";
            check=0;
            break;
        }
    }
    if(check)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}