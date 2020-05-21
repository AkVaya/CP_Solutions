#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
void solve(){
    ll n;
    cin>>n;
    ll x[n+1],h[n+1];
    for (int i = 1; i <=n; ++i)
    {
        cin>>x[i]>>h[i];
    }
    vector<ll> dpn(n+1,0),dpr(n+1,0),dpl(n+1,0);
    dpn[1]=0;
    dpl[1]=1;
    if(n>=2 && x[1]+h[1]<x[2])
        dpr[1]++;
    for (int i = 2; i <=n; ++i)
    {
        dpn[i]=max3(dpn[i-1],dpr[i-1],dpl[i-1]);
        if(x[i]-h[i]>x[i-1]){
            if(x[i]-h[i]>x[i-1]+h[i-1]){
                dpl[i]=1+max3(dpn[i-1],dpr[i-1],dpl[i-1]);
            }
            else{
                dpl[i]=1+max(dpn[i-1],dpl[i-1]);
            }
        }
        if(i<n && x[i]+h[i]<x[i+1])
            dpr[i]=1+max3(dpn[i-1],dpr[i-1],dpl[i-1]);
        else
            dpr[i]=dpn[i];
       // cout<<dpn[i]<<" "<<dpl[i]<<" "<<dpr[i]<<endl;

    }
    if(n>1)
        dpr[n]++;
    cout<<max3(dpn[n],dpl[n],dpr[n])<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    return 0 ;
}