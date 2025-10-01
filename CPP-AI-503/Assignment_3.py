## --- Original Q1: Prime Numbers in a Clockwise Spiral ---

import math

# Utility function to check if a natural number is a prime number
def check_primality(integer_val):
    if integer_val < 2:
        return False
    # Only check divisibility up to the square root
    for divisor in range(2, int(math.isqrt(integer_val)) + 1):
        if integer_val % divisor == 0:
            return False
    return True

# 1. Collect all prime numbers strictly less than the boundary (100)
prime_collection = [k for k in range(2, 100) if check_primality(k)]

# 2. Determine the side length for the smallest square grid
count_primes = len(prime_collection)
grid_size = 1
while grid_size * grid_size < count_primes:
    grid_size += 1

# 3. Initialize the square grid (matrix) with zeros
prime_grid = [[0] * grid_size for _ in range(grid_size)]

# Define boundaries for the spiral traversal
top_bound, bottom_bound = 0, grid_size - 1
left_bound, right_bound = 0, grid_size - 1
prime_index = 0

# 4. Populate the grid in a clockwise spiral pattern
while top_bound <= bottom_bound and left_bound <= right_bound:
    
    # 4a. Traverse East (left_bound to right_bound) along the top_bound
    for col_idx in range(left_bound, right_bound + 1):
        if prime_index < count_primes:
            prime_grid[top_bound][col_idx] = prime_collection[prime_index]
            prime_index += 1
    top_bound += 1 # Shrink the top boundary
    
    # 4b. Traverse South (top_bound to bottom_bound) along the right_bound
    for row_idx in range(top_bound, bottom_bound + 1):
        if prime_index < count_primes:
            prime_grid[row_idx][right_bound] = prime_collection[prime_index]
            prime_index += 1
    right_bound -= 1 # Shrink the right boundary
    
    # Check if boundaries still valid (to prevent double-filling the center)
    if top_bound <= bottom_bound and left_bound <= right_bound:
        
        # 4c. Traverse West (right_bound down to left_bound) along the bottom_bound
        for col_idx in range(right_bound, left_bound - 1, -1):
            if prime_index < count_primes:
                prime_grid[bottom_bound][col_idx] = prime_collection[prime_index]
                prime_index += 1
        bottom_bound -= 1 # Shrink the bottom boundary
        
        # 4d. Traverse North (bottom_bound down to top_bound) along the left_bound
        for row_idx in range(bottom_bound, top_bound - 1, -1):
            if prime_index < count_primes:
                prime_grid[row_idx][left_bound] = prime_collection[prime_index]
                prime_index += 1
        left_bound += 1 # Shrink the left boundary

# 5. Output the result in the specified format
for row_data in prime_grid:
    # Format each number to 3 spaces wide for alignment; use spaces for 0 (unfilled)
    output_line = " ".join(f"{num:3}" if num != 0 else "   " for num in row_data)
    print(output_line)

print("-" * 30)

## --- Original Q2: Text-Based Hourly Views Graph ---

# Sample data representing video interactions per hour
interaction_counts = [12, 25, 7, 30, 18, 22, 10, 40, 28, 15, 35, 50, 45, 38, 20, 27, 32, 18, 10, 5, 12, 8, 15, 20]
VIEWS_PER_STAR = 5 # Defines the scale factor for the visualization

print("Streaming Platform Hourly Traffic Report (Each '*' = {} interactions)\n".format(VIEWS_PER_STAR))

# Iterate over the 24 hours (0 to 23) and the corresponding interaction data
for hour_slot, total_interactions in enumerate(interaction_counts):
    # Calculate the number of star symbols needed (integer division by the scale factor)
    visual_stars = '*' * (total_interactions // VIEWS_PER_STAR)
    
    # Print the formatted time slot, the star-graph, and the raw number
    print(f"{hour_slot:02d}:00 | {visual_stars} ({total_interactions})")

print("-" * 30)

## --- Original Q3: Total Daily Revenue Calculation ---

# Daily interaction data (24 hours) for revenue calculation
hourly_interaction_data = [12, 25, 7, 30, 18, 22, 10, 40, 28, 15, 35, 50, 45, 38, 20, 27, 32, 18, 10, 5, 12, 8, 15, 20]

# Revenue tiers and rates
TIER1_COUNT = 10  # Max views for Tier 1
TIER1_RATE = 0.50 # Rate for first 10 views
TIER2_COUNT = 20  # Max views for Tier 2 (from 11 to 30)
TIER2_RATE = 0.30 # Rate for next 20 views
TIER3_RATE = 0.10 # Rate for all remaining views

total_daily_earnings = 0.0

# Process each hour's interactions to calculate cumulative revenue
for hourly_count in hourly_interaction_data:
    current_hour_revenue = 0
    
    # Case 1: All views fall within the first tier (up to 10)
    if hourly_count <= TIER1_COUNT:
        current_hour_revenue = hourly_count * TIER1_RATE
    
    # Case 2: Views exceed Tier 1 but not Tier 2 (11 to 30)
    elif hourly_count <= (TIER1_COUNT + TIER2_COUNT):
        # Revenue from Tier 1 (full)
        current_hour_revenue += TIER1_COUNT * TIER1_RATE
        # Revenue from remaining views in Tier 2
        remaining_views_t2 = hourly_count - TIER1_COUNT
        current_hour_revenue += remaining_views_t2 * TIER2_RATE
    
    # Case 3: Views exceed both Tier 1 and Tier 2 (over 30)
    else:
        # Revenue from Tier 1 (full)
        current_hour_revenue += TIER1_COUNT * TIER1_RATE
        # Revenue from Tier 2 (full)
        current_hour_revenue += TIER2_COUNT * TIER2_RATE
        # Revenue from remaining views in Tier 3
        remaining_views_t3 = hourly_count - (TIER1_COUNT + TIER2_COUNT)
        current_hour_revenue += remaining_views_t3 * TIER3_RATE
        
    total_daily_earnings += current_hour_revenue

# Output the final accumulated revenue, formatted to two decimal places
print(f"Total daily revenue: ${total_daily_earnings:.2f}")
