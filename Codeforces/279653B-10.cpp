#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
ll a[nax];
struct items{
    ll mult, val;
};
vector<items> tree(4*nax);
void build(int curr, int L, int R){
    if(L==R-1){
        tree[curr].val = 1;
        tree[curr].mult = 1;
        return;
    }
    int mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    int l = 2*curr, r = 2*curr + 1;
    tree[curr].val = (tree[l].val + tree[r].val)%M;
    tree[curr].mult = 1;
}
items query(int curr, int qL, int qR, int L, int R){
    if(qR<=L || qL>=R)
        return {0, 0};
    if(qR>=R && qL<=L){
        return tree[curr];
    }
    int mid = (L+R)/2;
    items fir = query(2*curr, qL, qR, L, mid);
    items sec = query(2*curr+1, qL, qR, mid, R);
    items res;
    res.mult = tree[curr].mult;
    res.val = (((fir.val + sec.val)%M)*tree[curr].mult)%M;
    return res;
}
void update(int curr, int qL, int qR, ll val, int L, int R){
    if(qR<=L || qL>=R)
        return;
    if(qR>=R && qL<=L){
        tree[curr].val = (tree[curr].val * val)%M;
        tree[curr].mult = (tree[curr].mult * val)%M;
        return;
    }
    int mid = (L+R)/2;
    update(2*curr, qL, qR, val, L, mid);
    update(2*curr+1, qL, qR, val, mid, R);
    tree[curr].val = (((tree[2*curr].val+tree[2*curr+1].val)%M)*tree[curr].mult)%M;
}
int main(){
    int n,q;
    cin>>n>>q;
    build(1, 1, n+1);
    while(q--){
        int x, l, r, val;
        cin>>x>>l>>r;
        l++;
        r++;
        if(x==1){
            cin>>val;
            update(1, l, r, val, 1, n+1);// last index + 1 DUH!!
        }
        else{
            cout<<query(1, l, r, 1, n+1).val<<'\n';
        }
    }
    return 0;
}