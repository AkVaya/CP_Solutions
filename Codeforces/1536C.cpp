#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
         int n;
         string s;
         cin>>n>>s;
         int cnt = 0, cnt1 = 0;
         map<string, int> m;
         for (int i = 0; i < n; ++i)
         {
            if(s[i]=='D')
                cnt++;
            else
                cnt1++;
            // cout<<i<<' '<<cnt<<' '<<cnt1<<':';
            if(!cnt || !cnt1){
                cout<<(cnt ? cnt : cnt1)<<' ';
            }
            else{
                int val = __gcd(cnt1, cnt);
                int a = cnt / val, b = cnt1 / val;
                string x = to_string(a) + " " + to_string(b);
            //cout<<i<<' '<<cnt<<' '<<cnt1<<' '<<a<<' '<<b<<endl;
                cout<<++m[x]<<' ';
            }
         }
         cout<<'\n';
    }
    return 0;
}
/*          for (int j = 0; j < n; ++j)
            {
                
            }
*/