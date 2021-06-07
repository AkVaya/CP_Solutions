#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
bool is(int i, int j){
    while(j){
        if(j%10==i)
            return true;
        j/=10;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    bool check[10][100];
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 1; j < 100; ++j)
        {
            if(is(i, j) || (j>i && check[i][j-i]))
                check[i][j] = true;
            else
                check[i][j] = false;
        }
    }
    while(t--){
        int n, d, x;
        cin>>n>>d;
        while(n--){
            cin>>x;
            if(x<d){
                cout<<"NO\n";
                continue;
            }
            if(x%d==0 || x>10*d){
                cout<<"YES\n";
                continue;
            }
            cout<<(check[d][x] ? "YES\n" : "NO\n");
        }
    }
    return 0;
}