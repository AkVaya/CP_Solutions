#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e7 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int curr = 0;
        for (int i = 1; i < s.length(); ++i)
        {
            if(s[i]==s[i-1])
                curr+=2;
            else
                curr++;
        }
        //cout<<curr<<endl;
        while(k--){
            int x;
            cin>>x;
            x--;
            s[x] = '1' - s[x] + '0';
            if(x && s[x]==s[x-1])
                curr++;
            else if(x)
                curr--;
            if(x+1<n && s[x+1]==s[x])
                curr++;
            else if(x+1<n)
                curr--;
            cout<<curr<<'\n';
        }
    }
    return 0;
} 