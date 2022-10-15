import sys
input = sys.stdin.readline


tbl_1 = [[0] * 8 for _ in range(8)]
tbl_2 = [[0] * 8 for _ in range(8)]
for i in range(8):
    for j in range(8):
        if (i + j) % 2 == 0:
            tbl_1[i][j] = 'W'
            tbl_2[i][j] = 'B'
        else:
            tbl_1[i][j] = 'B'
            tbl_2[i][j] = 'W'


N, M = map(int, input().split())
data = [list(input()) for _ in range(N)]

mn = 8 * 8
for sn in range(N - 8 + 1):
    for sm in range(M - 8 + 1):
        cnt_1, cnt_2 = 0, 0
        for i in range(sn, sn + 8):
            for j in range(sm, sm + 8):
                if data[i][j] != tbl_1[i - sn][j - sm]:
                    cnt_1 += 1
                if data[i][j] != tbl_2[i - sn][j - sm]:
                    cnt_2 += 1
                
        mn = min(mn, cnt_1, cnt_2)

print(mn)