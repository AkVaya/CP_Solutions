#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;

void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n0,n1,n2;
    cin>>n0>>n1>>n2;
    string s1="";
    string ans="";
    if(n1){
        for (int i = 0; i < n0+1; ++i)
        {
            s1+="0";
        }
        for (int i = 0; i < n2+1; ++i)
        {
            s1+="1";
        }
        if(n1){
            n1--;
            while(n1>1){
                s1+="01";
                n1-=2;
                //cout<<n1<<" ";
            }
            if(n1)
                s1+="0";
        }
        cout<<s1<<endl;
    }
    else {
        if(n0){
            for (int i = 0; i < n0+1; ++i)
            {
                cout<<"0";
            }
            cout<<endl;
        }
        else{
            for (int i = 0; i < n2+1; ++i)
            {
                cout<<"1";
            }
            cout<<endl;
        }


    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,q,x;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}