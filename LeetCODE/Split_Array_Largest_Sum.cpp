// BS solution
class Solution {
public:
    bool can(int sum,vector<int>&a,int m){
        int curr = 0, cnt = 0;
        for(auto i : a){
            if(i>sum)
                return false;
            if(curr+i>sum){
                curr = i;
                cnt++;
            }
            else{
                curr+=i;
            }
            if(cnt>m-1)
                return false;
        }
        if(curr>sum)
            cnt++;
        return cnt<=m-1;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 1e9;
        while(l<=r){
            int mid = (l+r)/2;
            if(can(mid,nums,m))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r+1;
        
    }
};
// DP solution
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> pref(nums.size(),0);
        vector<vector<int> > dp(m+1,vector<int>(nums.size(),INT_MAX));
        pref[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            pref[i] = nums[i] + pref[i-1];
        }
        for(int i = 0; i < nums.size(); ++i)
            dp[1][i] = pref[i] ;
        for(int x = 2; x <= m; ++x){
            for(int i = 0; i < nums.size(); ++i){
                for(int j = 0; j < i; ++j){
                    dp[x][i] = min(dp[x][i],max(dp[x-1][j],pref[i]-pref[j]));
                }
            }
        }
        return dp[m][nums.size()-1];
        
    }
};