#include <vector>
#include <iostream>
using namespace std;
/*
122. Best Time to Buy and Sell Stock II
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int buy, sell;
        int profit=0;
        while(i < prices.size()-1){
            while(i<prices.size()-1 && prices[i] >= prices[i+1]){
                i++;
            }
            buy = prices[i];
            //cout<<"buy at "<<buy<<endl;
            while(i<prices.size()-1 && prices[i] < prices[i+1]){
                i++;
            }
            sell = prices[i];
            //cout<<"sell at "<<sell<<endl;
            profit += sell-buy;
            buy=0, sell=0;
        }
        return profit;
    }
};