#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k%3 || n<k || n==0){
            if(n%3)
                cout<<"Alice\n";
            else
                cout<<"Bob\n";
        }
        else{
            int temp = n%(k+1);
            if(temp%3==0 && temp!=k)
                cout<<"Bob\n";
            else
                cout<<"Alice\n";
        }
    }
    return 0;
}