#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#define ll long long
using namespace std;
vector<long long> primes;
vector<pair<ll ,ll> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> v(2000001);
    fill(v.begin(),v.end(),true);
    v[0]=false;
    v[1]=false;
    primes.emplace_back(2);
    ll num,ans1;
    for (int i = 0; i <2000000; ++i)
    {
    	num=i+1;
    	ans1=0;
    	while((num)%2==0){
    		ans1++;
    		num/=2;
    	}
    	ans.push_back(make_pair(ans1,i+1));	
    }
    for (long long i = 3; i <2000000; i+=2)
    {
        if (v[i]==true)
        {
            primes.emplace_back(i);
            for (long long j = i; j < 2000000; j+=i)
            {
                v[j]=false;
                num=j;
    			ans1=0;
    			while((num)%i==0){
    				ans1++;
    				num/=i;
    			}
    			ans[j-1].first+=ans1;
            }
        }
    }
    sort(ans.begin(),ans.end());
    long long a;
    long long i=1;
    while(1){
        cin>>a;
        if(!a){
            break;
        }
        cout<<"Case "<<i<<": "<<ans[a-1].second<<endl;
        i++;
    }    
    return 0;
}