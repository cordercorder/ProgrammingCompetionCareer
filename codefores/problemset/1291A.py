t = int(input())

for i in range(t):
    n = int(input())
    s = input()
    index = []
    sum_digits = 0
    ans = None
    for j, ch in enumerate(s, start=1):
        tmp = int(ch)
        sum_digits += tmp
        if tmp % 2 == 1 and sum_digits % 2 == 0:
            ans = s[:j]
            break

    if ans is not None:
        print(ans)
    else:
        print('-1')