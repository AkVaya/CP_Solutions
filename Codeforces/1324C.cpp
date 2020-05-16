#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> v;
        v.push_back(0);
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i]=='R')
                v.push_back(i+1);
        }
        v.push_back(s.length()+1);
        long long ans=0;
        for (int i = 0; i < v.size()-1; ++i)
        {
             if(v[i+1]-v[i]>ans)
                ans=v[i+1]-v[i];
        }
        if(v.empty())
            ans=s.length()+1;
        cout<<ans<<endl;
    }
    return 0; 
} 