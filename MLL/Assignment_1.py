# linear_regression.py

# Input data
X = [0, 1, 2, 3, 3, 5, 5, 5, 6, 7, 7, 10]
Y = [96, 85, 82, 74, 95, 68, 76, 84, 58, 65, 75, 50]

# Calculate means
mean_x = sum(X) / len(X)
mean_y = sum(Y) / len(Y)
print(f"Mean of X: {mean_x}")
print(f"Mean of Y: {mean_y}")

# Calculate slope (m)
numerator = 0
denominator = 0
for i in range(len(X)):
    numerator += (X[i] - mean_x) * (Y[i] - mean_y)
    denominator += (X[i] - mean_x) ** 2

m = numerator / denominator
print(f"Slope (m): {m}")

# Calculate intercept (c)
c = mean_y - m * mean_x
print(f"Y-intercept (c): {c}")

# Define prediction function
def predict_y(x, m, c):
    """Predicts the Y value for a given X, slope, and intercept."""
    return m * x + c

# Predict for x = 9
predicted_y_at_9 = predict_y(x=9, m=m, c=c)
print(f"Predicted Y value for X=9: {predicted_y_at_9}")

# Display results
print(f"Calculated Slope (m): {m}")
print(f"Calculated Intercept (c): {c}")
print(f"Predicted Y for X=9: {predicted_y_at_9}")

# Interactive prediction
try:
    user_x = float(input("Enter an X value to predict Y: "))
    predicted_y_for_user_x = predict_y(x=user_x, m=m, c=c)
    print(f"Predicted Y value for X={user_x}: {predicted_y_for_user_x}")
except ValueError:
    print("Invalid input. Please enter a number.")
