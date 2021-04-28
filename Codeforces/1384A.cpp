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
        int n;
        cin>>n;
        int a[n];
        string s[n+1];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];        
        }
        for (int i = 0; i < 200; ++i)
        {
            s[0]+="a";
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < a[i]; ++j)
            {
                s[i+1]+=s[i][j];
            }
            if(s[i][a[i]]=='a')
                s[i+1]+="b";
            else
                s[i+1]+="a";
            for (int j = a[i]+1; j < 200; ++j)
            {
                s[i+1]+="a";
            }
        }
        for (int i = 0; i < n+1; ++i)
        {
            cout<<s[i]<<endl;
        }
    }
    return 0;
}s