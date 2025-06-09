import math

def calculate_minimum_damage(x1, y1, r1, d1, t, x2, y2, r2, d2):
    d_start = math.sqrt(x1**2 + y1**2)
    d_end = math.sqrt(x2**2 + y2**2)
    
    t_reach1 = d_start
    
    if t_reach1 <= t:
        total_damage = d1 * t_reach1
    else:
        total_damage = d1 * t
        d_remaining = d_end - t
        total_damage += d2 * d_remaining
    
    return total_damage

x1, y1, r1, d1 = 5, 5, 10, 2
t = 10
x2, y2, r2, d2 = 15, 15, 5, 3

print(calculate_minimum_damage(x1, y1, r1, d1, t, x2, y2, r2, d2))
