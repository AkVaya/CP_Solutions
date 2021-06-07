#include<bits/stdc++.h> 
using namespace std; 
const int nax = 1e6 + 69;
using ll = long long;
int fun(int x){
    int res = 1;
    while(x>=10){
        res*=10;
        res++;
        x/=10;
    }
    if(x)
        res*=x;
    return res;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool res = true;
        if(n<=10){
            cout<<"NO"<<endl;
            continue;
        }
        if(n%11==0 || n%111==0){
            cout<<"YES"<<endl;
            continue;
        }
        int x = n%11;
        n-=111*x;
        if(n>=0 && n%11==0){
            cout<<"YES";
        }
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
} 