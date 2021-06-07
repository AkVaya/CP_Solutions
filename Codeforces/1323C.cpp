#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int res = 0;
        int last = -1;
        int cnt0 = 0, cnt1 = 0, diff = 0;
        for (int i = 0; i < n; ++i)
        {
            if(s[i]=='(')
                cnt0++;
            else
                cnt1++;
        }
        if(cnt0!=cnt1){
            cout<<"-1\n";
            continue;
        }
        int i = 0;
        while(i<n){
            if(s[i]==')'){
                cnt0 = cnt1 = 0;
                cnt1++;
                i++;
                while(i<n && cnt0!=cnt1){
                    if(s[i]=='(')
                        cnt0++;
                    else
                        cnt1++;
                    i++;
                }
                res+=cnt0 + cnt1;
            }
            else{
                cnt0 = cnt1 = 0;
                cnt0++;
                i++;
                while(i<n && cnt0!=cnt1){
                    if(s[i]=='(')
                        cnt0++;
                    else
                        cnt1++;
                    i++;
                }
            }
        }
        cout<<res<<'\n';


    }
    return 0;
}