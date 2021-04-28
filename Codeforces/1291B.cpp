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
        set<int> s;
        s.insert(-1);
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        bool check = true;
        int l = 0, r = n-1;
        while(l<r){
            if(s.find(a[l])!=s.end() || s.find(a[r])!=s.end())
                break;
            auto it = s.end();
            --it;
            if(*it+1==a[l] && *it+1==a[r] && l+1==r && n%2==0){
                l = 0;
                break;
            }
            s.insert(*it + 1);
            l++;
            r--;
        }
        if(n%2 && s.find(a[r])!=s.end())
            l = 0;
        if(l<r)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}