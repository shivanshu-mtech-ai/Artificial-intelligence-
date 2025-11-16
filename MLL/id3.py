# ID3 DECISION TREE 

# Import Libraries
import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import matplotlib.pyplot as plt
import seaborn as sns

# Load Dataset
data = load_iris()
X = data.data
y = data.target
feature_names = data.feature_names
class_names = data.target_names

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Create ID3 Model
model = DecisionTreeClassifier(criterion="entropy")  # ID3 uses entropy
model.fit(X_train, y_train)

# Predict
y_pred = model.predict(X_test)

# Evaluation
print("Accuracy:", accuracy_score(y_test, y_pred))

# 1. DECISION TREE VISUALIZATION
plt.figure(figsize=(16,10))
plot_tree(
    model,
    feature_names=feature_names,
    class_names=class_names,
    filled=True,
    rounded=True,
    fontsize=10
)
plt.title("ID3 Decision Tree (Entropy)")
plt.show()
