t = int(input())

for case in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    odd_numbers = 0
    for item in a:
        if item % 2 == 1:
            odd_numbers += 1
    even_numbers = n-odd_numbers

    if odd_numbers == 0:
        print('NO')
        continue

    if odd_numbers % 2 == 1:
        print('YES')
    else:
        if even_numbers > 0:
            print('YES')
        else:
            print('NO')