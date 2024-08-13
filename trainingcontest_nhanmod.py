t = int(input())
for _ in range(t):
    n = int(input())
    print((n * (n + 1) * (n + 2) * (3 * n + 1) // 24) % (10**18 + 3))