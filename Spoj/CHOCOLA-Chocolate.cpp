#include<bits/stdc++.h> 
using namespace std; 
const int nax = 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        n--;
        m--;
        int a[n], b[m];
        for (int i = 0; i < n; ++i)
            cin>>a[i];
        for (int i = 0; i < m; ++i)
            cin>>b[i];
        ll res = 0, x = 1, y = 1;
        sort(a, a+n, greater<int>());
        sort(b, b+m, greater<int>());
        int i = 0, j = 0;
        while(i<n && j<m){
            if(a[i]>b[j]){
                res+=(y*a[i++]);
                x++;
            }
            else{
                res+=(x*b[j++]);
                y++;
            }
        }
        while(i<n)
            res+=(y*a[i++]);
        while(j<m)
            res+=(x*b[j++]);
        cout<<res<<'\n';
    }
    return 0;
}