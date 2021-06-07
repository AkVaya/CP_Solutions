#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e4 + 69;
using ll = long long;
const int M = 1e9 + 7;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        cout<<n-(*(m.begin())).second<<'\n';
    }
    return 0;
} 