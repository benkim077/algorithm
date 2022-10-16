N = int(input())
data = list(map(int, input().split()))

dp = [0] * N
dp[0] = data[0]
for i in range(1, N):
    mx = 0
    for j in range(i):
        if data[j] < data[i]:
            mx = max(mx, dp[j])
    dp[i] = mx + data[i]

print(max(dp))