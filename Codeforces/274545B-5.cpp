#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
struct items{
    int val;
};
ll a[nax], n, tree[4*nax];
void build(ll curr, ll L, ll R){
    if(L==R-1){
        tree[curr] = 1;
        return;
    }
    ll mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int query(int curr, int k, int L, int R){
    if(L==R-1){
        return L;
    }
    int mid = (L+R)/2;
    if(tree[2*curr+1]<=k)
        return query(2*curr,k - tree[2*curr+1],L,mid);
    return query(2*curr+1, k,mid,R);
}
void update(int ind, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = 0;
        return;
    }
    int mid = (L+R)/2;
    update(ind,L,mid,2*curr);
    update(ind,mid,R,2*curr+1);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    build(1,1,n+1);
    int res[n+1];
    for (int i = n; i >= 1; --i)
    {
        res[i] = query(1, a[i], 1, n+1);
        update(res[i], 1, n+1, 1);
    }
    for (int i = 1; i <= n; ++i)
        cout<<res[i]<<' ';
    cout<<'\n';
    return 0;
}