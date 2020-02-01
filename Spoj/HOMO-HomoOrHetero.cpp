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
    ll n;
    cin>>n;
    string str,ans="1";
    ll a[n];
    map<ll,ll> m ;
    set<ll> s;
    ll num=0;
    bool isHetero , isHomo,check;
    for (int i = 0; i < n; ++i)
    {
        cin>>str>>a[i];
        isHetero=false;
        check=false;
        isHomo = false;
        if(str[0]=='i'){
            s.insert(a[i]);
            if(m.find(a[i])!=m.end()){
                m[a[i]]++;
                if(m[a[i]]>=2){
                    num++;
                }
            }
            else
                m[a[i]]=1;
            if(num){
                isHomo=true;
            }
            if(s.size()>=2){
                isHetero=true;
            }
        }
        else{
            if(m.find(a[i])!=m.end() && m[a[i]]==1){
                s.erase(a[i]);
                m[a[i]]=0;
            }
            else if(m.find(a[i])!=m.end()){
                m[a[i]]--;
                if(m[a[i]]<2){
                    num--;
                }
                //check=true;
            }
            if(num){
                isHomo=true;
            }
            if(s.size()>=2){
                isHetero=true;
            }
        }
        if(isHomo && isHetero){
            cout<<"both"<<endl;
        }
        else if(!isHetero && isHomo){
            cout<<"homo"<<endl;
        }
        else if(isHetero && !isHomo){
            cout<<"hetero"<<endl;
        }
        else{
            cout<<"neither"<<endl;
        }
    }
    return 0;
}