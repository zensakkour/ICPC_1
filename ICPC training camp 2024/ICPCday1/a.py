def count_signals(L):
    MOD = 3000017
    dp = [[0, 0] for _ in range(L + 1)]
    dp[0][0] = 1
    
    for i in range(L):
        for k in range(1, L - i + 1):
            dp[i + k][0] = (dp[i + k][0] + dp[i][0] + dp[i][1]) % MOD
            dp[i + k][1] = (dp[i + k][1] + dp[i][0]) % MOD
    
    return dp[L][0]

# Example usage:
L = int(input())
print(count_signals(L))
