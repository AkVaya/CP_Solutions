#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
struct items{
    ll seg, pref, suff, sum;
};
ll a[nax]; 
vector<items> tree(4*nax);
items merge(items &a, items &b){
    return {
        max(a.seg, max(b.seg, a.suff + b.pref))
        , max(a.pref, a.sum + b.pref)
        , max(b.suff, a.suff + b.sum)
        , a.sum + b.sum
    };
}
items single(ll val){
    return {
        max(0LL, val)
        , max(0LL, val)
        , max(0LL, val)
        , val
    };
}
void build(int curr, int L, int R){
    if(L==R-1){
        tree[curr] = single(a[L]);
        return;
    }
    int mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    int l = 2*curr, r = 2*curr + 1;
    tree[curr] = merge(tree[l], tree[r]);
}
items query(int curr, int qL, int qR, int L, int R){
    if(qL>=R || qR<=L)
        return {0, 0, 0, 0};
    if(qR>=R && qL<=L)
        return tree[curr];
    int mid = (L+R)/2;
    return merge(tree[2*curr], tree[2*curr+1]);
}
void update(int ind, ll val, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = single(val);
        a[ind] = val;
        return;
    }
    int mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    tree[curr] = merge(tree[2*curr], tree[2*curr+1]);
}
int main(){
    int n,q;
    cin>>n>>q;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }     
    build(1,1,n+1);
    cout<<tree[1].seg<<'\n';
    while(q--){
        int x, y;
        cin>>x>>y;
        update(x+1,y,1,n+1,1);
        cout<<tree[1].seg<<'\n';
    }
    return 0;
}