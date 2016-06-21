int maxProfit(int* prices, int pricesSize)
{
    int l[pricesSize];
    int h[pricesSize];
    for (int i = 0; i < pricesSize; i++) {
        if (i == 0) {
            l[0] = 0;
            h[0] = 0;
        }
        else {
            int min = h[i - 1] + 1;
            for (int j = h[i - 1] + 1; j <= i; j++) {
                if (prices[j] < prices[min])
                    min = j;
            }
            int preProfit = prices[h[i - 1]] - prices[l[i - 1]];
            int currProfit = prices[i] - prices[l[i - 1]];
            int currProfitAll = prices[i] - prices[min];
            if (preProfit >= currProfit && preProfit >= currProfitAll) {
                l[i] = l[i - 1];
                h[i] = h[i - 1];
            }
            else if (currProfit >= preProfit && currProfit >= currProfitAll) {
                l[i] = l[i - 1];
                h[i] = i;
            }
            else if (currProfitAll >= preProfit && currProfitAll >= currProfit) {
                l[i] = min;
                h[i] = i;
            }
        }
    }
    return prices[h[pricesSize - 1]] - prices[l[pricesSize - 1]];
}
