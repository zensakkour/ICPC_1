def BL(i, time, t, z, y):
    period = t[i] * z[i] + y[i]
    return (time // period) * z[i] + min((time % period) // t[i], z[i])

def canBlow(time, m, n, t, z, y):
    cnt = 0
    for i in range(n):
        cnt += BL(i, time, t, z, y)
        if cnt >= m:
            return True
    return False

def main():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    m = int(input_data[0])
    n = int(input_data[1])
    
    t = []
    z = []
    y = []
    index = 2
    for _ in range(n):
        t.append(int(input_data[index]))
        z.append(int(input_data[index+1]))
        y.append(int(input_data[index+2]))
        index += 3

    lo = -1
    hi = m * 300
    while lo + 1 < hi:
        mid = lo + (hi - lo) // 2
        if canBlow(mid, m, n, t, z, y):
            hi = mid
        else:
            lo = mid

    print(hi)
    
    remaining = m
    result = []
    for i in range(n):
        num = BL(i, hi, t, z, y)
        if num > remaining:
            num = remaining
        remaining -= num
        result.append(str(num))
    print(" ".join(result))

if __name__ == "__main__":
    main()
