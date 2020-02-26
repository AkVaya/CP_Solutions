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
#define M 1000000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll c=0,k=0;
    string s;
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='b')
            c++;
        else{
            k+=c;
            c*=2;
            k%=M;
            c%=M;
        }
    }
    cout<<k;
    return 0;
}