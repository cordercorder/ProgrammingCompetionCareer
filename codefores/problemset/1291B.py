t = int(input())

def deb(lst):
    for item in lst:
        print(item, end=' ')
    print()

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    f = False

    pref = [True]*n
    suf = [True]*n

    for j, item in enumerate(a):
        if j == 0:
            pref[j] = item >= j
        else:
            pref[j] = pref[j - 1] & (item >= j)

    for cnt, j in enumerate(range(n-1, -1, -1)):
        if j == len(a)-1:
            suf[j] = a[j] >= cnt
        else:
            suf[j] = suf[j+1] & (a[j] >= cnt)
    #deb(pref)
    #deb(suf)
    for j in range(n):
        if pref[j] and suf[j]:
            f = True
            break
    if f:
        print('Yes')
    else:
        print('No')