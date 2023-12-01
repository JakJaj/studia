def subtractProductAndSum(n):
        add = 0
        prod = 1
        
        for i in str(n):
            temp = int(i)
            add += temp
            prod *= temp
            
        return prod - add
    
print(subtractProductAndSum(234)) # 15
print(subtractProductAndSum(4421)) # 21

def subtractProductAndSum2(n):
        add = 0
        prod = 1
        
        while n != 0:
            temp = n % 10
            add += temp
            prod *= temp
            n = n // 10
            
        return prod - add
    
print(subtractProductAndSum2(234)) # 15
print(subtractProductAndSum2(4421)) # 21