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
    ll t,a,b,c;
    ll ans,tempC,finalA,finalB,finalC,min;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        min=M;
        for (int x = 1; x <= 2*a; ++x)
        {
            for (int y = x; y <= 2*b; y+=x)
            {
                for (int i = 0; i < 2; ++i)
                {
                    tempC = (c/y)*y + (i*y);
                    ans= abs(a-x)+abs(b-y)+abs(c-tempC);
                    if(ans<min){
                        min=ans;
                        finalC=tempC;
                        finalB=y;
                        finalA=x;
                    }

                }
            }
        }
        cout<<min<<endl<<finalA<<" "<<finalB<<" "<<finalC<<endl;
    }
    return 0;
}