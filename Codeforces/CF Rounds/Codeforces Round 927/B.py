def apocalypse_year(n, signs):
    year = 1
    for sign in signs:
        year = max(year, sign)
        if year<=sign:
            year=sign
        year += (sign - year % sign) % sign
        year+=1
    return year

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        signs = list(map(int, input().split()))
        result = apocalypse_year(n, signs)
        print(result-1)

if __name__ == "__main__":
    main()
