import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N, M = map(int, input().split())
data = [[0] * (M + 1)] + [[0] + list(map(int, input().split())) for _ in range(N)]
# print(data)
prefix_sum_arr = [[0] * (M + 1) for _ in range(N + 1)]
for n in range(1, N + 1):
    for m in range(1, M + 1):
        prefix_sum_arr[n][m] = data[n][m] + prefix_sum_arr[n - 1][m] + prefix_sum_arr[n][m - 1] - prefix_sum_arr[n - 1][m - 1]
# print(prefix_sum_arr)

K = int(input())
for _ in range(K):
    i, j, x, y = map(int, input().split())
    # print(i, j, x, y)
    print(prefix_sum_arr[x][y] - prefix_sum_arr[x][j - 1] - prefix_sum_arr[i - 1][y] + prefix_sum_arr[i - 1][j - 1])
