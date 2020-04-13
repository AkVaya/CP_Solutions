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
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,x=0,y=0;
        cin>>n;
        char a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            bool check =false;
            if(a[i]=='R'){
                while(a[i]=='R' || a[i]=='L'){
                    i++;
                }
                x++;
            }
            else if(a[i]=='L'){
                while(a[i]=='R' || a[i]=='L'){
                    i++;
                }
                x--;
            }
            else if(a[i]=='U'){
                while(a[i]=='D' || a[i]=='U')
                    i++;
                y++;

            }
            else if(a[i]=='D'){
                while(a[i]=='D' || a[i]=='U')
                    i++;
                y--;
            }
            i--;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0 ;
}
