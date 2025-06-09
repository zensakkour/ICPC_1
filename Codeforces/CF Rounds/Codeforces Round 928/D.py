from collections import Counter
from collections import defaultdict

def solve_test_case(n, numbers):
    cnt = defaultdict(int)
    res=0
    d= (1<<31)-1
    numbers.sort()
    for nb in numbers:
        inv=d^nb
        if cnt[inv]>0:
            cnt[inv]-=1 
        else:
            cnt[nb]+=1
            res+=1           
    return res
  



    
if __name__ == "__main__":
    t = int(input())
    test_cases = []
    r=0
    for _ in range(t):
        n = int(input())
        numbers = list(map(int, input().split()))
        print(solve_test_case(n, numbers))