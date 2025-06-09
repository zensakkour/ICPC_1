t= int(input())

for _ in range(t):
    n=int(input())
    arr=input().rstrip().split()
    used=dict()
    s=""
    A="abcdefghijklmnopqrstuvwxyz"
    for a in A:
        used[a]=0
    for i in range(n):        
        for c,f in used.items():
            # print(str(f)+"  "+str(arr[i]))
            if int(f)==int(arr[i]):
                used[c]+=1
                s+=c
                # print(c)
                break

    print((s))
