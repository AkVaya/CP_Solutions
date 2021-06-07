#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int a[2*nax], n, tree[8*nax];
map<int, int> m;
int query(int curr, int qL, int qR, int L, int R){
    if(qL>=R || qR<=L)
        return 0;
    if(qR>=R && qL<=L)
        return tree[curr];
    int mid = (L+R)/2;
    int res = query(2*curr,qL,qR,L,mid);
    res += query(2*curr+1,qL,qR,mid,R);
    return res;
}
void update(int ind, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = 1;
        return;
    }
    int mid = (L+R)/2;
    update(ind,L,mid,2*curr);
    update(ind,mid,R,2*curr+1);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int main(){
    cin>>n;
    for (int i = 1; i <= 2*n; ++i)
        cin>>a[i];
    int res[n+1];
    for (int i = 1; i <= 2*n; ++i)
    {
        if(!m.count(a[i]))
            m[a[i]] = i;
        else{
            res[a[i]] = query(1, m[a[i]], i, 1, 2*n+1);
            update(m[a[i]], 1, 2*n+1, 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout<<res[i]<<' ';
    cout<<'\n';
    return 0;
}