from collections import Counter

def min_operations_to_fix_diagonals(grid):
    operations = 0
    S=[]
    for i in range(1, 6):
        for j in range(1, 6):
            if grid[i][j] == 'B' and all(grid[i + di][j + dj] == 'B' for di, dj in [(-1, -1), (-1, 1), (1, -1), (1, 1)]):
                tmp=set()
                for di, dj in [(-1, -1), (-1, 1), (1, -1), (1, 1),(0, 0)]:
                    tmp.add((i+di,j+dj))
                S.append(tmp)

    all_elements = [element for subset in S for element in subset]
    element_counts = Counter(all_elements)
    sorted_elements = [element for element, count in element_counts.most_common()]
    # print(sorted_elements)
    i=0
    
    while i<len(sorted_elements):
        if S=={}:
            break
        init=len(S)
        S=[s for s in S if sorted_elements[i] not in s]
        aft=len(S)
        if init!=aft:
            operations+=1
        i+=1
    
    return operations + len(S)

def main():
    t = int(input())
    for _ in range(t):
        grid = [list(input().strip()) for _ in range(7)]
        operations = min_operations_to_fix_diagonals(grid)
        print(operations)

if __name__ == "__main__":
    main()
