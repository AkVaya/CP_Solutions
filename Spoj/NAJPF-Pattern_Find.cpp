#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69;
void findLps(string a,vector<int>&lps){
	int i = 1, j = 0;
	lps[0] = 0;
	int n = a.length();
	while(i<n){
		if(a[i]==a[j]){
			j++;
			lps[i] = j;
			i++;
		}
		else if(!j){
			lps[i] = 0;
			i++;
		}
		else{
			j = lps[j-1];
		}
	}
}
vector<int> match(string s,string t, vector<int>& lps){
	int i = 0, j = 0;
	vector<int> res;
	while(i<s.length()){
		if(s[i]==t[j]){
			i++;
			j++;
		}
		if(j==t.length()){
			res.push_back(i-j);
			j = lps[j-1];
		}
		else if(i<s.length() && s[i]!=t[j]){
			if(j)
				j = lps[j-1];
			else
				i++;
		}
	}
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
    	string s,t;
    	cin>>s;
    	cin>>t;
    	if(s.length()<t.length()){
    		cout<<"Not Found\n\n";
    		continue;
    	}
    	else{
    		vector<int> lps(s.length(),0);
    		findLps(t,lps);
    		vector<int> res = match(s,t,lps);
    		if(res.size()){
    			cout<<res.size()<<'\n';
    			for(auto i : res)
    				cout<<i+1<<' ';
    			cout<<'\n'<<'\n';
    		}
    		else
    			cout<<"Not Found\n\n";
    	}
    }
   	return 0;
}