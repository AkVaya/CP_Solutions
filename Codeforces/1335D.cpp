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
#define M 1000000007
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,a,b;
    cin>>t;
    while(t--){
        char a[9][9];
        for (int i = 0; i < 9; ++i)
        {
            for(int j=0;j<9;j++){
                cin>>a[i][j];
                if(a[i][j]=='1')
                    a[i][j]='2';
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            for(int j=0;j<9;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}