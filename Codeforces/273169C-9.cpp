#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int a[nax],tree[4*nax][2];
void build(int curr, int L, int R){
    if(L==R-1){
        tree[curr][0] = a[L];
        tree[curr][1] = 1;
        return;
    }
    int mid = (L+R)/2;
    build(2*curr,L,mid);
    build(2*curr+1,mid,R);
    int left = tree[2*curr][0];
    int right = tree[2*curr+1][0];
    if(left<right){
        tree[curr][0] = tree[2*curr][0];
        tree[curr][1] = tree[2*curr][1];
    }
    else if(left>right){
        tree[curr][0] = tree[2*curr+1][0];
        tree[curr][1] = tree[2*curr+1][1];
    }
    else{
        tree[curr][0] = tree[2*curr][0];
        tree[curr][1] = tree[2*curr][1] + tree[2*curr+1][1];
    }
}
pair<int, int> query(int curr, int qL, int qR, int L, int R){
    if(qL>=R || qR<=L)
        return {INT_MAX, INT_MAX};
    if(qR>=R && qL<=L)
        return {tree[curr][0], tree[curr][1]};
    int mid = (L+R)/2;
    pair<int, int> left = query(2*curr,qL,qR,L,mid);
    pair<int, int> right = query(2*curr+1,qL,qR,mid,R);
    pair<int, int> res;
    if(left.first>right.first)
        res = right;
    else if(left.first<right.first)
        res = left;
    else{
        res.first= right.first;
        res.second = right.second + left.second;
    }
    return res;
}
void update(int ind, int val, int L, int R, int curr){
    if(ind<L || ind>=R)
        return;
    if(L==R-1){
        tree[curr][0] = val;
        tree[curr][1] = 1;
        a[ind] = val;
        return;
    }
    int mid = (L+R)/2;
    update(ind,val,L,mid,2*curr);
    update(ind,val,mid,R,2*curr+1);
    int left = tree[2*curr][0];
    int right = tree[2*curr+1][0];
    if(left<right){
        tree[curr][0] = left;
        tree[curr][1] = tree[2*curr][1];
    }
    else if(left>right){
        tree[curr][0] = right;
        tree[curr][1] = tree[2*curr+1][1];
    }
    else{
        tree[curr][0] = left;
        tree[curr][1] = tree[2*curr][1] + tree[2*curr+1][1];
    }
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
        int x,y,z;
        cin>>x>>y>>z;
        if(x==2){
            pair<int, int> ans = query(1,y+1,z+1,1,n+1);// last index + 1 DUH!!
            cout<<ans.first<<' '<<ans.second<<'\n';
        }
        else{
            update(y+1,z,1,n+1,1);
        }
    }
    return 0;
}