# Code by: KoKoDuDu
# Created: 20.10.2024 10:38:27

MOD = int(1e9 + 7)
INF = int(1e18)

def solve():
    n = int(input())
    adj = [[] for _ in range(n + 1)]
    ope = [0] * (n + 1)
    par = [0] * (n + 1)
    num = [0] * (n + 1)

    for i in range(n):
        s = input()
        c = s[-1]  # Last character
        if c == '+':
            ope[i] = 1
        elif c == '-':
            ope[i] = 2
        elif c == '*':
            ope[i] = 3
        elif c == '/':
            ope[i] = 4
        s = s[:-1]  # Remove the last character (operator)
        par[i] = int(s)
        num[i] = int(s)

    vst = [False] * (n + 1)

    def dfs(x, val, path, sz):
        vst[x] = True
        if ope[x] == 1:
            val += num[x]
        elif ope[x] == 2:
            val -= num[x]
        elif ope[x] == 3:
            val *= num[x]
        elif ope[x] == 4:
            if num[x] != 0:
                val //= num[x]  # Integer division

        if not vst[par[x]]:
            sz += 1
            path += f"->{par[x]}"
            dfs(par[x], val, path, sz)

    pl = -1
    maxx = -INF
    min_sz = INF
    best_path = ""

    for i in range(n):
        val = 0
        sz = 0
        path = f"{i}"
        vst = [False] * (n + 1)
        dfs(i, val, path, sz)
        if maxx == val:
            if min_sz > sz:
                best_path = path
                min_sz = sz
                pl = i
        elif maxx < val:
            maxx = val
            best_path = path
            min_sz = sz
            pl = i

    print(pl)
    print(maxx)
    print(best_path)


if __name__ == "__main__":
    t = 1
    while t > 0:
        solve()
        t -= 1
