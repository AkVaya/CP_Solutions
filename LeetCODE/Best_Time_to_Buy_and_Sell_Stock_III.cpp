class Solution {
public:
    int maxProfit(vector<int>& a) {
        int buy1, buy2, sell1, sell2;
        sell1 = sell2 = 0;
        buy1 = buy2 = INT_MAX;
        for(auto i : a){
            buy1 = min(buy1, i);
            sell1 = max(sell1, i - buy1);
            buy2 = min(i - sell1, buy2);
            sell2 = max(sell2, i - buy2);
        }
        return sell2;
    }
};