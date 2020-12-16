#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        while(a[i]%2==0)
            a[i]/=2;
        while(a[i]%3==0)
            a[i]/=3;
    }
    bool check = true; 
    for (int i = 1; i < n; ++i)
    {
        if(a[i]!=a[i-1]){
            check = false;
            break;
        }
    }
    if(check)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
