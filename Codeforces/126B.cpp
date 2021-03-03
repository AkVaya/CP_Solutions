#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.length();
	vector<int> lps(n,0);
	vector<string> possible;
	int i = 1, j = 0;
	while(i<n){
		if(s[i]==s[j])
			lps[i++]=++j;
		else if(j)
			j = lps[j-1];
		else
			lps[i++] = 0;
	}
	bool check = false;
	int val = lps[n-1];
	if(!val){
		cout<<"Just a legend\n";
		return 0;
	}
	//cout<<val<<endl;
	for(i = 0; i < n-1; ++i){
		if(lps[i]==val){
			check = true;
			break;
		}
	}
	if(check){
		for(i = n-val; i < n; ++i)
			cout<<s[i];
		cout<<'\n';
	}
	else{
		val = lps[val-1];
		if(!val){
			cout<<"Just a legend\n";
			return 0;
		}
		for(i = 0; i < n-1; ++i){
			if(lps[i]==val){
				check = true;
				break;
			}
		}
		if(check){
			for(i = n-val; i < n; ++i)
				cout<<s[i];
			cout<<'\n';
		}
		else
			cout<<"Just a legend\n";
	}
	return 0;
}