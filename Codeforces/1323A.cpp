#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int res = -1;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i]%2==0){
                res = i+1;
            }
        }
        if(res!=-1){
            cout<<1<<endl<<res<<endl;
            continue;
        }
        if(n>=2){
            cout<<2<<endl<<1<<' '<<2<<'\n';
            continue;
        }
        cout<<"-1\n";

    }
    return 0;
}