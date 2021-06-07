#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll FREE = LLONG_MAX;
ll a[nax]; 
vector<ll> tree(4*nax);
ll assign(ll a, ll b){
    if(b==FREE)
        return a;
    return b;
}
void propogate(int curr, int L, int R){
    if(L==R-1)
        return;
    tree[2*curr] = assign(tree[2*curr], tree[curr]);
    tree[2*curr+1] = assign(tree[2*curr+1], tree[curr]);
    tree[curr] = FREE;
}
ll query(int curr, int ind, int L, int R){
    propogate(curr, L, R);
    if(R-1==L)
        return tree[curr];
    ll res ;
    int mid = (L+R)/2;
    if(ind < mid)
        res = query(2*curr, ind, L, mid);
    else
        res = query(2*curr+1, ind, mid, R);
    return res;
}
void update(int curr, int qL, int qR, ll val, int L, int R){
    propogate(curr, L, R);
    if(qR<=L || qL>=R)
        return;
    if(qR>=R && qL<=L){
        tree[curr] = assign(tree[curr], val);
        return;
    }
    int mid = (L+R)/2;
    update(2*curr, qL, qR, val, L, mid);
    update(2*curr+1, qL, qR, val, mid, R);
}
int main(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int x, l, r, val;
        cin>>x>>l;
        l++;
        if(x==1){
            cin>>r>>val;
            r++;
            update(1, l, r, val, 1, n+1);// last index + 1 DUH!!
        }
        else{
            cout<<query(1, l, 1, n+1)<<'\n';
        }
    }
    return 0;
}