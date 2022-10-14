import sys
input = sys.stdin.readline

N = int(input())
list = [0] * N
for i in range(N):
    list[i] = tuple(map(int, input().split()))

rank = [1] * N
for i in range(N):
    for j in range(N):
        if list[i][0] < list[j][0] and list[i][1] < list[j][1]:
            rank[i] += 1

print(*rank)