#include <stdio.h>

// Q1. Print "Hello, World!"

int main() {
  printf("Hello, World!");
  return 0;
}

// Q2. Swap Two Numbers

int main() {
  int first, second, temp;
  printf("Enter first number: ");
  scanf("%d", &first);
  printf("Enter second number: ");
  scanf("%d", &second);

  temp = first;

  first = second;

  second = temp;

  printf("First number - %d\n", first);
  printf("Second number - %d ", second);

  return 0;
}

// Q3. Check Even or Odd

int main() {
  int token_number;
  printf("Enter Token number: ");
  scanf("%d", &token_number);
  
  if(token_number%2==0){
      printf("Token number is even");
  }else{
    printf("Token number is odd");
  }

  return 0;
}

// Q4. Find Largest of Three Numbers

int main() {
  int a,b,c;
  printf("Enter First number: ");
  scanf("%d", &a);
  printf("Enter Second number: ");
  scanf("%d", &b);
  printf("Enter Third number: ");
  scanf("%d", &c);
  
  if(a>=b && a>=c){
      printf("%d is largest",a);
  }else if(b>=a && b>=c){
    printf("%d is largest",b);
  }else{
      printf("%d is largest",c);
  }

  return 0;
}

// Q5. Simple Calculator (switch case)

int main() {
  int a,b,res;
  char c;
  printf("Enter First number: ");
  scanf("%d", &a);
  printf("Enter Second number: ");
  scanf("%d", &b);
  printf("Enter Expression you want to perform: ");
  scanf(" %c", &c);
  
  switch(c){
    case '+':
             res = a+b;
            printf("%d Addition of no",res);
            break;
    case '-':
             res = a-b;
            printf("%d Subtraction of no",res);
            break;
    case '*':
             res = a*b;
            printf("%d Multiplication of no",res);
            break;
    case '/':
            float ans = (float)a/b;
            printf("%.2f Divide of no",ans);
            break;
    default:
            printf("Entered wrong expresion");
            break;
  }

  return 0;
}

// Q6. Factorial of a Number

int main() {
    int n, i;
    int fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of negative numbers is not defined.\n");
    } else {
        for (i = 1; i <= n; i++) {
            fact = fact * i;
        }
        printf("Factorial of %d = %d\n", n, fact);
    }

    return 0;
}

// Q7. Fibonacci Series (first n terms)

int main() {
    int n, i;
    int t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}

// Q8. Reverse a Number

int main() {
  int n, res = 0;

    printf("Enter the number: ");
    scanf("%d", &n);

    while (n != 0) {
        int mod = n % 10;        
        res = res * 10 + mod;     
        n = n / 10;               
    }

    printf("Reversed number: %d\n", res);
 return 0;
}

// Q9. Palindrome Number Check

int main() {
  int n,a, res = 0;

    printf("Enter the number: ");
    scanf("%d", &n);
    a=n;
    while (n != 0) {
        int mod = n % 10;        
        res = res * 10 + mod;     
        n = n / 10;               
    }
    if(a==res){
        printf("Number is Palindrome");
    }else{
        printf("Number is not Palindrome");
    }
 return 0;
}

// Q10. Count Digits in a Number

int main() {
  int n, res = 0;

    printf("Enter the number: ");
    scanf("%d", &n);
    while (n != 0) {
        int mod = n % 10;        
        res++;    
        n = n / 10;               
    }
    printf("Total number of digits are %d",res);
 return 0;
}

// Q11. Sum of Digits

int main() {
  int n, res = 0;

    printf("Enter the number: ");
    scanf("%d", &n);
    while (n != 0) {
        int mod = n % 10;        
        res+=mod;    
        n = n / 10;               
    }
    printf("Total number of digits are %d",res);
         return 0;
}

// Q12. Check Prime Number

int main() {
  int n, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i <= n ; i++) {
            if (n % i == 0 && n!=i) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a prime number", n);
    else
        printf("%d is not a prime number", n);

    return 0;

}

// Q13. Array – Find Maximum Element

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Maximum element in the array is: %d", max);

    return 0;
}

// Q14. String – Count Vowels

int is_vowel(char ch) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};

    for (int i = 0; i < 10; i++) {
        if (ch == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[100];
    int count = 0;

    printf("Enter a string: ");
    scanf("%s",&str);
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_vowel(str[i])) {
            count++;
        }
    }

    printf("Number of vowels in the string: %d", count);

    return 0;
}

// Q15. Scenario – Electricity Bill Calculation

int main() {
    int units;
    float bill = 0;

    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    if (units <= 100) {
        bill = units * 5;
    } else if (units <= 200) {
        bill = (100 * 5) + ((units - 100) * 7);
    } else {
        bill = (100 * 5) + (100 * 7) + ((units - 200) * 10);
    }

    printf("Electricity Bill: %.2f", bill);

    return 0;
}

// Q16. Factorial using Recursion

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return factorial(n-1)*n;
}

int main() {
  int a,b;
  printf("Enter number: ");
  scanf("%d", &a);
  b=factorial(a);
  printf("Factorial of number is %d",b);
  return 0;
}

// Q17. Fibonacci Series using Recursion

int fibonacci(int n){
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
 return 0;
}

// Q18. GCD (Greatest Common Divisor) using Recursion

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter first integers: ");
    scanf("%d", &num1);
    printf("Enter second integers: ");
    scanf("%d", &num2);

    int result = gcd(num1, num2);
    printf("GCD of %d and %d is: %d", num1, num2, result);

    return 0;
}

// Q19. Sum of Digits using Recursion

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("Sum of digits = %d", result);

    return 0;
}

// Q20. Recursive Binary Search

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // Found
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}










