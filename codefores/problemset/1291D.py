s = input()
q = int(input())

N = len(s)
prefix_sum = []

for i in range(N + 1):
    prefix_sum.append([0] * 26)

for i, ch in enumerate(s, start=1):
    tmp = ord(ch)-ord('a')
    for j in range(26):
        if tmp == j:
            prefix_sum[i][j] = prefix_sum[i-1][j]+1
        else:
            prefix_sum[i][j] = prefix_sum[i-1][j]

for case in range(q):
    l, r = list(map(int, input().split()))
    if l == r:
        print('Yes')
        continue
    if s[l-1] != s[r-1]:
        print('Yes')
    else:
        sum_ch = 0
        for i in range(26):
            if prefix_sum[r][i]-prefix_sum[l-1][i] > 0:
                sum_ch += 1
        print('Yes' if sum_ch > 2 else 'No')