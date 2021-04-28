#include<bits/stdc++.h> 
using namespace std; 
const int nax = 3e5 + 69;
using ll = long long;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    set<pair<int, int> > fir, sec;
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= n; ++j)
    	{
    		if((i+j)%2)
    			sec.insert({i, j});
    		else
    			fir.insert({i, j});
    	}
    } 
    while(cin>>n){
    	if(n==1){
    		if(sec.size()){
    			pair<int,int> it = *sec.begin();
    			cout<<2<<' '<<it.first<<' '<<it.second<<endl;
    			sec.erase(it);
    		}
    		else{
    			pair<int,int> it = *fir.begin();
    			cout<<3<<' '<<it.first<<' '<<it.second<<endl;
    			fir.erase(it);
    		}
    	}
    	else if(n==2){
    		if(fir.size()){
    			pair<int,int> it = *fir.begin();
    			cout<<1<<' '<<it.first<<' '<<it.second<<endl;
    			fir.erase(it);
    		}
    		else{
    			pair<int,int> it = *sec.begin();
    			cout<<3<<' '<<it.first<<' '<<it.second<<endl;
    			sec.erase(it);
    		}
    	}
    	else{
    		if(fir.size()){
    			pair<int,int> it = *fir.begin();
    			cout<<1<<' '<<it.first<<' '<<it.second<<endl;
    			fir.erase(it);
    		}
    		else{
    			pair<int,int> it = *sec.begin();
    			cout<<2<<' '<<it.first<<' '<<it.second<<endl;
    			sec.erase(it);
    		}
    	}
    }
	return 0;
} 