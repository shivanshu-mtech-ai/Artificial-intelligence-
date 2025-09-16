#include <stdio.h>
#include <string.h>

/* 
============================================================
Assignment: Time and Space Complexity Analysis in C
Submitted by: Shivanshu Shrivastava
Roll No: 25201341
============================================================
*/

/* ==========================================================
   1. Sum of Elements in an Array
   Scenario: You have a list of daily sales of a store.
   ========================================================== */

// Recursive function
int sumRecursive(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1] + sumRecursive(arr, n-1);
}

void problem1() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, sum = 0;

    // Iterative
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("1a) Sum (Iterative) = %d\n", sum);

    // Recursive
    printf("1b) Sum (Recursive) = %d\n", sumRecursive(arr, n));

    /* Expected Output:
       1a) Sum (Iterative) = 150
       1b) Sum (Recursive) = 150
    */
}

/* ==========================================================
   2. Find Maximum Element in an Array
   Scenario: Given temperature readings for a week.
   ========================================================== */

void bubbleSort(int arr[], int n) {
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                int temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;
            }
        }
    }
}

void problem2() {
    int arr[] = {32, 35, 28, 40, 30, 33, 36};
    int n = 7;

    // Linear scan
    int max = arr[0];
    for (int i=1;i<n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    printf("2a) Max (Linear Scan) = %d\n", max);

    // Sort and take last
    bubbleSort(arr, n);
    printf("2b) Max (By Sorting) = %d\n", arr[n-1]);

    /* Expected Output:
       2a) Max (Linear Scan) = 40
       2b) Max (By Sorting) = 40
    */
}

/* ==========================================================
   3. Reverse a String
   Scenario: Reversing a username for encryption.
   ========================================================== */

void problem3() {
    char str1[] = "username";
    int n = strlen(str1);

    // In-place
    int l=0, r=n-1;
    while(l<r) {
        char temp = str1[l];
        str1[l] = str1[r];
        str1[r] = temp;
        l++; r--;
    }
    printf("3a) Reverse In-Place = %s\n", str1);

    // New array
    char str2[] = "username";
    char rev[100];
    n = strlen(str2);
    for (int i=0;i<n;i++) {
        rev[i] = str2[n-1-i];
    }
    rev[n]='\0';
    printf("3b) Reverse New Array = %s\n", rev);

    /* Expected Output:
       3a) Reverse In-Place = emanresu
       3b) Reverse New Array = emanresu
    */
}

/* ==========================================================
   4. Check Even or Odd
   Scenario: Print whether numbers are even or odd.
   ========================================================== */

void problem4() {
    int nums[] = {10, 15, 22, 33};
    int n = 4;

    printf("4a) Using Modulo:\n");
    for (int i=0;i<n;i++) {
        if (nums[i] % 2 == 0) printf("%d Even\n", nums[i]);
        else printf("%d Odd\n", nums[i]);
    }

    printf("4b) Using Bitwise:\n");
    for (int i=0;i<n;i++) {
        if (nums[i] & 1) printf("%d Odd\n", nums[i]);
        else printf("%d Even\n", nums[i]);
    }

    /* Expected Output:
       4a) Using Modulo:
       10 Even
       15 Odd
       22 Even
       33 Odd

       4b) Using Bitwise:
       10 Even
       15 Odd
       22 Even
       33 Odd
    */
}

/* ==========================================================
   5. Factorial of a Number
   Scenario: Calculate possible arrangements.
   ========================================================== */

int factRecursive(int n) {
    if (n==0 || n==1) return 1;
    return n * factRecursive(n-1);
}

void problem5() {
    int n=5, fact=1;

    for (int i=1;i<=n;i++) fact*=i;
    printf("5a) Factorial Iterative = %d\n", fact);

    printf("5b) Factorial Recursive = %d\n", factRecursive(n));

    /* Expected Output:
       5a) Factorial Iterative = 120
       5b) Factorial Recursive = 120
    */
}

/* ==========================================================
   6. Linear Search
   Scenario: Search for a customer ID.
   ========================================================== */

int linearSearch(int arr[], int n, int key) {
    for (int i=0;i<n;i++) if(arr[i]==key) return i;
    return -1;
}

int sentinelSearch(int arr[], int n, int key) {
    int last=arr[n-1];
    arr[n-1]=key;
    int i=0;
    while(arr[i]!=key) i++;
    arr[n-1]=last;
    if (i<n-1 || arr[n-1]==key) return i;
    return -1;
}

void problem6() {
    int arr[]={1,3,5,7,9};
    int n=5, key=7;

    int idx=linearSearch(arr,n,key);
    printf("6a) Linear Search: %d found at index %d\n", key, idx);

    idx=sentinelSearch(arr,n,key);
    printf("6b) Sentinel Search: %d found at index %d\n", key, idx);

    /* Expected Output:
       6a) Linear Search: 7 found at index 3
       6b) Sentinel Search: 7 found at index 3
    */
}

/* ==========================================================
   7. Print First n Natural Numbers
   Scenario: Generate numbers for a report.
   ========================================================== */

void printRecursive(int n) {
    if (n==0) return;
    printRecursive(n-1);
    printf("%d ", n);
}

void problem7() {
    int n=5;

    printf("7a) Iterative: ");
    for(int i=1;i<=n;i++) printf("%d ", i);
    printf("\n");

    printf("7b) Recursive: ");
    printRecursive(n);
    printf("\n");

    /* Expected Output:
       7a) Iterative: 1 2 3 4 5
       7b) Recursive: 1 2 3 4 5
    */
}

/* ==========================================================
   8. Count Vowels in a String
   Scenario: Analyze user comments.
   ========================================================== */

int isVowel(char c) {
    c = (c>='A' && c<='Z') ? c+32 : c;
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

void problem8() {
    char str[]="Hello World";
    int count=0;

    for (int i=0; str[i]; i++) {
        if (isVowel(str[i])) count++;
    }
    printf("8a) Count vowels (traverse) = %d\n", count);

    int lookup[256]={0};
    lookup['a']=lookup['e']=lookup['i']=lookup['o']=lookup['u']=1;
    lookup['A']=lookup['E']=lookup['I']=lookup['O']=lookup['U']=1;
    count=0;
    for (int i=0; str[i]; i++) {
        if (lookup[(int)str[i]]) count++;
    }
    printf("8b) Count vowels (lookup) = %d\n", count);

    /* Expected Output:
       8a) Count vowels (traverse) = 3
       8b) Count vowels (lookup) = 3
    */
}

/* ==========================================================
   9. Swap Two Numbers Without Temp
   Scenario: Embedded systems with memory constraints.
   ========================================================== */

void problem9() {
    int a=5, b=10;

    int x=a, y=b;
    x=x+y; y=x-y; x=x-y;
    printf("9a) Swap Arithmetic: a=%d, b=%d\n", x, y);

    x=a; y=b;
    x=x^y; y=x^y; x=x^y;
    printf("9b) Swap XOR: a=%d, b=%d\n", x, y);

    /* Expected Output:
       9a) Swap Arithmetic: a=10, b=5
       9b) Swap XOR: a=10, b=5
    */
}

/* ==========================================================
   10. Palindrome Number
   Scenario: Validate ID number is symmetric.
   ========================================================== */

int isPalindromeStr(char str[]) {
    int l=0, r=strlen(str)-1;
    while(l<r) {
        if (str[l]!=str[r]) return 0;
        l++; r--;
    }
    return 1;
}

int isPalindromeNum(int n) {
    int rev=0, temp=n;
    while(temp>0) {
        rev=rev*10 + temp%10;
        temp/=10;
    }
    return (rev==n);
}

void problem10() {
    int num=121;
    char str[10];
    sprintf(str,"%d",num);

    printf("10a) Palindrome (String) = %s\n", isPalindromeStr(str)?"Yes":"No");
    printf("10b) Palindrome (Math) = %s\n", isPalindromeNum(num)?"Yes":"No");

    /* Expected Output:
       10a) Palindrome (String) = Yes
       10b) Palindrome (Math) = Yes
    */
}

/* ==========================================================
   Main
   ========================================================== */
int main() {
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    problem6();
    problem7();
    problem8();
    problem9();
    problem10();
    return 0;
}
