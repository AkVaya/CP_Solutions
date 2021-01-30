#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 2e5 + 69;
ll n,h,a[nax];
bool fun(ll val,ll sum,ll mn){
	ll temp = h;
	if((val/n)>temp)
		return true;
	//cout<<temp<<' '<<val/n<<endl;
	//cout<<temp-val/n<<endl;
	//cout<<(temp+(max((val/n)-1,0LL))*sum)<<endl;
	if(temp<=abs((val/n)*sum) || (val>=n && (temp+(max((val/n)-1,0LL))*sum)+mn<=0))
		return true;
	temp+=((val/n)*sum);
	val%=n;
	//cout<<val<<' '<<temp<<endl;
	for (int i = 0; i < val; ++i)
	{
		temp+=a[i];
		if(temp<=0)
			return true;
	}
	return false;
}
int main(){
	cin>>h>>n;
	ll sum = 0,mn = 1e18;
	bool check = false;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		mn = min(mn,sum);
		if(sum+h<=0)
			check = true;
	}
	//cout<<h<<' '<<n<<endl;
	//cout<<mn<<' '<<sum<<endl;
	ll l = 1,r = 1e18 + 1;
	if(sum>=0 && !check){
		cout<<-1<<'\n';
		return 0;
	}
	else if(sum>=0){
		int curr = 0;
		for (int i = 0; i < n; ++i)
		{
			curr+=a[i];
			if(curr+h<=0){
				cout<<i+1<<'\n';
				return 0;
			}
		}
		cout<<-1<<'\n';
		return 0;
	}
	while(l<=r){
		ll mid = (l + r)/2;
		bool res = fun(mid,sum,mn);
	//	cout<<mid<<' '<<res<<endl;
		if(res)
			r = mid - 1;
		else
			l = mid + 1;
	}
	//cout<<"YAHA"<<endl;
	//cout<<r<<endl;
	if(r==1e12+1)
		cout<<-1<<'\n';
	else
		cout<<r+1<<'\n';
	return 0;
}