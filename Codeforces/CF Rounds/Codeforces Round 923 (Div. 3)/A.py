t= int(input())

for _ in range(t):
    n=int(input())
    s=str(input())
    fb=-1
    lb=-1
    for i in range(n):
        if fb==-1 and s[i]=='B':
            fb=i
        if s[i]=='B':
            lb=i
    print(lb-fb+1)

