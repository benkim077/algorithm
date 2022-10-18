st_A = [0] + list(input())
st_B = [0] + list(input())

A = len(st_A)
B = len(st_B)
dp = [[0] * (B + 1) for _ in range(A + 1)]

mx = 0
for a in range(1, A):
    for b in range(1, B):
        if st_A[a] == st_B[b]:
            dp[a][b] = dp[a - 1][b - 1] + 1
        else:
            dp[a][b] = 0
        mx = max(mx, dp[a][b])

print(mx)