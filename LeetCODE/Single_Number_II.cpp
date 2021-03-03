class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for(auto i : nums){
            once = (once ^ i) & (~twice);
            twice = (twice ^ i) & (~once);
        }
        return once;
    }
};