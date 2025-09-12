# AI-523 Python Programming Laboratory
# Assignment No 1
# Date of Assignment: 05/09/2025
# Due Date: 12/09/2025
# Max Marks: 05
# Submitted by: Shivanshu Shrivastava
# Roll No: 25201341

# -----------------------------
# Q1) Sort list of tuples by last element
# -----------------------------

tuple_list = [(2, 5), (1, 2), (4, 4), (2, 3), (2, 1)]

# Sorting using lambda to access last element
sorted_list = sorted(tuple_list, key=lambda x: x[-1])
print("Q1) Sorted List by last element:", sorted_list)


# -----------------------------
# Q2) Replace all occurrences of first char with '$'
# -----------------------------

def change_string(s):
    first_char = s[0]
    # Replace all occurrences of first character except the first one
    return first_char + s[1:].replace(first_char, '$')

sample_str = "restart"
print("Q2) Modified String:", change_string(sample_str))


# -----------------------------
# Q3) Replace 'not'...'poor' with 'good'
# -----------------------------

def replace_not_poor(sentence):
    not_pos = sentence.find('not')
    poor_pos = sentence.find('poor')

    # Check if 'poor' follows 'not'
    if not_pos != -1 and poor_pos != -1 and poor_pos > not_pos:
        return sentence[:not_pos] + 'good' + sentence[poor_pos+4:]
    return sentence

sample_sentence = "The lyrics is not that poor!"
print("Q3) Resulting String:", replace_not_poor(sample_sentence))


# -----------------------------
# Q4) Sort dictionary by value
# -----------------------------

sample_dict = {'apple': 10, 'banana': 5, 'cherry': 20}

# Sorting dictionary by values
sorted_dict = dict(sorted(sample_dict.items(), key=lambda item: item[1]))
print("Q4) Dictionary sorted by value:", sorted_dict)


# -----------------------------
# Q5) Add key to dictionary
# -----------------------------

my_dict = {1: 'A', 2: 'B'}
print("Original Dictionary:", my_dict)

# Adding a new key-value pair
my_dict[3] = 'C'
print("Q5) Updated Dictionary:", my_dict)
