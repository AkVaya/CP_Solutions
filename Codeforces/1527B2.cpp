#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int fun(string s){
    int res = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i]!=s[s.length()-i-1])
            res++;
    }
    return res/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        for(auto i : s)
            cnt+=i=='0';
        int val = fun(s);
        if(val==0)
        {
            if(n%2 && s[n/2]=='0' && cnt>1){
                cout<<"ALICE\n";
            }
            else{
                cout<<"BOB\n";
            }
        }
        else if((val==1 && cnt==2))
            cout<<"DRAW\n";
        else{
            cout<<"ALICE\n";
        }
    }
    return 0;
}