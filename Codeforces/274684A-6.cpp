#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
ll a[nax],tree[4*nax];
void build(ll curr, ll L, ll R){
    if(L==R-1){
        tree[curr] = a[L];
        return;
    }
    ll mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    if(mid%2==L%2)
        tree[curr] = tree[2*curr] + tree[2*curr+1];
    else
        tree[curr] = tree[2*curr] - tree[2*curr+1];
}
ll query(ll curr, ll qL, ll qR, ll L, ll R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L){
        if(L%2==qL%2){
            return tree[curr];
        }
        return -tree[curr];
    }
    ll mid = (L+R)/2;
    ll res = query(2*curr,qL,qR,L,mid);
    res += query(2*curr+1,qL,qR,mid,R);
    return res;
}
void update(ll ind, ll val, ll L, ll R, ll curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = val;
        a[ind] = val;
        return;
    }
    ll mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    if(mid%2==L%2)
        tree[curr] = tree[2*curr] + tree[2*curr+1];
    else
        tree[curr] = tree[2*curr] - tree[2*curr+1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    }     
    cin>>q;
    build(1,1,n+1);
    /*for (int i = 1; i <= 20; ++i)
        cout<<tree[i]<<' ';
    cout<<endl;
    */
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            cout<<query(1,y,z+1,1,n+1)<<endl;// last index + 1 DUH!!
        }
        else{
            update(y,z,1,n+1,1);
        }
    }
    return 0;
}