#include<bits/stdc++.h>
using namespace std;
const long long nax = 5e4 + 69 ;
double v,n,a[nax][4];
bool check(double val){
    double total = 0.0,temp;
    bool check = false;
    for (int i = 0; i < n; ++i)
    {
        if(a[i][0]>=val)
            continue;
        temp = (val-a[i][0]<a[i][1] ? val-a[i][0] : a[i][1]);
        total += (temp*a[i][2]*a[i][3]);
    }
    return total<=v;
}
double correction(double val){
	double res = 0.0;
    bool check = false; 
    for (int i = 0; i < n; ++i)
    {
        if(a[i][0]>=val)
            continue;
        if(val>a[i][0] && val<=a[i][0]+a[i][1])
        	check = true;
    }
    if(check)
    	return val;
    for (int i = 0; i < n; ++i)
    {
        if(a[i][0]>=val)
            continue;
        res = max(res,a[i][0]+a[i][1]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        double total = 0.0,mx = 0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
            total += (a[i][1]*a[i][2]*a[i][3]);
            mx = max(a[i][1] + a[i][0],mx);
        }
        cin>>v;
        if(total<v){
            cout<<"OVERFLOW\n";
            continue;
        }
        double l = 0.0, r = mx+1;
        for (int i = 0; i < 45; ++i)
        {
        	double mid = (l + r)/2.0;
            if(check(mid)){
                l = mid;
            }
            else
                r = mid;
        }  
        l = correction(l);
        cout<<fixed<<setprecision(2);
        cout<<l<<'\n';
    }
}