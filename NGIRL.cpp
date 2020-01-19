    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<cstring>
    #define ll  long long
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<bool> v(100000+1);
        vector<ll> :: iterator it;
        vector<ll> x;
        fill(v.begin(),v.end(),true);
        v[0]=false;
        v[1]=false;
        x.emplace_back(2);
        for (ll i = 3; i <=100000; i+=2)
        {
            if (v[i]==true)
            {
                x.emplace_back(i);
                for (ll j = i*i; j <= 100000; j+=i)
                {
                    v[j]=false;
                }
            }
        }
        ll t,n,k,ans,num;
        cin>>t;
        while(t--){
            cin>>n>>k;
            ans=0,num=0;
            for (int i = 0; i < x.size(); ++i)
            {
                if(x[i]*x[i]<=n){
                    num++;
                    if(x[i]*x[i]>k){
                        ans++;
                    }
                }
                else{
                    break;
                }
            }
            cout<<num<<" "<<ans<<endl;
        }
        return 0;
    } 