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
        string s;
        cin>>s;
        int ind = n-1;
        int sum = 0;
        for(auto i : s)
            sum+=(i-'0');
        while(ind>=0 && (sum%2 || (s[ind]-'0')%2==0)){
            sum-=(s[ind]-'0');
            ind--;
        }
        if(ind>=1)
            cout<<s.substr(0, ind + 1)<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}