class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind = nums.size()-1, res = 0,cnt = 0;
        for(auto i : nums)
            if(i==val)
                cnt++;
        //cout<<cnt<<endl;
        if(cnt==nums.size())
            return 0;
        for(int i = 0; i <= ind && ind>=nums.size()-cnt; ++i){
            while(nums[ind]==val)
                ind--;
            if(i<=ind && nums[i]==val){
                swap(nums[i],nums[ind--]);
            }
        }
        return ind+1;
    }
};