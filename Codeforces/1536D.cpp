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
        cin>>n;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        bool check = true;
        set<int> s;
        s.insert(a[0]);
        for (int i = 1; i < n; ++i)
        {
            if(a[i]!=a[i-1]){
                auto it = s.find(a[i-1]);
                auto x = it;
                auto y = it;
                ++x;
                if(a[i]>a[i-1] && (x!=s.end() && *x<a[i])){
                    check = false;
                    break;
                }
                else if(a[i]<a[i-1]){
                    if(it!=s.begin()){
                        --y;
                        if(*y>a[i]){
                            check = false;
                            break;
                        }
                    }
                }
            }
            s.insert(a[i]);
        }
        cout<<(check ? "YES" : "NO")<<'\n';
    }
    return 0;
}