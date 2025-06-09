import math
 

def solve( n) :
   
    if (n<10) :
        return (n*(n+1)/2)
    nbD = (int)(math.log10(n))
    arr = [0] * (nbD + 1)
    arr[0] = 0
    arr[1] = 45
    for i in range(2,nbD+1) :
       arr[i] =arr[i-1] * 10 + 45 * (int)(math.ceil(math.pow(10,i-1)))
    p = (int)(math.ceil(math.pow(10,nbD)))
    msd = n//p
    return (int)(msd *arr[nbD] + (msd*(msd-1) // 2) * p + msd * (1 + n % p) + solve(n % p))
 

t=int(input())
for _ in range(t):
    n = int(input())
    print(int(solve(n)))