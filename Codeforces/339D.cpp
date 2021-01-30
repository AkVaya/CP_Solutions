#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e6 + 69;
ll a[nax],tree[4*nax],lvl[4*nax];
void build(ll curr, ll L, ll R){
    if(L==R-1){
        lvl[curr] = 0;
        tree[curr] = a[L];
        return;
    }
    ll mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    lvl[curr] = lvl[2*curr] + 1;
    if(lvl[curr]%2)
        tree[curr] = tree[2*curr]|tree[2*curr+1];
    else
        tree[curr] = tree[2*curr]^tree[2*curr+1];
}
/*ll query(ll curr, ll qL, ll qR, ll L, ll R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L)
        return tree[curr];
    ll mid = (L+R)/2;
    ll res = query(2*curr,qL,qR,L,mid);
    res+=query(2*curr+1,qL,qR,mid,R);
    return res;
}*/
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
void update(ll ind, ll val, ll L, ll R, ll curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = val;
        a[ind] = val;
        return;
    }
    ll mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    if(lvl[curr]%2)
        tree[curr] = tree[2*curr]|tree[2*curr+1];
    else
        tree[curr] = tree[2*curr]^tree[2*curr+1];
}
int main(){
    int n,q;
    cin>>n>>q;
    n = binpow(2,n);
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }     
    build(1,1,n+1);
    while(q--){
        int x,y;
        cin>>x>>y;
        update(x,y,1,n+1,1);
        cout<<tree[1]<<'\n';
    }
}