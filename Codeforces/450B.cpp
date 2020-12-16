#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int x,y,n;
    cin>>x>>y>>n;
    int ans[6] = {x, y, y-x, -x, -y, x-y};
    n--;
    n%=6;
    cout<<(ans[n]%M + M)%M;
    return 0;
}