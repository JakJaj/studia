def maxProfit(prices):
    min = prices[0]
    max = 0
    i = 0
    while(i < len(prices)):
        if prices[i] < min:
            min = prices[i]
        if prices[i] - min > max:
            max = prices[i] - min
        i+=1
    return max