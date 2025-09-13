import matplotlib.pyplot as plt

# Daily sales data of a store (in units sold)
daily_sales = [120, 135, 128, 110, 105, 95, 90, 100, 115, 130]

# Function: 2-point average (1st-order smoothing)
def smooth_first(data):
    return [(data[i] + data[i+1]) / 2 for i in range(len(data) - 1)]

# Function: 3-point average on first-order result (2nd-order smoothing)
def smooth_second(data):
    first_pass = smooth_first(data)
    return [(first_pass[j] + first_pass[j+1] + first_pass[j+2]) / 3 for j in range(len(first_pass) - 2)]

# Compute smoothed values
sales_avg1 = smooth_first(daily_sales)
sales_avg2 = smooth_second(daily_sales)

# Print results for verification
print("Original Sales Data:", daily_sales)
print("1st-Order Smoothed:", sales_avg1)
print("2nd-Order Smoothed:", sales_avg2)

# ---- Visualization ----
plt.plot(daily_sales, label='Original Sales', marker='o')
plt.plot(range(1, len(sales_avg1) + 1), sales_avg1, label='1st-Order Avg', marker='s')
plt.plot(range(2, len(sales_avg2) + 2), sales_avg2, label='2nd-Order Avg', marker='^')

# Chart formatting
plt.title('Sales Data Smoothing using Moving Averages')
plt.xlabel('Day')
plt.ylabel('Units Sold')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.savefig('sales_moving_average.png')  # save output image
plt.show()
