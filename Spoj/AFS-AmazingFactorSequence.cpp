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
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
ll f[1000005]={0};
int main(){
    ll t;
    for (ll i = 2; i <=1000000; i++)
    {
        f[i]+=1;
        for (ll j = 2*i; j <= 1000000; j+=i)
        {
            f[j]+=i;
        }
    }
    ll b;
    ll a[1000001];
    a[0]=0;a[1]=0;
    for (int i = 2; i < 1000001; ++i)
    {
        a[i]=a[i-1]+f[i];
    }
    scanf("%lld",&t);
    while(t--){
        cin>>b;
        cout<<a[b]<<endl;        
    }
    return 0;
}