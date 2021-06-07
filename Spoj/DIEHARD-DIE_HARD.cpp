#include<bits/stdc++.h> 
using namespace std; 
const int nax = 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--){
        int h, a, res = -1;
        cin>>h>>a;
        bool check = true;
        while(h>0 && a>0){
            if(check){
                h+=3;
                a+=2;
            }
            else{
                if(h>20 && a<=10){
                    h-=20;
                    a+=5;
                }
                else{
                    h-=5;
                    a-=10;
                }
            }
            check = !check;
            res++;
        }
        cout<<max(res, 0)<<'\n';
    }
    return 0;
}