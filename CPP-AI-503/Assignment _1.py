# Assignment 1: Decision Control Statements
# Submitted by: Shivanshu Shrivastava
# Roll No: 25201341

# Q1: Positive or Negative
num = int(input("Enter a number: "))
if num > 0:
    print("Positive")
elif num < 0:
    print("Negative")
else:
    print("Zero")

# Q2: Even or Odd
num = int(input("Enter an integer: "))
if num % 2 == 0:
    print("Even")
else:
    print("Odd")

# Q3: Largest of Two Numbers
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
if a > b:
    print("Largest number is:", a)
elif b > a:
    print("Largest number is:", b)
else:
    print("Both numbers are equal")

# Q4: Absolute Value (without abs())
num = int(input("Enter a number: "))
if num < 0:   # if number is negative, multiply by -1
    print("Absolute value is:", -num)
else:
    print("Absolute value is:", num)

# Q5: Eligibility for Voting
age = int(input("Enter your age: "))
if age >= 18:   # person can vote only if age >= 18
    print("Eligible to vote")
else:
    print("Not eligible to vote")

# Q6: Leap Year Check
year = int(input("Enter a year: "))
# leap year if divisible by 400 OR (divisible by 4 but not by 100)
if (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0):
    print("Leap Year")
else:
    print("Not a Leap Year")

# Q7: Grade Calculation
marks = int(input("Enter marks: "))
if marks >= 40:
    print("Pass")
else:
    print("Fail")

# Q8: Multiple of 5
num = int(input("Enter a number: "))
if num % 5 == 0:
    print("Multiple of 5")
else:
    print("Not a multiple of 5")

# Q9: Character Case Check
ch = input("Enter a character: ")
if 'A' <= ch <= 'Z':   # ASCII range for uppercase letters
    print("Uppercase letter")
elif 'a' <= ch <= 'z': # ASCII range for lowercase letters
    print("Lowercase letter")
else:
    print("Not a letter")

# Q10: Discount Calculator
amount = float(input("Enter purchase amount: "))
if amount >= 1000:   # apply 10% discount if bill >= 1000
    discount = amount * 0.10
    final_bill = amount - discount
    print("Discount applied. Final bill:", final_bill)
else:
    print("No discount. Final bill:", amount)
