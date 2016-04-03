int maxProfit(int* prices, int pricesSize)
{
    int profit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        int p = prices[i + 1] - prices[i];
        profit += p > 0 ? p : 0;
    }
    return profit;
}
