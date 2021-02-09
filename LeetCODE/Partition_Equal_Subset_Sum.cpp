class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = 100*100+1;
        bitset<n> bs(1);
        int sum = 0;
        for(auto i : nums){
            sum += i;
            bs |= (bs<<i);
        }
        if(sum%2 || !bs[sum/2])
            return false;
        return true;
    }
};