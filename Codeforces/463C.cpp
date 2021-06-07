#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e3 + 1;
ll n, a[nax][nax], LU[nax][nax], RU[nax][nax], LD[nax][nax], RD[nax][nax];
struct val{
    ll x, y, value;
};
bool cmp(val &a, val &b){
    return a.value > b.value;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    val v1 = {0,0,0}, v2;
    v2 = {0,1,0};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin>>a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            LU[i][j] = a[i][j];
            if(i && j)
                LU[i][j]+=LU[i-1][j-1];
        }
    for (int i = n-1; i >= 0; --i)
        for (int j = n-1; j >= 0; --j){
            RD[i][j] = a[i][j];
            if(i+1<n && j+1<n)
                RD[i][j]+=RD[i+1][j+1];
        }
    for (int i = 0; i < n; ++i)
        for (int j = n-1; j >= 0; --j){
            RU[i][j] = a[i][j];
            if(i && j+1<n)
                RU[i][j]+=RU[i-1][j+1];
        }
    for (int i = n-1; i >= 0; --i)
        for (int j = 0; j < n; ++j){
            LD[i][j] = a[i][j];
            if(i+1<n && j)
                LD[i][j]+=LD[i+1][j-1];
            ll val = LU[i][j] + RU[i][j] + LD[i][j] + RD[i][j] - 3*a[i][j];
            // cout<<i<<' '<<j<<' '<<val<<endl;
            if((i+j)%2){
                if(v1.value<val){
                    v1 = {i, j,val};
                }
            }
            else{
                if(v2.value<val){
                    v2 = {i, j,val};
                }
            }
        }
    // cout<<v1.value<<' '<<v2.value<<endl;
    cout<<v1.value+v2.value<<'\n';
    cout<<v1.x+1<<' '<<v1.y+1<<' '<<v2.x+1<<' '<<v2.y+1<<'\n';
    return 0;
}