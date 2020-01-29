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
#define M 10000007
using namespace std;
int main()
{
    ll n,t,x=1;
    ll fun1[1001]={0},fun2[1001]={0},fun3[1001]={0};
    fun1[0]=1;
    fun1[1]=1;
    fun2[0]=1;
    fun2[1]=2;
    fun3[0]=1;
    fun3[1]=1;
    for (int i = 2; i <= 1000; ++i)
    {
        fun1[i] = fun1[i-1] + fun1[i-2] + 2*fun2[i-2] + fun3[i-2];
        fun2[i] = fun1[i]+fun2[i-1];
        fun3[i] = fun3[i-2] + fun1[i];
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<x++<<" "<<fun1[n]<<endl;
    }

        
    return 0;
} 