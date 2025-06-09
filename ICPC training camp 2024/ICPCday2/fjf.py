# def possible_sums(coins, quantity):
    
    
#     sums = set()
#     sums.add(0)
#     res=0
#     for i in range(1,(coins+1)):
#         sums_now = list(sums)
#         for sum_ in sums_now:
#             for j in range(1, quantity[i] + 1):
#                 sums.add(sum_ + j * i)
#                 res+=1
    
#     return len(sums) 

# def count_distinct_sums(n, a):
#     max_sum = sum(i * a[i] for i in range(1, n + 1))
#     dp = [False] * (max_sum + 1)
#     dp[0] = True
    
#     for i in range(1, n + 1):
#         new_dp = dp[:]
#         for j in range(1, a[i] + 1):
#             for x in range(max_sum - i * j, -1, -1):
#                 if dp[x]:
#                     new_dp[x + i * j] = True
#         dp = new_dp
    
#     return sum(dp)