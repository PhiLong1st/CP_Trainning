MOD = 10**9 + 7

def lt(a, b, mod):
    res = 1
    while b > 0:
        if b % 2 == 1:
            res = res * a % mod
        a = a * a % mod
        b //= 2
    return res

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    total_sum = sum(a)
    res = 0

    for i in range(n):
        total_sum -= a[i]
        res += a[i] * total_sum
        res %= MOD

    denominator = n * (n - 1) // 2
    result = res * lt(denominator, MOD - 2, MOD) % MOD
    print(result)
