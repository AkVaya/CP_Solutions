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
stack<vector<ll> >num;
stack<char> ch;
void fun(){
    ll a,b,c,d;
    vector<ll> v1,v2;
    while(ch.top()!='('){
        v2=num.top();
        num.pop();
        v1=num.top();
        num.pop();
        if(ch.top()=='&'){
            a=((v1[0]%M)*((v2[1]%M)+(v2[0]%M)+(v2[2]%M)+(v2[3]%M))%M)%M+((v1[1]%M)*(v2[0]%M))%M+((v1[2]%M)*(v2[0]%M))%M+((v1[2]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[0]%M))%M+((v1[3]%M)*(v2[2]%M));
            b=((v1[1]%M)*(v2[1]%M))%M;
            c=((v1[2]%M)*(v2[1]%M))%M+((v1[1]%M)*(v2[2]%M))%M+((v1[2]%M)*(v2[2]%M))%M;
            d=((v1[3]%M)*(v2[1]%M))%M+((v1[1]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[3]%M))%M;
            v1[0]=a%M;v1[1]=b%M;v1[2]=c%M;v1[3]=d%M;
            ch.pop();
            num.push(v1);
        }
        else if(ch.top()=='|'){
            a=((v1[0]%M)*(v2[0]%M))%M;
            b=((v1[1]%M)*(((v2[1]%M)+(v2[0]%M)+(v2[2]%M)+(v2[3]%M))%M))+((v1[0]%M)*(v2[1]%M))%M+((v1[2]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[2]%M))%M+((v1[3]%M)*(v2[1]%M))%M+((v1[2]%M)*(v2[1]%M))%M;
            c=((v1[2]%M)*(v2[0]%M))%M+((v1[0]%M)*(v2[2]%M))%M+((v1[2]%M)*(v2[2]%M));
            d=((v1[3]%M)*(v2[0]%M))%M+((v1[0]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[3]%M))%M;
            v1[0]=a%M;v1[1]=b%M;v1[2]=c%M;v1[3]=d%M;
            ch.pop();num.push(v1);
        }
        else if(ch.top()=='^'){
            a=((v1[0]%M)*(v2[0]%M))%M+((v1[1]%M)*(v2[1]%M))%M+((v1[2]%M)*(v2[2]%M))%M+((v1[3]%M)*(v2[3]%M))%M;
            b=((v1[0]%M)*(v2[1]%M))%M+((v1[1]%M)*(v2[0]%M))%M+((v1[3]%M)*(v2[2]%M))%M+((v1[2]%M)*(v2[3])%M)%M;
            c=((v1[0]%M)*(v2[2]%M))%M+((v1[2]%M)*(v2[0]%M))%M+((v1[1]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[1]%M))%M;
            d=((v1[0]%M)*(v2[3]%M))%M+((v1[3]%M)*(v2[0]%M))%M+((v1[1]%M)*(v2[2]%M))%M+((v1[2]%M)*(v2[1]%M))%M;
            v1[0]=a%M;v1[1]=b%M;v1[2]=c%M;v1[3]=d%M;
            ch.pop();num.push(v1);        
        }
    }
    ch.pop();
}
long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%M)*(a%M))%M;
        a = ((a%M)*(a%M))%M;
        b >>= 1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,count,ind;
    string s;
    vector <ll> v1;
    v1.eb(1);v1.eb(1);v1.eb(1);v1.eb(1);
    cin>>t;
    while(t--){        
        cin>>s;
        count=0;
        ch.push('(');
        ind=0;
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i]=='(' || s[i]=='|' || s[i]=='&' || s[i]=='^')
                ch.push(s[i]);
            else if(s[i]=='#'){
                num.push(v1);
                count++;
            }
            if(s[i]==')'){
                fun();
            }
        }
        if(num.size()>1)
            fun();
        ll temp=1;
        while(count--){
            temp=((temp%M)*(4))%M;
        }
        ind=binpow(temp,M-2)%M;
        cout<<((num.top()[0]%M)*(ind%M))%M<<" "<<((num.top()[1]%M)*(ind%M))%M<<" "<<((num.top()[2]%M)*(ind%M))%M<<" "<<((num.top()[3]%M)*(ind%M))%M<<endl;
        num.pop();
        while(!num.empty())
            num.pop();
        while(!ch.empty())
            ch.pop();
    }
    return 0 ;
}