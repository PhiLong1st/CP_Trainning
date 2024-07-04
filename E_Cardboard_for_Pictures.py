def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    numTest = int(data[idx])
    idx += 1
    results = []
    
    for _ in range(numTest):
        n = int(data[idx])
        c = int(data[idx + 1])
        idx += 2
        a = list(map(int, data[idx:idx + n]))
        idx += n
        
        sumBp = sum(x * x for x in a)
        sum_a = sum(a)
        
        ans = 0
        l = 0
        r = 1000000000
        
        while l <= r:
            mid = (l + r) // 2
            if 4 * n * mid * mid == c - sumBp - 4 * sum_a * mid:
                ans = mid
                break
            if 4 * n * mid * mid > c - sumBp - 4 * sum_a * mid:
                r = mid - 1
            else:
                l = mid + 1
        
        results.append(ans)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    solve()
