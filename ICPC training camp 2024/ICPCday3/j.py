import heapq
import sys

def solve():
    
    
    n = int(input())
    marbles = list(map(int,input().split()))
    
    if n == 1:
        print(marbles[0])
        return
    
    heap = []
    
    for i in range(1, n):
        heapq.heappush(heap, (-abs(marbles[i]), i))
    
    result = marbles[0]
    operations = []
    
    while heap:
        _, index = heapq.heappop(heap)
        if index == 1:
            continue
        result -= marbles[index]
        operations.append(index + 1) 
    
    print(result)
    for op in operations:
        print(op)

solve()
