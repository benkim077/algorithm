N = int(input())

if N == 1:
    print(1)
    exit()
elif N == 2:
    print(2)
    exit()
else:
    dp = [0] * (N + 1)
    dp[1] = 1
    dp[2] = 2
    for k in range(3, N + 1):
        dp[k] = (dp[k - 1] + dp[k - 2]) % 15746
    print(dp[N])