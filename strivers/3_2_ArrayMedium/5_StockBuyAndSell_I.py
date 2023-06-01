'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        least_stock_price = prices[0]
        profit = 0
        for price in prices:
            # Updating the least stock price in each iteration
            least_stock_price = min(least_stock_price, price)
            profit = max(profit, price - least_stock_price)
        return profit
        
