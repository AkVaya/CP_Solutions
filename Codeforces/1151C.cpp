#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
const ll M = 1e9 + 7;
ll fun(ll r){
	if(r==0 || r==1)
		return r;
	//cout<<"fun of "<<r<<":"<<endl;
	ll fir = 0,sec = 0, flip = 1,curr = 0;
	while(curr<r){
		if(!curr)
			curr++;
		if(!flip)
			sec+=curr;
		else
			fir+=curr;
		flip = 1 - flip;
		curr*=2;
	}
	if(curr!=r){
		curr=(curr)/2;
		if(flip)
			sec-=curr;
		else
			fir-=curr;
		curr--;
	}
	else if(flip)
		fir++;
	else
		sec++;
	ll res = 0;
	//cout<<r<<' '<<curr<<endl;
	if(flip){
	//	cout<<"UPAR ";
		fir%=M;
		res = (fir*fir)%M;
		sec+=r-curr;
		sec%=M;

		res = (res + ((sec+1)*sec)%M)%M;
	//	cout<<fir<<' '<<sec<<' '<<res<<endl;
	}	
	else{
	//	cout<<"NEECHE ";
		fir+=r-curr;
		sec%=M;
		fir%=M;
		res = (fir*fir)%M;
		res = (res + ((sec+1)*sec)%M)%M;
	//	cout<<fir<<' '<<sec<<' '<<res<<endl;
	}
	//cout<<r<<' '<<res<<endl;
	return res%M;
}
int main(){
	ll l,r;
	cin>>l>>r;
	cout<<((fun(r) - fun(l-1) + M)%M)<<'\n';

	return 0;
}