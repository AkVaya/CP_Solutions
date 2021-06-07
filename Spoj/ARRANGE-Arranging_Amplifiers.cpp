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
        int n;
        cin>>n;
        int a[n];
        bool check = false;
        for (int i = 0; i < n; ++i){
            cin>>a[i];
            if(a[i]>3)
                check = true;
        }
        sort(a, a+n, greater<int>());
        int i = n-1;
        while(i>=0 && a[i]==1){
            cout<<1<<' ';
            i--;
            n--;
        }
        if(i==1 && !check){
            if(a[i]==2 && a[i-1]==3){
                cout<<2<<' '<<3;
            }
        }
        else{
            for (int i = 0; i < n; ++i)
            {
                cout<<a[i]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}