#include<bits/stdc++.h>
using namespace std;
int main(){
   	vector<set<int> >ind(26);
   	string s;
   	int q,x,y;
   	cin>>s>>q;
   	for (int i = 0; i < s.length(); ++i)
   	{
   		ind[s[i]-'a'].insert(i);
   	}
   	while(q--){
   		cin>>x>>y;
   		if(x==1){
   			char z;
   			cin>>z;
   			y--;
   			ind[s[y]-'a'].erase(y);
   			s[y] = z;
   			ind[s[y]-'a'].insert(y);
   		}
   		else{
   			int z;
   			cin>>z;
   			y--;
   			z--;
   			int res = 0;
   			for (int i = 0; i < 26; ++i)
   			{
   				auto it = ind[i].lower_bound(y);
   				if(it!=ind[i].end() && *it<=z)
   					res++;
   			}
   			cout<<res<<'\n';
   		}
   	}
}