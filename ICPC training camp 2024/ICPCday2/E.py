def possible_sums(coins, quantity):
    
    
    sums = set()
    sums.add(0)
    res=0
    for i in range(1,(coins+1)):
        sums_now = list(sums)
        for sum_ in sums_now:
            for j in range(1, quantity[i] + 1):
                sums.add(sum_ + j * i)
                res+=1
    
    return len(sums) 

n = int(input())
quantity = list(map(int, input().split()))
quantity = [0]+quantity

res=possible_sums(n,quantity)
print(res)