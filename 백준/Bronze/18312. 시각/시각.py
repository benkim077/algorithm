N, K = map(int, input().split())

cnt = 0
for i in range(0, 60 * 60 * (N + 1)):
    s = i % 60
    m = i // 60 % 60
    h = i // 60 // 60
    h, m, s = str(h), str(m), str(s)
    h = '0' + h if len(h) == 1 else h
    m = '0' + m if len(m) == 1 else m
    s = '0' + s if len(s) == 1 else s
    time = h + m + s
    
    if str(K) in time:
        cnt += 1

print(cnt)