from collections import defaultdict

def calculate_on_call(schedule):
    on_call_time = defaultdict(int)
    for line in schedule:
        
        start, end, name = line.split()
        
        on_call_time[name] += int(end)-int(start)
        
    return on_call_time


schedule1 = []
schedule2 = []

# Parse the input
while True:
    line = input()
    if line == "------":
        break
    schedule1.append(line)

while True:
    line = input()
    if line == "======":
        break
    schedule2.append(line)

# Calculate on-call time for each teammate
on_call_time1 = calculate_on_call(schedule1)
on_call_time2 = calculate_on_call(schedule2)

# Compare schedules and output differences
differences = []
for name, time1 in on_call_time1.items():
        time2 = on_call_time2.get(name, 0)
        if time1 != time2:
            differences.append((name, time2 - time1))

# Check for differences in the second schedule
for name, time2 in on_call_time2.items():
    if name not in on_call_time1:
        differences.append((name, time2))
    

# Sort the differences alphabetically
differences.sort(key=lambda x: x[0])

# Output the differences
if not differences:
    print("No differences found.")
else:
    for name, diff in differences:
        sign = "+" if diff > 0 else "-"
        print(f"{name} {sign}{abs(diff)}")


