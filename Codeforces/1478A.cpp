#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n], res = 1;
        map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        for(auto i : m)
            res = max(res, i.second);
        cout<<max(1, res)<<'\n';
    }
    return 0;
}