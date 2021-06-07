#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
ll a[nax]; 
vector<ll> tree(4*nax);
ll query(int curr, int ind, int L, int R){
    if(R-1==L)
        return tree[curr];
    ll res = 0;
    int mid = (L+R)/2;
    if(ind < mid)
        res = query(2*curr, ind, L, mid);
    else
        res = query(2*curr+1, ind, mid, R);
    return max(res, tree[curr]);
}
void update(int curr, int qL, int qR, ll val, int L, int R){
    if(qR<=L || qL>=R)
        return;
    if(qR>=R && qL<=L){
        tree[curr] = max(val, tree[curr]);
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