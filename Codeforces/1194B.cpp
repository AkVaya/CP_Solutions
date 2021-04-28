#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char a[n][m];
        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin>>a[i][j];
                if(a[i][j]=='*'){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                //cout<<i<<' '<<j<<' '<<r[i]<<' '<<c[j]<<endl;
                res = max(res,(r[i] + c[j] - (a[i][j]=='*' ? 1 : 0)));
            }
        }
        cout<< m + n - 1 -res<<'\n';
    }
    return 0;
}