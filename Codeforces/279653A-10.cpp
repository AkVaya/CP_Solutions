#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
ll a[nax];
struct items{
    ll min, val;

};
vector<items> tree(4*nax);
items query(int curr, int qL, int qR, int L, int R){
    if(qR<=L || qL>=R)
        return {LLONG_MAX, 0};
    if(qR>=R && qL<=L){
        return tree[curr];
    }
    int mid = (L+R)/2;
    items fir = query(2*curr, qL, qR, L, mid);
    items sec = query(2*curr+1, qL, qR, mid, R);
    return {min(fir.min, sec.min) + tree[curr].val, tree[curr].val};
}
void update(int curr, int qL, int qR, ll val, int L, int R){
    if(qR<=L || qL>=R)
        return;
    if(qR>=R && qL<=L){
        tree[curr].val += val;
        tree[curr].min += val;
        return;
    }
    int mid = (L+R)/2;
    update(2*curr, qL, qR, val, L, mid);
    update(2*curr+1, qL, qR, val, mid, R);
    tree[curr].min = min(tree[2*curr].min, tree[2*curr+1].min) + tree[curr].val;
}
int main(){
    int n,q;
    cin>>n>>q;
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
            cout<<query(1, l, r, 1, n+1).min<<'\n';
        }
    }
    return 0;
}