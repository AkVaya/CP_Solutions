#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll binpow(ll a,ll b,ll m=1e18) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
ll sum(ll n){
    ll res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
int main(){
    long long a,b,c,val=1;
    cin>>a>>b>>c;
    set<int> res;
    while(val<81){
        long long temp = b*(binpow(val,a))+c;
        //cout<<temp<<endl;
        if(temp<1e9 && temp>0 && sum(temp)==val){
            res.insert(temp);
        }
        val++;
    }
    cout<<res.size()<<endl;
    for(auto i : res)
        cout<<i<<' ';
    cout<<'\n';
    return 0;
}