#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<math.h>
#include<string.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
#define inf 1000000000000000000
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,ans=1,temp;
    cin>>n;
    ll a[n],spd[200001];
    for (int i = 0; i <n; ++i)
    {
        cin>>a[i];
    }
    vector<bool> v(200000+1);
    vector<ll> x;
    fill(v.begin(),v.end(),true);
    x.eb(2);
    spd[1]=1;
    spd[2]=2;
    for (ll i = 3; i <200001; i++)
    {
        spd[i]=2;
        if(i%2)
            spd[i]=i;
    }
    //cout<<3;
    for (ll i = 3; i <200001; i+=2)
    {
        if (v[i]==true)
        {
            x.emplace_back(i);
            for (ll j = i*i; j <200001; j+=i)
            {
                v[j]=false;
                spd[j]=min(spd[j],i);
            }
        }
    }
    map<ll,ll> m,count;
    //cout<<2;
    for (int i = 0; i < n; ++i)
    {
        temp=a[i];
        while(temp!=1){
            ll fact=spd[temp];
            while(spd[temp]==fact){
                temp/=spd[temp];
            }
            count[fact]++;
        }
    }
    //cout<<"1";
    for (map<ll,ll>:: iterator it=count.begin();it!=count.end(); ++it)
    {
        if(it->second==n){
            ll min1=inf,min2=inf;
            for (int i = 0; i < n; ++i)
            {
                ll curr=0;
                while(a[i]%it->first==0){
                    a[i]/=it->first;
                    curr++;
                }
                if(min1>curr){
                    min2=min1;
                    min1=curr;
                }
                else if(min2>curr){
                    min2=curr;
                }
            }
            ans*=pow(it->first,min2);
        }
        else if(it->second==n-1){
            ll min1=inf;
            for (int i = 0; i < n; ++i)
            {
                ll curr=0;
                while(a[i]%it->first==0){
                    a[i]/=it->first;
                    curr++;
                }
                if(curr!=0)
                min1=min(min1,curr);
            }
            ans*=pow(it->first,min1);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}