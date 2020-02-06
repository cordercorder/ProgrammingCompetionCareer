def solve():
    for i in range(n):
        mine = i
        for j in range(i, n):
            if s[j] < s[mine]:
                mine = j
        if mine != i:
            # print('mine=', mine,', i==',i)
            # for item in ind:
            #     print(item, end=' ')
            # print('end')
            color = -1
            for k in range(i, mine):
                if ans[ind[k]] != -1:
                    if color != -1 and color != ans[ind[k]]:
                        return False
                    color = ans[ind[k]]
            # print('color=', color)
            if color == -1:
                ans[ind[mine]] = 0
                color = 1
            else:
                if ans[ind[mine]] == -1:
                    ans[ind[mine]] = 1-color
                else:
                    if ans[ind[mine]] != 1-color:
                        return False
                    ans[ind[mine]] = 1-color

            for k in range(i, mine):
                ans[ind[k]] = color
            tmp = s[mine]
            tmpind = ind[mine]
            for k in range(mine, i, -1):
                s[k] = s[k-1]
                ind[k] = ind[k-1]
            s[i] = tmp
            ind[i] = tmpind

    return True


n = int(input())
s = list(input())
ans = [-1]*n
ind = list(range(n))
if solve():
    print('YES')
    for i in range(n):
        if ans[i] == -1:
            ans[i] = 0
    for i in ans:
        print(i, end='')
    print()
else:
    print('NO')