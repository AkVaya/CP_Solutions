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
#define ins insert 
#define mp make_pair
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 1000000000
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,k,ans,x,count;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        ll k,x,ans=0;
        cin>>k>>x;
        map<char,ll> m;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]<x){
                m[s[i]]++;
                ans++;
            }
            else{
                if(k>=1){
                    k--;
                }

            else
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}