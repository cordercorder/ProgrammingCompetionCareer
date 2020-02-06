import sys


def find_path(u, pre, target, weight):

    if u == target:
        return True

    for i, (v, w) in enumerate(graph[u]):
        if v == pre:
            continue
        if find_path(v, u, target, weight):
            if graph[u][i][1] == 1000000:
                graph[u][i][1] = weight
            else:
                graph[u][i][1] = max(graph[u][i][1], weight)
            return True

    return False


def check(u, pre, target):

    if u == target:
        return True

    for v, w in graph[u]:
        if v == pre:
            continue
        if check(v, u, target):
            global min_w
            min_w = min(min_w, w)
            return True
    return False


def solve():
    description.sort(key=lambda item: item[2])
    description.reverse()
    for a, b, g in description:
        find_path(a, -1, b, g)
        find_path(b, -1, a, g)
        if not valid:
            return False
    for a, b, g in description:
        global min_w
        min_w = 1000000
        check(a, -1, b)
        if min_w != g:
            return False
    return True


n = int(sys.stdin.readline())
edges = []
graph = [[] for i in range(n+1)]
description = []
valid = True
min_w = None

for i in range(n-1):
    x, y = list(map(int, sys.stdin.readline().split()))
    edges.append((x, y))
    graph[x].append([y, 1000000])
    graph[y].append([x, 1000000])

m = int(input())
for i in range(m):
    a, b, g = list(map(int, sys.stdin.readline().split()))

    description.append((a, b, g))

if solve():

    for x, y in edges:
        min_w = 1000000
        check(x, -1, y)
        print(min_w, end=' ')
else:
    print('-1')