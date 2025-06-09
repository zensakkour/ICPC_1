

t = int(input())  # Number of test cases

for _ in range(t):
    n, k = map(int, input().split())  # n: number of cards, k: position of the card to output

    # Calculate the position of the card in the current sequence
    position = 1
    while k > (position * (position + 1)) // 2:
        position += 1

    # Calculate the actual value of the card
    value = 2 * (k - (position - 1) * position // 2)

    # If the position is odd, subtract one to get the correct value
    if position % 2 == 1:
        value -= 1

    print(value)
