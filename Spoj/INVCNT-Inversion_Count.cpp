#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
ll a[nax],tree[4*nax];
ll query(ll curr, ll qL, ll qR, ll L, ll R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L)
        return tree[curr];
    ll mid = (L+R)/2;
    ll res = query(2*curr,qL,qR,L,mid);
    res += query(2*curr+1,qL,qR,mid,R);
    return res;
}
void update(ll ind, ll L, ll R, ll curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = 1;
        a[ind] = 1;
        return;
    }
    ll mid = (L+R)/2;
    update(ind,L,mid,2*curr);
    update(ind,mid,R,2*curr+1);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int b[n], original[n];
        for (int i = 0; i < n; ++i){
            cin>>b[i];
            original[i] = b[i];
        }
        for (int i = 0; i < 4*n; ++i)
        {
            tree[i] = 0;
        }
        // cout<<endl;
        sort(b, b+n);
        ll res = 0;
        for(int i = 0; i < n; ++i){
            auto it = lower_bound(b, b+n, original[i]);
            ll x = query(1, (it-b+1), n+1, 1, n+1);
            // cout<<i<<' '<<x<<' '<<it-b+1<<endl;
            res+=x;
            update((it-b)+1, 1, n+1, 1);
            // for (int i = 0; i < 4*n; ++i)
            // {
            //    cout<<tree[i]<<' ';
            // }
            // cout<<endl;
        }
        cout<<res<<'\n';
    }
    return 0;
}
/*
Using BIT

#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
struct FenwickTree
{
    vector<int> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int b[n], original[n];
        for (int i = 0; i < n; ++i){
            cin>>b[i];
            original[i] = b[i];
        }
        vector<int>v(n+1, 0);
        sort(b, b+n);
        FenwickTree bit = FenwickTree(v);   
        ll res = 0;
        for(int i = 0; i < n; ++i){
            auto it = lower_bound(b, b+n, original[i]);
            ll x = bit.sum((it-b+1), n);
            res+=x;
            bit.add((it-b)+1, 1);
        }
        cout<<res<<'\n';
    }
    return 0;
}

*/