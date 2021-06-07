#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
ll a[nax];
struct items{
    ll sum, val;
};
vector<items> tree(4*nax);
ll query(ll curr, ll qL, ll qR, ll L, ll R){
    if(qR<=L || qL>=R)
        return 0;
    if(qR>=R && qL<=L){
        return tree[curr].sum;
    }
    ll mid = (L+R)/2;
    ll fir = query(2*curr, qL, qR, L, mid);
    ll sec = query(2*curr+1, qL, qR, mid, R);
    ll res = fir + sec + tree[curr].val * (min(R, qR) - max(L, qL)) ;
    return res;
}
void update(ll curr, ll qL, ll qR, ll val, ll L, ll R){
    if(qR<=L || qL>=R)
        return;
    if(qR>=R && qL<=L){
        tree[curr].sum += (R-L) * val;
        tree[curr].val += val;
        return;
    }
    ll mid = (L+R)/2;
    update(2*curr, qL, qR, val, L, mid);
    update(2*curr+1, qL, qR, val, mid, R);
    tree[curr].sum = (tree[2*curr].sum + tree[2*curr+1].sum + tree[curr].val * (R - L));
}
int main(){
    ll n,q;
    cin>>n>>q;
    while(q--){
        ll x, l, r, val;
        cin>>x>>l>>r;
        l++;
        r++;
        if(x==1){
            cin>>val;
            update(1, l, r, val, 1, n+1);// last index + 1 DUH!!
        }
        else{
            cout<<query(1, l, r, 1, n+1)<<'\n';
        }
    }
    // for (ll i = 0; i < 2*n; ++i)
    // {
    //     cout<<tree[i].val<<' ';
    // }
    return 0;
}