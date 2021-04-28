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
        string s, t, p;
        cin>>s>>t>>p;
        bool check = false;
        int ind = 0;
        map<int,int> fir, sec;
        for(auto i : s){
            while(ind<t.length() && i!=t[ind])
                ind++;
            if(ind==t.length()){
                check = true;
                break;
            }
            fir[i-'a']++;
            ind++;
        }
        if(check){
            cout<<"NO\n";
            continue;
        }
        for(auto i : p)
            fir[i-'a']++;
        for(auto i : t)
            sec[i-'a']++;
        for(auto i : sec){
            if(i.second>fir[i.first])
                check = true;
        }
        cout<<(!check ? "YES\n" : "NO\n");

    }
    return 0;
}