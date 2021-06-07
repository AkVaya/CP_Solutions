#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        bool check = false;
        cin>>s;
        int n = s.length();
        ll res = n, curr = 0, cnt = 0;
        int i = 0;
        char x = '?';
        while(i<n){
            if(x!='?')
                x = '1' - x + '0';
            if(s[i]=='?'){
                curr++;
                cnt++;
                i++;
                continue;
            }
            if(x=='?'){
                curr++;
                x = s[i];
            }
            else if(x!=s[i]){
                res+= (curr * (curr-1))/2;
                curr = 0;
                if(i && s[i-1]=='?')
                    curr = cnt;
                curr++;
                x = s[i];
                res -= (cnt * (cnt -1 ))/2;
            }
            else
                curr++;
            //cout<<curr<<' '<<cnt<<endl;
            i++;
            cnt = 0;
        }
        res += (curr * (curr-1))/2;
        cout<<res<<'\n';
        
    }
    return 0;
}