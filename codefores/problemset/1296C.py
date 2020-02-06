t = int(input())

for case in range(t):
    n = int(input())
    s = input()
    deta_sum = []
    for i in range(n+1):
        deta_sum.append([0]*2)

    for i, ch in enumerate(s, start=1):
        for j in range(2):
            deta_sum[i][j] = deta_sum[i-1][j]
        if ch == 'L':
            deta_sum[i][0] += 1
        elif ch == 'R':
            deta_sum[i][0] -= 1
        elif ch == 'U':
            deta_sum[i][1] += 1
        else:
            deta_sum[i][1] -= 1

    isv = dict()
    isv[(0, 0)] = 0
    ans = 1000000000
    l = 0
    r = 0
    for i in range(1, n+1):
        tmp = isv.get((deta_sum[i][0], deta_sum[i][1]), -1)

        if tmp != -1 and i-tmp < ans:
            ans = i-tmp
            l = tmp+1
            r = i
        isv[(deta_sum[i][0], deta_sum[i][1])] = i
    if ans != 1000000000:
        print(l, r)
    else:
        print('-1')