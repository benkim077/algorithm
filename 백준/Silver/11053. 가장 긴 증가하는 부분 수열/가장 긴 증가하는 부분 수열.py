N = int(input())
data = list(map(int, input().split()))

dp = [0] * N
dp[0] = 1
for i in range(1, N):
    mx = 0
    for j in range(0, i):
        if data[j] < data[i]:
            mx = max(mx, dp[j])
    dp[i] = mx + 1

# print(dp)
print(max(dp))