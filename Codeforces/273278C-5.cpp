#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
struct items{
    ll mx;
};
ll a[nax]; 
vector<items> tree(4*nax);
items merge(items &a, items &b){
    return {max(a.mx, b.mx)};
}
items single(ll val){
    return {val};
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
int query(int curr, int k, int L, int R){
    if(L==R-1)
        return L;
    int mid = (L+R)/2;
    if(tree[2*curr].mx>=k){
        return query(2*curr, k, L, mid);
    }
    return query(2*curr+1, k, mid, R);
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
    while(q--){
        int x, y, z;
        cin>>x>>y;
        if(x==2){
            if(tree[1].mx>=y)
                cout<<query(1,y,1,n+1)-1<<'\n';// last index + 1 DUH!!
            else
                cout<<"-1\n";
        }
        else{
            cin>>z;
            update(y+1,z,1,n+1,1);
        }
    }
    return 0;
}