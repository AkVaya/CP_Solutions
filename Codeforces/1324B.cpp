#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        bool check=false;
        map<int,int> m;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j=n-1; j >= i+2;--j )
            {
                if(a[i]==a[j]){
                    check=true;
                    break;
                }
            }
            if(check)
                break;
        }
        if(check)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0; 
} 