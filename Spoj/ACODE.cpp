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
ll dp(string &s,ll i,ll *memory){
    if(s[i]=='0' ){
        return 0;
    }
    else if(memory[i]!=-1){
        return memory[i];
    }
    else if((s[i]<='1' && i<s.length()-1 )|| (i<s.length()-1 && s[i+1]<='6' && s[i]=='2')){
        *(memory+i)= dp(s,i+1,memory) + dp(s,i+2,memory);
        return *(memory+i);
    }
    else{
        *(memory+i) = dp(s,i+1,memory);
        return *(memory+i);
    }
}
int main()
{
    string s;
    while(1){
        cin>>s;
        if(s=="0")
            break;
        ll memory[s.length()+1];
        for (int i = 0; i <= s.length(); ++i)
        {
            memory[i]=-1;
        }
        memory[s.length()]=1;
        cout<<dp(s,0,memory)<<endl;
    }
    return 0;
}
