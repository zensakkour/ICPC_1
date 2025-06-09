
t= int(input())
 
for _ in range(t):
    n=int(input())
    A=list(map(int, input().split()))
    Bol=[-1]*n
    for i in range(1,n):
        if A[i]==A[i-1]:
            Bol[i]=Bol[i-1]
        else:
            Bol[i]=i-1
    q=int(input())
    for _ in range(q):
        l,r= map(int, input().split())
        l-=1
        r-=1
        if Bol[r]<l:
            
            print("-1 -1")
        else:
            print(str(r+1)+" "+str(Bol[r]+1))
            
    
    print("")
        
    
    
