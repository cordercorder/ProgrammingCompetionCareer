t = int(input())

for case in range(t):
    n, m, k = list(map(int, input().split()))
    a = list(map(int, input().split()))

    ans = 0
    for i in range(min(k, m-1)+1):
        tmp = 10000000000
        for j in range(m-min(k, m-1)):
            tmp = min(tmp, max(a[i+j], a[n-m+i+j]))
        ans = max(ans, tmp)
    print(ans)