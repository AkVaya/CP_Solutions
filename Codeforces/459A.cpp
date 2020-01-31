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
int main(){
    ios_base::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1!=x2 && y1!=y2 && abs(x1-x2)!=abs(y1-y2)){
        cout<<-1<<endl;
    }
    else if(x1==x2){
        cout<<x1+abs(y1-y2)<<" "<<y1<<" "<<x2+abs(y1-y2)<<" "<<y2<<endl;
    }
    else if(y1 == y2){
        cout<<x1<<" "<<y1+abs(x1-x2)<<" "<<x2<<" "<<y2+abs(x1-x2)<<endl;
    }
    else{
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
    }
    return 0 ;
}