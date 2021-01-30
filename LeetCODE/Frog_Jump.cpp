class Solution {
public:
    int dp[2001][2001];
    bool canCross(vector<int>& stones,int k = 1, int ind = 0) {
        if(ind==0){
            
            if(stones.size()>1){
                if(stones[1]!=stones[0]+1)
                    return false;
                else
                    return canCross(stones,1,ind+1);
            }
            else
                return true;
        }
        //cout<<stones[ind]<<' '<<k<<endl;
        if(ind == stones.size()-1 || dp[ind][k]==1)
            return true;
        else if(dp[ind][k]==2 || k<=0)
            return false;
        bool res = false;
        auto x = lower_bound(stones.begin(),stones.end(),stones[ind]+k);
        if(x!=stones.end() && *x==(stones[ind]+k)){
            res |= canCross(stones,k,x-stones.begin());
        }
        if(res){
            dp[ind][k] = 1;
            return res;
        }
        x = lower_bound(stones.begin(),stones.end(),stones[ind]+k+1);
        if(x!=stones.end() && *x==(stones[ind]+k+1)){
            res |= canCross(stones,k+1,x-stones.begin());
        }
        if(res){
            dp[ind][k] = 1;
            return res;
        }
        x = lower_bound(stones.begin(),stones.end(),stones[ind]+k-1);
        if(x!=stones.end() && *x==(stones[ind]+k-1)){
            res |= canCross(stones,k-1,x-stones.begin());
        }
        //cout<<ind<<endl;
        dp[ind][k] = (res ? 1 : 2);
        return res;
    }
};