// Stock Buy and Sell to Maximize Profit (1 transaction)
// Given an array of prices where prices[i] is the price of a stock on the i-th day, find the maximum profit you can achieve from one buy and one sell.
// You must buy before you sell.

// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;
        } else {
            maxProfit = max(maxProfit, price - minPrice);
        }
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}