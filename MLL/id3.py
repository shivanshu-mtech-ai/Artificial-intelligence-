import numpy as np
import pandas as pd

def calc_entropy(labels):
    unique_vals, counts = np.unique(labels, return_counts=True)
    probabilities = counts / len(labels)
    return -np.sum(probabilities * np.log2(probabilities))

def calc_information_gain(dataset, feature_name, target_name):
    parent_entropy = calc_entropy(dataset[target_name])

    feature_values, value_counts = np.unique(dataset[feature_name], return_counts=True)
    weighted_entropy = 0

    for val, count in zip(feature_values, value_counts):
        subset_df = dataset[dataset[feature_name] == val]
        weighted_entropy += (count / len(dataset)) * calc_entropy(subset_df[target_name])

    return parent_entropy - weighted_entropy


def build_id3_tree(dataset, feature_list, target_name):
    # Case 1: All examples have same label
    unique_labels = np.unique(dataset[target_name])
    if len(unique_labels) == 1:
        return unique_labels[0]

    # Case 2: No features left → return majority label
    if len(feature_list) == 0:
        return dataset[target_name].mode()[0]

    # Select best feature
    info_gains = [calc_information_gain(dataset, feat, target_name) for feat in feature_list]
    best_feat = feature_list[np.argmax(info_gains)]

    tree = {best_feat: {}}

    # Build branches
    for val in np.unique(dataset[best_feat]):
        subset_df = dataset[dataset[best_feat] == val]

        if subset_df.empty:
            tree[best_feat][val] = dataset[target_name].mode()[0]
        else:
            remaining_features = [f for f in feature_list if f != best_feat]
            tree[best_feat][val] = build_id3_tree(subset_df, remaining_features, target_name)

    return tree

# Example Dataset (Play Tennis)
sample_data = {
    'Outlook': ['Sunny','Sunny','Overcast','Rain','Rain','Rain','Overcast','Sunny'],
    'Temperature': ['Hot','Hot','Hot','Mild','Cool','Cool','Mild','Mild'],
    'Humidity': ['High','High','High','High','Normal','Normal','Normal','High'],
    'Wind': ['Weak','Strong','Weak','Weak','Weak','Strong','Strong','Strong'],
    'Play': ['No','No','Yes','Yes','Yes','No','Yes','No']
}

df_tennis = pd.DataFrame(sample_data)

feature_columns = ['Outlook','Temperature','Humidity','Wind']
target_column = 'Play'

# Build Decision Tree
id3_tree = build_id3_tree(df_tennis, feature_columns, target_column)

print("Decision Tree (ID3):")
print(id3_tree)
