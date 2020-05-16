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
#define M 998244353
using namespace std;
long long binpow(long long a, long long b, long long m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,ans=0,min=1;
    cin>>n;
    ll a[n];
    map<ll,ll> m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    ll num=binpow(2,n);
    if(m.find(1)==m.end()){
        ans=binpow(2,n);
    }
    else{   
        sort(a,a+n);
        ll num=0,temp,x=1;
        for (int i = 0; i < n; ++i)
        {
            if(a[i]==min)
                min++;
        }
        for (int i = 1; i <= min; ++i)
        {
            num+=m[i];
            temp=(i*binpow(2,n-num))%M;
            temp=((temp)*(x))%M;
            x=((x%M)*(binpow(2,m[i])-1))%M;
            ans=(ans%M+temp%M)%M;
        }
    }
    ans%=M;
    cout<<ans<<endl;
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