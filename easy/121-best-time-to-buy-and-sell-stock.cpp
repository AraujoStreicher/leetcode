int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0, min = 0, profit;

    for(int i = 1; i < pricesSize; i++){
        if(prices[i] < prices[min]){
            min = i;
        } else{
            profit =  prices[i] - prices[min];
            if(profit > max_profit)
                max_profit = profit; 
        }
        
    
    }

    return max_profit;
}