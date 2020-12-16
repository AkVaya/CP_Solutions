#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int a[n],curr=0;
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
        if(s.find(a[i])!=s.end())
            continue;
        else{
        	if(curr<k){
        	    curr++;
        	    ans.push_back(a[i]);
                s.insert(a[i]);
  	        }
  	        else{
  	        	ans.push_back(a[i]);
  	        	s.insert(a[i]);
  	        	s.erase(ans[ans.size()-1-k]);
  	        }
        }
        //for(auto i : ans)
        //	cout<<i<<' ';
        //cout<<endl;
    }
    curr = 0;
    k = min((int) ans.size(),k);
    cout<<k<<'\n';
    while(curr<k){
        cout<<ans[ans.size()-1-curr++]<<' ';
    }
    cout<<'\n';
}