for t in range(int(input())):
    m, n, k = map(int, input().split())
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    A = set([c for c in list(a) if c<=k])
    B = set([c for c in list(b) if c<=k])
    s = A.union(B)
    if(len(A) >= k/2 and len(B) >= k/2 and len(s) == k):
        print("YES")
    else:
        print("NO")
