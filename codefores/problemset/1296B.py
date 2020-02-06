def max_bit(x):
    cnt = 0
    ans = -1
    while x > 0:
        ans = x%10
        x = x//10
        cnt += 1
    return ans*pow(10, cnt-1)

t = int(input())

for case in range(t):

    s = int(input())
    ans = 0
    while s >= 10:
        tmp = max_bit(s)
        s -= tmp
        ans += tmp
        s += tmp//10
    ans += s
    print(ans)