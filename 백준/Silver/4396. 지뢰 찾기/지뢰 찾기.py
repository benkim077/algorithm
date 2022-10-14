N = int(input())
mine_data = [list(input()) for _ in range(N)]
current_data = [list(input()) for _ in range(N)]

board = [['.'] * N for _ in range(N)]


for i in range(N):
    for j in range(N):
        if current_data[i][j] == 'x':
            board[i][j] = 0

flag = False
for i in range(N):
    for j in range(N):
        if mine_data[i][j] == '*':
            for di, dj in [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < N and 0 <= nj < N and board[ni][nj] != '.':
                    board[ni][nj] += 1

            if current_data[i][j] == 'x':
                flag = True

if flag:
    for i in range(N):
        for j in range(N):
            if mine_data[i][j] == '*':
                board[i][j] = '*'

for i in range(N):
    for j in range(N):
        print(board[i][j], end='')
    print()