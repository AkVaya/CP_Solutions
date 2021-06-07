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
        int a[n];
        int neg = 0, pos = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i]>=0)
                pos++;
            else if(a[i]<0)
                neg++;
        }
        if(neg){
            cout<<"NO\n";
            continue;
        }
        int mn = *max_element(a, a+n);
        cout<<"YES\n";
        cout<<mn + 1<<'\n';
        for (int i = 0; i <= mn; ++i)
        {
            cout<<i<<' ';
        }
        cout<<'\n';    
    }
    return 0;
}
/*          for (int j = 0; j < n; ++j)
            {
                
            }
*/