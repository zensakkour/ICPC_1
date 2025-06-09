# Rinput :
n = int(input())
arr = list(map(int, input().split()))

k = int(input())



arr.sort()  
i = 0
while i < k:
    # Read each query: two integers L and R
    L, R = map(int, input().split())
    
    # BS for L
    # Find the first index where arr[index] >= L.
    lw = -1
    hi = n
    while lw + 1 < hi:
        mid = lw + (hi - lw) // 2
        if arr[mid] >= L: # condition is arr[index] >= L so hi keeps track of the last correct one
            hi = mid
        else:
            lw = mid
    l = hi + 1

    # BS for R
    # Find the last index where arr[index] <= R.
    lw = -1
    hi = n
    while lw + 1 < hi:
        mid = lw + (hi - lw) // 2
        if arr[mid] <= R: # arr[index] <= R.
            lw = mid
        else:
            hi = mid
    r = lw + 1

    print(r - l + 1, end=" ")
    i += 1
