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
void update(int ind, int val, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr] = val;
        return;
    }
    int mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}
int main(){
    cin>>n;
    for (int i = 1; i <= 2*n; ++i)
        cin>>a[i];
    vector<int> res(n+1, 0);
    for (int i = 1; i <= 2*n; ++i)
    {
        if(!m.count(a[i])){
            m[a[i]] = i;
            update(i, 1, 1, 2*n+1, 1);
        }
        else{
            res[a[i]] += query(1, m[a[i]]+1, i, 1, 2*n+1);
            //cout<<a[i]<<' '<<res[a[i]]<<endl;
            update(m[a[i]],0 , 1, 2*n+1, 1);
            m.erase(a[i]);
        }
    }
    for (int i = 2*n; i >= 1; --i)
    {
        if(!m.count(a[i])){
            m[a[i]] = i;
            update(i, 1, 1, 2*n+1, 1);
        }
        else{
            res[a[i]] += query(1, i, m[a[i]], 1, 2*n+1);
            update(m[a[i]],0 , 1, 2*n+1, 1);
            m.erase(a[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout<<res[i]<<' ';
    cout<<'\n';
    return 0;
}