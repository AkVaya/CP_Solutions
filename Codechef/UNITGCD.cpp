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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,count;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            printf("%lld\n",n);
            printf("1 1\n");
        }
        else if(n==2){
            printf("%lld\n",n/2);
            printf("2 1 2\n");
        }
        else{
            printf("%lld\n",n/2);
            printf("3 1 2 3\n");
            n-=3;
            count=4;
            while(n>1){
                printf("2 %lld %lld\n",count++,count++);
                n-=2;
            }
            if(n==1)
                printf("1 %lld\n",count);
        }
    }
    return 0;
} 