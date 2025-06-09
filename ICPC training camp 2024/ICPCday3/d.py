import math

def find_min_ratio(n, cities):
    def distance_ratio(x1, y1, x2, y2):
        dm = abs(x1 - x2) + abs(y1 - y2)
        de = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
        return dm / de
    
    cities_sorted_by_x = sorted(cities, key=lambda c: c[0])
    cities_sorted_by_y = sorted(cities, key=lambda c: c[1])
    
    min_ratio = float('inf')
    
    def compare_sorted_cities(sorted_cities):
        nonlocal min_ratio
        for i in range(len(sorted_cities) - 1):
            x1, y1 = sorted_cities[i]
            x2, y2 = sorted_cities[i + 1]
            min_ratio = min(min_ratio, distance_ratio(x1, y1, x2, y2))
    
    compare_sorted_cities(cities_sorted_by_x)
    compare_sorted_cities(cities_sorted_by_y)
    
    return min_ratio

def main():    
    n = int(input())
    
    cities = []
    
    index = 1
    for _ in range(n):
        x,y = list(map(int,input().split()))
        
        cities.append((x, y))
        index += 2
    
    result = find_min_ratio(n, cities)
    print(f"{result:.12f}")


main()
