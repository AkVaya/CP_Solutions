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
        ll n;
        string s;
        cin>>n>>s;
        vector<int> mnl(n+1, 0), mxr(n+1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if(s[i-1]=='R')
                mnl[i] = i;
            else if(s[i-1]=='L' && i>=2 && s[i-2]=='R')
                mnl[i] = mnl[i-2];
            else if(s[i-1]=='L')
                mnl[i] = i-1;
        }
        mxr[n] = n;
        for (int i = n-1; i >= 0; --i)
        {
            if(s[i]=='L')
                mxr[i] = i;
            else if(i+1<n && s[i]=='R' && s[i+1]=='L')
                mxr[i] = mxr[i+2];
            else
                mxr[i] = 1 + i; 
        }
        for (int i = 0; i <= n; ++i)
        {
            cout<<mxr[i] - mnl[i] + 1<<' '; 
        }
        cout<<'\n';
    }
    return 0;
}