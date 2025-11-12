// ===========================================================
// Assignment – 4
// Name: Shivanshu Shrivastava
// ===========================================================

// -----------------------------------------------------------
// Q1) Swap two complex numbers using a struct
// -----------------------------------------------------------
#include <stdio.h>
struct ComplexNumber {
    float realPart;
    float imagPart;
};
void swapComplex(struct ComplexNumber *numA, struct ComplexNumber *numB) {
    struct ComplexNumber tempNum;
    tempNum = *numA;
    *numA = *numB;
    *numB = tempNum;
}
int main() {
    struct ComplexNumber complex1, complex2;
    printf("Enter real and imaginary part of first complex number: ");
    scanf("%f %f", &complex1.realPart, &complex1.imagPart);
    printf("Enter real and imaginary part of second complex number: ");
    scanf("%f %f", &complex2.realPart, &complex2.imagPart);

    printf("\nBefore swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", complex1.realPart, complex1.imagPart);
    printf("Second complex number: %.2f + %.2fi\n", complex2.realPart, complex2.imagPart);

    swapComplex(&complex1, &complex2);

    printf("\nAfter swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", complex1.realPart, complex1.imagPart);
    printf("Second complex number: %.2f + %.2fi\n", complex2.realPart, complex2.imagPart);
    return 0;
}

// -----------------------------------------------------------
// Q2) Store and display info of n employees using array of structures
// -----------------------------------------------------------
#include <stdio.h>
struct EmployeeData {
    int empId;
    char empName[50];
    float empSalary;
};
int main2() {
    int empCount;
    printf("Enter the number of employees: ");
    scanf("%d", &empCount);
    struct EmployeeData employeeList[empCount];

    for (int i = 0; i < empCount; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employeeList[i].empId);
        printf("Name: ");
        scanf(" %[^\n]s", employeeList[i].empName);
        printf("Salary: ");
        scanf("%f", &employeeList[i].empSalary);
    }

    printf("\nEmployee Information:\n");
    printf("ID\tName\t\tSalary\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%d\t%s\t\t%.2f\n", employeeList[i].empId, employeeList[i].empName, employeeList[i].empSalary);
    }
    return 0;
}

// -----------------------------------------------------------
// Q3) Nested structure example – Student with Date of Birth
// -----------------------------------------------------------
#include <stdio.h>
struct DateData {
    int day;
    int month;
    int year;
};
struct StudentDetails {
    int rollNo;
    char studentName[50];
    struct DateData dob;
};
int main3() {
    struct StudentDetails student;
    printf("Enter student roll number: ");
    scanf("%d", &student.rollNo);
    printf("Enter student name: ");
    scanf(" %[^\n]s", student.studentName);
    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &student.dob.day, &student.dob.month, &student.dob.year);
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", student.rollNo);
    printf("Name: %s\n", student.studentName);
    printf("Date of Birth: %02d-%02d-%04d\n", student.dob.day, student.dob.month, student.dob.year);
    return 0;
}

// -----------------------------------------------------------
// Q4) Struct containing pointer to itself example
// -----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
struct NodeData {
    int value;
    struct NodeData *next;
};
int main4() {
    struct NodeData *firstNode = NULL;
    struct NodeData *secondNode = NULL;

    firstNode = (struct NodeData*)malloc(sizeof(struct NodeData));
    secondNode = (struct NodeData*)malloc(sizeof(struct NodeData));

    firstNode->value = 10;
    firstNode->next = secondNode;
    secondNode->value = 20;
    secondNode->next = NULL;

    printf("First node data: %d\n", firstNode->value);
    printf("Second node data: %d\n", firstNode->next->value);
    return 0;
}

// -----------------------------------------------------------
// Q5) Find highest marks among n students
// -----------------------------------------------------------
#include <stdio.h>
struct StudentMarks {
    int rollNo;
    char studentName[50];
    float marks;
};
int main5() {
    int count, i, topIndex = 0;
    printf("Enter number of students: ");
    scanf("%d", &count);
    struct StudentMarks list[count];
    for (i = 0; i < count; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &list[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]s", list[i].studentName);
        printf("Marks: ");
        scanf("%f", &list[i].marks);
    }
    for (i = 1; i < count; i++) {
        if (list[i].marks > list[topIndex].marks)
            topIndex = i;
    }
    printf("\nStudent with Highest Marks:\n");
    printf("Roll Number: %d\n", list[topIndex].rollNo);
    printf("Name: %s\n", list[topIndex].studentName);
    printf("Marks: %.2f\n", list[topIndex].marks);
    return 0;
}

// -----------------------------------------------------------
// Q6) Compare two structures (students)
// -----------------------------------------------------------
#include <stdio.h>
#include <string.h>
struct CompareStudent {
    int rollNo;
    char name[50];
    float marks;
};
int main6() {
    struct CompareStudent s1, s2;
    printf("Enter details of first student:\n");
    printf("Roll Number: ");
    scanf("%d", &s1.rollNo);
    printf("Name: ");
    scanf(" %[^\n]s", s1.name);
    printf("Marks: ");
    scanf("%f", &s1.marks);

    printf("\nEnter details of second student:\n");
    printf("Roll Number: ");
    scanf("%d", &s2.rollNo);
    printf("Name: ");
    scanf(" %[^\n]s", s2.name);
    printf("Marks: ");
    scanf("%f", &s2.marks);

    if (s1.rollNo == s2.rollNo && strcmp(s1.name, s2.name) == 0 && s1.marks == s2.marks)
        printf("Both students have identical details");
    else
        printf("The students are different");
    return 0;
}

// -----------------------------------------------------------
// Q7) Cricket team array – player with highest runs
// -----------------------------------------------------------
#include <stdio.h>
#include <string.h>
struct PlayerData {
    char playerName[50];
    int runs;
    int wickets;
};
int main7() {
    int totalPlayers, i, bestIndex = 0;
    printf("Enter number of players in the team: ");
    scanf("%d", &totalPlayers);
    struct PlayerData team[totalPlayers];
    for (i = 0; i < totalPlayers; i++) {
        printf("\nEnter details of player %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", team[i].playerName);
        printf("Runs: ");
        scanf("%d", &team[i].runs);
        printf("Wickets: ");
        scanf("%d", &team[i].wickets);
    }
    for (i = 1; i < totalPlayers; i++) {
        if (team[i].runs > team[bestIndex].runs)
            bestIndex = i;
    }
    printf("\nPlayer with Highest Runs:\n");
    printf("Name: %s\n", team[bestIndex].playerName);
    printf("Runs: %d\n", team[bestIndex].runs);
    printf("Wickets: %d\n", team[bestIndex].wickets);
    return 0;
}

// -----------------------------------------------------------
// Q8) malloc vs calloc explanation
// -----------------------------------------------------------
#include <stdio.h>
int main8() {
    printf("malloc() gives uninitialized memory.\n");
    printf("calloc() gives zero-initialized memory.\n");
    return 0;
}

// -----------------------------------------------------------
// Q9) Dynamically allocate 2D array inside a structure
// -----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
struct MatrixData {
    int rows;
    int cols;
    int **array;
};
int main9() {
    struct MatrixData mat;
    int i, j;
    printf("Enter number of rows: ");
    scanf("%d", &mat.rows);
    printf("Enter number of columns: ");
    scanf("%d", &mat.cols);

    mat.array = (int**)malloc(mat.rows * sizeof(int*));
    for (i = 0; i < mat.rows; i++)
        mat.array[i] = (int*)malloc(mat.cols * sizeof(int));

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat.array[i][j]);
        }
    }

    printf("\nMatrix Elements:\n");
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("%d ", mat.array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// -----------------------------------------------------------
// Q10) Using realloc to increase number of students
// -----------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
struct DynamicStudent {
    int rollNo;
    char name[50];
    float marks;
};
int main10() {
    struct DynamicStudent *stud;
    int initialCount, extraCount, totalCount, i;

    printf("Enter number of students: ");
    scanf("%d", &initialCount);
    stud = (struct DynamicStudent*)malloc(initialCount * sizeof(struct DynamicStudent));

    printf("\nEnter details of %d students:\n", initialCount);
    for (i = 0; i < initialCount; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &stud[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]s", stud[i].name);
        printf("Marks: ");
        scanf("%f", &stud[i].marks);
    }

    printf("\nEnter number of new students to add: ");
    scanf("%d", &extraCount);
    totalCount = initialCount + extraCount;
    stud = (struct DynamicStudent*)realloc(stud, totalCount * sizeof(struct DynamicStudent));

    printf("\nEnter details of %d new students:\n", extraCount);
    for (i = initialCount; i < totalCount; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &stud[i].rollNo);
        printf("Name: ");
        scanf(" %[^\n]s", stud[i].name);
        printf("Marks: ");
        scanf("%f", &stud[i].marks);
    }

    printf("\nAll Student Details:\n");
    printf("------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------\n");
    for (i = 0; i < totalCount; i++) {
        printf("%-10d %-20s %-10.2f\n", stud[i].rollNo, stud[i].name, stud[i].marks);
    }
    return 0;
}
