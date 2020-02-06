n, a, b, k = list(map(int, input().split()))
h = list(map(int, input().split()))
ans = 0

for i, item in enumerate(h):
    times = item//(a+b)
    if item % (a+b) == 0:
        times -= 1
    item = item-times*(a+b)
    tmp = item//a
    if item % a != 0:
        tmp += 1
    # print(tmp)
    tmp = tmp//2
    # print(times, k, tmp, item)

    if k >= tmp:
        k -= tmp
        ans += 1
    else:
        break
print(ans)