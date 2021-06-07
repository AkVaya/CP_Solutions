#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
ll tree[4*nax];
ll query(ll curr, ll qL, ll qR, ll L, ll R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L)
        return tree[curr];
    ll mid = (L+R)/2;
    ll res = query(2*curr,qL,qR,L,mid);
    res+=query(2*curr+1,qL,qR,mid,R);
    return res;
}
void update(ll ind, ll val, ll L, ll R, ll curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] += val;
        return;
    }
    ll mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    while(q--){
        int x,y,z,w;
        cin>>x>>y;
        y++;
        if(x==2){
            cout<<query(1,1,y+1,1,n+1)<<'\n';// last index + 1 DUH!!
        }
        else{
            cin>>z>>w;
            z++;
            update(y,w,1,n+1,1);
            update(z,-w,1,n+1,1);
        }
    }
    return 0;
}