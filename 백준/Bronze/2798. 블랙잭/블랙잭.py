N, M = map(int, input().split())
data = list(map(int, input().split()))

mx = 0
for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            sm = data[i] + data[j] + data[k]
            if sm <= M:
                mx = max(mx, sm)

print(mx)