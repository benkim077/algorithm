def solve():
    dp = [0] * (1000 + 1)
    
    dp[1] = 1
    dp[2] = 2

    for i in range(3, N + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[N] % 10_007


N = int(input())

ans = solve()

print(ans)