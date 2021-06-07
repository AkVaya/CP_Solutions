#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e6 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n*=2;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        sort(a, a+n);
        int b[n];
        int ind = 0,i = 0, j = n-1;
        while(i<j){
            b[ind++] = a[i++];
            b[ind++] = a[j--];
        }
        if(i==j)
            b[ind] = a[i];
        for (int i = 0; i < n; ++i)
        {
            cout<<b[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
} 