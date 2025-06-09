def max_histogram_area(histogram):
    n = len(histogram)
    max_areas = [0] * n
    stack = []

    for i in range(n):
        while stack and histogram[stack[-1]] > histogram[i]:
            height = histogram[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_areas[i-1] = max(max_areas[i-1], height * width)
        
        stack.append(i)
        max_areas[i] = max(max_areas[i-1], histogram[stack[-1]] * (i + 1))

    return max_areas

n = int(input())
histogram = list(map(int, input().split()))

result = max_histogram_area(histogram)


print(" ".join(map(str, result)))
