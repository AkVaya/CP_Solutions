#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
struct items{
    int val;
};
ll a[nax]; 
vector<items> tree(4*nax);
items merge(items &a, items &b){
    return {a.val+b.val};
}
items single(int val){
    return {val};
}
int query(int curr, int qL, int qR, int L, int R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L)
        return tree[curr].val;
    ll mid = (L+R)/2;
    ll res = query(2*curr,qL,qR,L,mid);
    res+=query(2*curr+1,qL,qR,mid,R);
    return res;
}
void update(int ind, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr].val = 1;
        return;
    }
    int mid = (L+R)/2;
    update(ind,L,mid,2*curr);
    update(ind,mid,R,2*curr+1);
    tree[curr] = merge(tree[2*curr], tree[2*curr+1]);
}
int main(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cout<<query(1, a[i] + 1, n+1, 1, n+1)<<' ';
        update(a[i], 1, n+1, 1);
    }
    cout<<'\n';
    return 0;
}