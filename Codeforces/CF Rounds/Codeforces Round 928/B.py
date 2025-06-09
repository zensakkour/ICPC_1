t = int(input())

for _ in range(t):
    n = int(input())
    grid = [input() for _ in range(n)]
    
    size=[]
    for row in grid:
        cnt=row.count('1')
        if cnt!=0:
            size.append(cnt)
    
    if all(row==size[0] for row in size):
        print("SQUARE")
    else:
        print("TRIANGLE")
        
