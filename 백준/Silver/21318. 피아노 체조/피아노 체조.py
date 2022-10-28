import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(input())
data = [0] + list(map(int, input().split()))

prefix_sum_data = [0] * (N + 1)
for i in range(1, N):
    if data[i] > data[i + 1]:
        prefix_sum_data[i] = 1
    else:
        prefix_sum_data[i] = 0
    prefix_sum_data[i] = prefix_sum_data[i] + prefix_sum_data[i - 1]
prefix_sum_data[N] = prefix_sum_data[N - 1] + prefix_sum_data[N]

# print(prefix_sum_data)

Q = int(input())
for _ in range(Q):
    x, y = map(int, input().split())
    ans = prefix_sum_data[y - 1] - prefix_sum_data[x - 1]
    print(ans)