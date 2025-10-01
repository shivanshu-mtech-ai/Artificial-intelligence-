import math

# ---------------------------
# Q1) Generate primes < 100 in spiral format
# ---------------------------

def generate_primes(limit=100):
    primes = []
    for num in range(2, limit):
        is_prime = True
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes

def spiral_matrix(values):
    n = math.ceil(math.sqrt(len(values)))  # minimal square size
    matrix = [[0]*n for _ in range(n)]
    top, left = 0, 0
    bottom, right = n-1, n-1
    idx = 0

    while top <= bottom and left <= right and idx < len(values):
        for i in range(left, right+1):  # top row
            if idx < len(values):
                matrix[top][i] = values[idx]
                idx += 1
        top += 1
        for i in range(top, bottom+1):  # right column
            if idx < len(values):
                matrix[i][right] = values[idx]
                idx += 1
        right -= 1
        for i in range(right, left-1, -1):  # bottom row
            if idx < len(values):
                matrix[bottom][i] = values[idx]
                idx += 1
        bottom -= 1
        for i in range(bottom, top-1, -1):  # left column
            if idx < len(values):
                matrix[i][left] = values[idx]
                idx += 1
        left += 1
    return matrix

print("Q1) Prime numbers less than 100 in spiral format:\n")
primes = generate_primes(100)
spiral = spiral_matrix(primes)
for row in spiral:
    print(" ".join([str(x).rjust(2) if x != 0 else " ." for x in row]))
print("\n" + "-"*50 + "\n")

# ---------------------------
# Q2) Text-based graph of hourly views (User Input)
# ---------------------------

print("Q2) Enter hourly views (separated by spaces):")
hourly_views = list(map(int, input().split()))

print("\nText-based graph of hourly views:\n")
for hour, views in enumerate(hourly_views):
    stars = "*" * (views // 5)  # 1 star = 5 views
    print(f"Hour {hour}: {stars} ({views})")
print("\n" + "-"*50 + "\n")

# ---------------------------
# Q3) Revenue calculation
# ---------------------------

def calculate_revenue(hourly_views):
    total_views = sum(hourly_views)
    revenue = 0.0
    if total_views <= 10:
        revenue = total_views * 0.50
    elif total_views <= 30:
        revenue = 10 * 0.50 + (total_views - 10) * 0.30
    else:
        revenue = 10 * 0.50 + 20 * 0.30 + (total_views - 30) * 0.10
    return revenue

print("Q3) Calculate total daily revenue:\n")
print(f"Hourly views: {hourly_views}")
print(f"Total Revenue = ${calculate_revenue(hourly_views):.2f}")
