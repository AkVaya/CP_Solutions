#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int r, n, m;
struct items{
    int a, b, c, d;
};
items a[nax]; 
vector<items> tree(4*nax);
items merge(items &fir, items &sec){
    return {(fir.a * sec.a + fir.b * sec.c)%r, 
        (fir.a*sec.b + fir.b*sec.d)%r,
        (fir.c*sec.a + fir.d*sec.c)%r,
        (fir.c*sec.b + fir.d*sec.d)%r};
}
items single(items &val){
    return val;
}
void build(int curr, int L, int R){
    if(L==R-1){
        tree[curr] = single(a[L]);
        return;
    }
    int mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);

    tree[curr] = merge(tree[2*curr], tree[2*curr+1]);
}
items query(int curr, int qL, int qR, int L, int R){
    if(qL>=R || qR<=L)
        return {1, 0, 0, 1};
    if(qR>=R && qL<=L)
        return tree[curr];
    int mid = (L+R)/2;
    items left = query(2*curr,qL,qR,L,mid);
    items right = query(2*curr+1,qL,qR,mid,R);
    items res = merge(left, right);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>r>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
    }
    build(1, 1, n+1);
    while(m--){
        int l, r;
        cin>>l>>r;
        items res = query(1, l, r+1, 1, n+1); 
        cout<<res.a<<' '<<res.b<<'\n'<<res.c<<' '<<res.d<<'\n'<<'\n';
    }
    return 0;
}