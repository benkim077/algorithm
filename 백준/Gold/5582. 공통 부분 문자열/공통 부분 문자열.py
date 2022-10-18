string_A = input()
string_B = input()

len_A = len(string_A)
len_B = len(string_B)
dp = [[0] * (len_B + 1) for _ in range(len_A + 1)]

mx = 0
for a in range(len_A):
    for b in range(len_B):
        if string_A[a] == string_B[b]:
            dp[a + 1][b + 1] = dp[a][b] + 1
        else:
            dp[a + 1][b + 1] = 0
        mx = max(mx, dp[a + 1][b + 1])

print(mx)