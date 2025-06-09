def process_commands(n, m, a, s):
    result = []
    seq=[]
    ls=len(s)
    
    i = 0
    l=n-1
    nt=0
    while  nt<ls:
        if s[nt] == 'L':
            seq.append(a[i])
            i+=1
        else:
            seq.append(a[l])
            l-=1
        nt+=1

    product = 1
    for i in range(ls-1,-1,-1):
        product=(product* seq[i])%m
        result.append(product)
    result.reverse()
    return result
 
def main():
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        a = list(map(int, input().split()))
        s = input()
 
        result=process_commands(n, m, a, s)
        print(*result)
 
if __name__ == "__main__":
    main()