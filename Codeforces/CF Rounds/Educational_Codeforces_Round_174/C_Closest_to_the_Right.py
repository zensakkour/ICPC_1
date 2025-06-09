
n, k = map(int, input().split())
arr = list(map(int, input().split()))
req = list(map(int, input().split()))

def lower_bound(a, val, l, r):
    # BS find the first index where a[index] >= val.

    
    while l < r: # arr[l] < val   && arr[r] >= val
        m = l + (r - l) // 2
        if a[m] >= val:
            r = m
        else:
            l = m + 1
    if a[l] >= val:
        return l + 1  # from 0 indexed to 1 indexed
    return n + 1

for q in req:
    print(lower_bound(arr, q, 0, n - 1))
