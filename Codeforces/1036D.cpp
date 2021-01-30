#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 69;
using ll = long long;
ll a[nax],b[nax];
int main(){ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  	
	ll n,m,s1 = 0,s2 = 0,res = 0;
   	cin>>n;
   	for(int i = 0; i < n; ++i){
   		cin>>a[i];
   		s1+=a[i];
   	}
   	cin>>m;
   	for (int i = 0; i < m; ++i)
   	{
   		cin>>b[i];
   		s2+=b[i];
   	}
   	if(s1!=s2){
   		cout<<-1<<'\n';
   		return 0;
   	}
   	s1 = s2 = 0;
   	ll l1 = 0,l2 = 0;
   	while(l1!=n && l2!=m){
   		if(s1 && s1==s2){
   			s1=0;
   			s2=0;
   			res++;
   		}
   		if(s1<=s2){
   			s1+=a[l1++];
   		}
   		else
   			s2+=b[l2++];
   		//cout<<s1<<' '<<s2<<endl;
   	}
   	while(l1!=n)
   		s1+=a[l1++];
   	while(l2!=m)
   		s2+=b[l2++];
   	if(s1==s2 && s1)
   		res++;
   	cout<<max(res,1LL)<<'\n';
   	return 0;
}