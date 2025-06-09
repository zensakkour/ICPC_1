def max_coins(path_length, path):
    if path[0]=='*':
        return 0
    cnt=0
    res=0
    i=0
    while i<path_length and cnt<2:
        res+=int(path[i] == '@')
        
        if path[i]=='*':
            cnt+=1
        else:
            cnt=0
        i+=1

    return res
# def max_coins(path_length, path):
#     if path[0]=='*':
#             return 0
#     if path_length==1:
#         return int(path[0] == '@')
#     if path_length==2:
#         return int(path[0] == '@')+int(path[1] == '@')
#     max_coins_at_cell = [0] * path_length
#     max_coins_at_cell[0] = int(path[0] == '@')
#     max_coins_at_cell[1] = max_coins_at_cell[0] + int(path[1] == '@')

#     cnt = 0
#     for i in range(2, path_length):
#         current_cell_coin = int(path[i] == '@')

#         if path[i] != '*':
#             max_coins_at_cell[i] = max(max_coins_at_cell[i - 1], max_coins_at_cell[i - 2]) + current_cell_coin
#             cnt=0
#         else:
#             max_coins_at_cell[i] = 0
#             cnt += 1
#             if cnt >= 2:
#                 break

#     return max(max_coins_at_cell)

t = int(input())

for _ in range(t):
    n = int(input())
    path = input().strip()
    result = max_coins(n, path)
    print(result)