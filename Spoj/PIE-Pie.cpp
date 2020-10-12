#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const long long nax = 1e4 + 69 ;
const double pi = 3.14159265358979323846264338327950;
double n,a[nax],f;
bool check(double val){
	int cnt = 0;
	//cout<<val<<endl;
	for (int i = 0; i < n; ++i)
	{
		double temp = (a[i]*a[i]*pi)/(val); 
		cnt+=temp;
		//cout<<a[i]<<' '<<temp<<' '<<cnt<<endl;
	}
	//cout<<endl;
	return cnt>=f+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>f;
		double mx = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			mx = max(a[i],mx);
		}
		double l = 0.00001, r = mx*pi*mx;
		for (int i = 0; i < 50; ++i)
		{
		  	double mid = (l + r)/2.0;
		  	if(check(mid)){
		  		l = mid;
		  	}
		  	else
		  		r = mid;
		}  
		cout<<fixed<<setprecision(4);
		cout<<l<<'\n';
	}
}