N = int(input())
data = list(map(int, input().split()))

dp = [0] * N
dp[0] = data[0]
for k in range(1, N):
    dp[k] = max(data[k] + dp[k - 1], data[k])

print(max(dp))