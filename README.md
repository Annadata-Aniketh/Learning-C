# C Programming - Complete Notes
> Based on Bro Code's C Programming Full Course  
> Reference notes covering all topics in the course

---

## Table of Contents

1. [First Program](#1-first-program)
2. [Variables](#2-variables)
3. [Format Specifiers](#3-format-specifiers)
4. [Arithmetic Operators](#4-arithmetic-operators)
5. [User Input](#5-user-input)
6. [Math Functions](#6-math-functions)
7. [If Statements](#7-if-statements)
8. [Switch Statements](#8-switch-statements)
9. [Nested If Statements](#9-nested-if-statements)
10. [Logical Operators](#10-logical-operators)
11. [Functions](#11-functions)
12. [Return Statement](#12-return-statement)
13. [Variable Scope](#13-variable-scope)
14. [Function Prototypes](#14-function-prototypes)
15. [While Loops](#15-while-loops)
16. [For Loops](#16-for-loops)
17. [Break and Continue](#17-break-and-continue)
18. [Nested Loops](#18-nested-loops)
19. [Random Numbers](#19-random-numbers)
20. [Arrays](#20-arrays)
21. [Arrays and User Input](#21-arrays-and-user-input)
22. [2D Arrays](#22-2d-arrays)
23. [Arrays of Strings](#23-arrays-of-strings)
24. [Ternary Operator](#24-ternary-operator)
25. [Typedef](#25-typedef)
26. [Enums](#26-enums)
27. [Structs](#27-structs)
28. [Arrays of Structs](#28-arrays-of-structs)
29. [Pointers](#29-pointers)
30. [File I/O - Write](#30-file-io---write)
31. [File I/O - Read](#31-file-io---read)
32. [Dynamic Memory - malloc](#32-dynamic-memory---malloc)
33. [Dynamic Memory - calloc](#33-dynamic-memory---calloc)
34. [Dynamic Memory - realloc](#34-dynamic-memory---realloc)

---

## 1. First Program

### Structure of a C Program

Every C program needs two things:
- An **IDE** (e.g., VS Code) - where you write the code
- A **C Compiler** (e.g., GCC, Clang) - converts code to machine code

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### Key Points

- `#include <stdio.h>` - preprocessor directive that includes the standard input/output library; required to use `printf` and `scanf`
- `int main()` - entry point of every C program; without it, the program will not run
- `return 0;` - the `main` function returns an integer to the OS as an exit code; `0` means success, non-zero means error
  - In older standards (C89/C90), omitting this causes undefined behavior; good practice to always include it
- Every statement ends with a **semicolon** `;` (similar to a period at the end of a sentence)
- `\n` inside a string is the **newline character** - moves output to the next line

### Comments

```c
// This is a single-line comment

/* This is a
   multi-line comment */
```

- Comments do not execute; they are notes for the developer
- Single-line: `//`
- Multi-line: `/* ... */`

---

## 2. Variables

A **variable** is a reusable container for a value. It behaves as if it were the value it contains.

### Data Types

| Data Type | Description | Size | Format Specifier | Example |
|-----------|-------------|------|-----------------|---------|
| `int` | Whole numbers | 4 bytes | `%d` | `int age = 25;` |
| `float` | Decimal (single precision) | 4 bytes | `%f` | `float price = 19.99;` |
| `double` | Decimal (double precision) | 8 bytes | `%lf` | `double pi = 3.14159;` |
| `char` | Single character | 1 byte | `%c` | `char grade = 'A';` |
| `char[]` | Array of characters (string) | varies | `%s` | `char name[] = "Aniketh";` |
| `bool` | True or false | 1 byte | `%d` | `bool isOnline = true;` |

### Notes on Each Type

**int**
- Stores whole numbers only; decimal portion is truncated if you try to store `25.5`

**float**
- Displays 6 decimal digits by default
- Use `.2f` precision modifier for currency (e.g., `%.2f`)

**double**
- Stores 15-16 digits after decimal; use when high precision is needed (e.g., pi, Euler's number)
- Use `%lf` for both input and output for consistency

**char**
- Single characters use **single quotes** `'A'`
- Strings (char arrays) use **double quotes** `"hello"`

**bool**
- Requires header: `#include <stdbool.h>`
- `true` = 1, `false` = 0
- Typically used internally with `if` statements, not printed directly

### Declaration Examples

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    int age = 25;
    float gpa = 3.5;
    double pi = 3.14159265358979;
    char grade = 'A';
    char name[] = "Aniketh";
    bool isStudent = true;

    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Pi: %.15lf\n", pi);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);
    printf("Is Student: %d\n", isStudent);

    return 0;
}
```

---

## 3. Format Specifiers

Format specifiers are tokens starting with `%` followed by a character representing the data type. They also support optional modifiers for width, precision, and flags.

### Common Format Specifiers

| Specifier | Data Type |
|-----------|-----------|
| `%d` | int (decimal) |
| `%f` | float |
| `%lf` | double |
| `%c` | char |
| `%s` | string (char array) |

### Modifiers

**Width** - minimum number of characters to print (right-justified by default):
```c
printf("%5d\n", 1);     // "    1"
printf("%5d\n", 10);    // "   10"
printf("%5d\n", 100);   // "  100"
```

**Left-justify** with `-`:
```c
printf("%-5d|\n", 1);   // "1    |"
```

**Leading zeros** with `0`:
```c
printf("%05d\n", 1);    // "00001"
```

**Show sign** with `+`:
```c
printf("%+d\n", 42);    // "+42"
printf("%+d\n", -42);   // "-42"
```

**Precision** (number of decimal digits):
```c
printf("%.2f\n", 19.99);   // "19.99"
printf("%.1f\n", 19.99);   // "20.0"  (rounded)
```

**Combining modifiers** (width + precision + flags):
```c
printf("%+7.2f\n", 19.99);   // "  +19.99"
```

---

## 4. Arithmetic Operators

```c
int x = 10, y = 3, z;

z = x + y;   // Addition:       13
z = x - y;   // Subtraction:    7
z = x * y;   // Multiplication: 30
z = x / y;   // Division:       3  (integer division, decimal truncated)
z = x % y;   // Modulus:        1  (remainder of 10 / 3)
```

### Integer Division Warning

When both operands are integers, the result is also an integer and the decimal portion is dropped:
```c
int result = 2 / 3;   // result = 0, NOT 0.666...
```

To retain the decimal, at least one operand must be a float:
```c
float result = 2 / 3.0;   // result = 0.666...
```

### Modulus Operator

- Gives the **remainder** of division
- `10 % 3 = 1` because 10 = (3 * 3) + 1
- `10 % 2 = 0` because 10 divides evenly by 2
- Useful for checking even/odd: `n % 2 == 0` means even

---

## 5. User Input

Use `scanf()` to read input from the keyboard.

```c
#include <stdio.h>

int main() {
    int age;
    float height;
    char name[25];

    printf("Enter your name: ");
    scanf("%s", name);          // no & needed for strings/arrays

    printf("Enter your age: ");
    scanf("%d", &age);          // & is the address-of operator

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Hello %s! You are %d years old and %.2f cm tall.\n", name, age, height);
    return 0;
}
```

### Key Points

- `&` (address-of operator) is required for non-array variables in `scanf`; it passes the memory address so `scanf` can write to it
- For strings (`char[]`), the array name itself is already an address, so `&` is NOT needed
- `scanf` stops reading a string at whitespace; to read a full line with spaces, use `fgets()`

```c
// Reading a full line (including spaces)
char fullName[50];
printf("Enter full name: ");
fgets(fullName, 50, stdin);
```

---

## 6. Math Functions

Requires `#include <math.h>` and link with `-lm` flag when compiling on Linux.

```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("%f\n", sqrt(25));       // Square root: 5.0
    printf("%f\n", pow(2, 10));     // Power: 1024.0
    printf("%f\n", round(3.6));     // Round: 4.0
    printf("%f\n", ceil(3.2));      // Ceiling (round up): 4.0
    printf("%f\n", floor(3.9));     // Floor (round down): 3.0
    printf("%f\n", fabs(-10.5));    // Absolute value: 10.5
    printf("%f\n", log(M_E));       // Natural log: 1.0
    printf("%f\n", sin(M_PI / 2));  // Sine: 1.0
    return 0;
}
```

### Compile with Math Library

```bash
gcc main.c -o main -lm
```

---

## 7. If Statements

Used for conditional execution - run code only if a condition is true.

```c
if (condition) {
    // runs if condition is true
} else if (another_condition) {
    // runs if first was false and this is true
} else {
    // runs if all conditions above were false
}
```

### Relational Operators

| Operator | Meaning |
|----------|---------|
| `==` | Equal to |
| `!=` | Not equal to |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |

### Example

```c
int age = 18;

if (age >= 18) {
    printf("You are an adult.\n");
} else if (age >= 13) {
    printf("You are a teenager.\n");
} else {
    printf("You are a child.\n");
}
```

---

## 8. Switch Statements

A cleaner alternative to long if-else chains when checking one variable against many fixed values.

```c
int day = 3;

switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    default:
        printf("Invalid day\n");
}
```

### Key Points

- `break` exits the switch block; without it, execution **falls through** to the next case
- `default` is optional; runs if no case matches
- Works with `int` and `char` values, not `float` or `string`
- Multiple cases can share the same code block (fall-through used intentionally):

```c
switch (month) {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        printf("31 days\n");
        break;
    case 4: case 6: case 9: case 11:
        printf("30 days\n");
        break;
    case 2:
        printf("28 or 29 days\n");
        break;
}
```

---

## 9. Nested If Statements

If statements inside other if statements. Used when multiple conditions must all be evaluated.

```c
int temperature = 35;
int isSunny = 1;

if (temperature > 30) {
    if (isSunny) {
        printf("It is hot and sunny.\n");
    } else {
        printf("It is hot but cloudy.\n");
    }
} else {
    printf("The weather is mild.\n");
}
```

- Keep nesting shallow (ideally no more than 2-3 levels deep) for readability
- Can often be replaced by logical operators (`&&`, `||`) for simpler cases

---

## 10. Logical Operators

Combine multiple conditions in one expression.

| Operator | Name | Meaning |
|----------|------|---------|
| `&&` | AND | Both conditions must be true |
| `\|\|` | OR | At least one condition must be true |
| `!` | NOT | Inverts the boolean value |

```c
int age = 25;
int hasID = 1;

// AND: both must be true
if (age >= 18 && hasID) {
    printf("Entry allowed.\n");
}

// OR: at least one true
if (age < 18 || !hasID) {
    printf("Entry denied.\n");
}

// NOT: inverts condition
if (!hasID) {
    printf("Please show your ID.\n");
}
```

### Short-Circuit Evaluation

- `&&`: if the left side is false, the right side is NOT evaluated
- `||`: if the left side is true, the right side is NOT evaluated

---

## 11. Functions

A **function** is a reusable block of code that performs a specific task. Functions reduce repetition and improve organization.

```c
// Function definition
// return_type function_name(parameter_type parameter_name) { ... }

void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int add(int a, int b) {
    return a + b;
}

int main() {
    greet("Aniketh");           // Output: Hello, Aniketh!
    int result = add(3, 5);
    printf("Sum: %d\n", result); // Output: Sum: 8
    return 0;
}
```

### Key Points

- `void` means the function returns nothing
- Parameters are local copies; modifying them does not affect the original variable (pass by value)
- Functions must be defined or declared (prototype) before they are called

---

## 12. Return Statement

The `return` keyword sends a value back to the caller and immediately exits the function.

```c
double square(double x) {
    return x * x;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    printf("%.1f\n", square(4.0));    // 16.0
    printf("%d\n", max(10, 25));      // 25
    return 0;
}
```

- The return type in the function signature must match what is returned
- A `void` function can use `return;` (no value) to exit early
- `main` returns `0` for success, non-zero for error (this value goes to the OS)

---

## 13. Variable Scope

**Scope** refers to where a variable is accessible in the code.

### Local Variables

Declared inside a function or block `{ }`. Only accessible within that block.

```c
void myFunction() {
    int x = 10;   // local to myFunction
    printf("%d\n", x);
}
// x is NOT accessible here
```

### Global Variables

Declared outside all functions. Accessible everywhere in the file.

```c
int count = 0;   // global variable

void increment() {
    count++;     // accessible here
}

int main() {
    increment();
    printf("%d\n", count);   // also accessible here
    return 0;
}
```

### Key Rules

- Local variables shadow global ones if they share the same name
- Prefer local variables; avoid global variables where possible for cleaner, safer code
- Variables declared inside a `for` loop are local to that loop

---

## 14. Function Prototypes

A **prototype** (also called a forward declaration) tells the compiler about a function's signature before the full definition appears. This allows the function to be defined after `main`.

```c
#include <stdio.h>

// Prototypes declared at the top
void greet(char name[]);
int multiply(int a, int b);

int main() {
    greet("Aniketh");
    printf("%d\n", multiply(3, 4));
    return 0;
}

// Actual definitions below main
void greet(char name[]) {
    printf("Hello, %s!\n", name);
}

int multiply(int a, int b) {
    return a * b;
}
```

- Without prototypes, the compiler may give warnings or errors if a function is called before its definition
- Header files (`.h`) are essentially collections of prototypes

---

## 15. While Loops

Repeats a block of code as long as a condition is true.

```c
int i = 1;
while (i <= 5) {
    printf("%d\n", i);
    i++;       // increment to avoid infinite loop
}
```

### Do-While Loop

Always executes the body at least once, then checks the condition.

```c
int choice;
do {
    printf("Enter a number (0 to quit): ");
    scanf("%d", &choice);
    printf("You entered: %d\n", choice);
} while (choice != 0);
```

- Use `while` when the loop may run 0 or more times
- Use `do-while` when the loop must run at least once (e.g., menu prompts)

---

## 16. For Loops

Best when the number of iterations is known in advance.

```c
// for (initialization; condition; update)
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

### Comparison: while vs for

```c
// These are equivalent:

int i = 0;
while (i < 5) { printf("%d\n", i); i++; }

for (int i = 0; i < 5; i++) { printf("%d\n", i); }
```

- `for` is preferred when the loop counter is well-defined
- `while` is preferred when the number of iterations is unknown

---

## 17. Break and Continue

### break

Immediately exits the **entire** loop.

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    printf("%d ", i);
}
// Output: 0 1 2 3 4
```

### continue

Skips the **current iteration** and jumps to the next one.

```c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;
    printf("%d ", i);
}
// Output: 1 3 5 7 9
```

---

## 18. Nested Loops

A loop inside another loop. Commonly used for 2D structures (grids, matrices).

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("%d ", i * j);
    }
    printf("\n");
}
```

Output:
```
1 2 3
2 4 6
3 6 9
```

- The inner loop completes all its iterations for every single iteration of the outer loop
- Total iterations = (outer iterations) x (inner iterations)
- `break` inside a nested loop only breaks the **innermost** loop

---

## 19. Random Numbers

Requires `#include <stdlib.h>` and `#include <time.h>`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   // seed the random number generator with current time

    // rand() % N gives a number from 0 to N-1
    // To get range [min, max]: (rand() % (max - min + 1)) + min
    int num = (rand() % 6) + 1;   // dice roll: 1 to 6
    printf("Dice: %d\n", num);
    return 0;
}
```

### Key Points

- `srand(time(NULL))` seeds the generator so results differ each run; call **once** at the start
- Without seeding, `rand()` gives the same sequence every run
- `rand() % N` gives a value from `0` to `N-1`
- For `[min, max]`: `(rand() % (max - min + 1)) + min`

---

## 20. Arrays

An **array** is a collection of elements of the same data type stored in contiguous memory, accessed by index.

```c
// Declaration and initialization
int scores[5] = {90, 85, 78, 92, 88};

// Access by index (0-based)
printf("%d\n", scores[0]);   // 90
printf("%d\n", scores[4]);   // 88

// Modify an element
scores[2] = 100;

// Iterate with a for loop
int size = 5;
for (int i = 0; i < size; i++) {
    printf("scores[%d] = %d\n", i, scores[i]);
}
```

### Key Points

- Arrays are **0-indexed**: first element is at index `0`, last is at `size - 1`
- Accessing out-of-bounds index causes **undefined behavior** (no automatic error)
- The size of an array cannot be changed after declaration (static size)
- To find the number of elements: `sizeof(arr) / sizeof(arr[0])`

```c
int arr[] = {1, 2, 3, 4, 5};
int length = sizeof(arr) / sizeof(arr[0]);   // 5
```

---

## 21. Arrays and User Input

Filling an array with values from the user.

```c
#include <stdio.h>

int main() {
    int n = 5;
    int nums[5];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("nums[%d] = ", i);
        scanf("%d", &nums[i]);
    }

    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
```

---

## 22. 2D Arrays

A 2D array is an array of arrays - like a grid or table with rows and columns.

```c
// Declaration: type name[rows][cols]
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Access: matrix[row][col]
printf("%d\n", matrix[1][2]);   // 6

// Iterate with nested loops
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```

---

## 23. Arrays of Strings

An array of strings is a 2D character array where each row is one string.

```c
#include <stdio.h>

int main() {
    // Array of 3 strings, each up to 20 characters
    char fruits[3][20] = {"Apple", "Banana", "Cherry"};

    for (int i = 0; i < 3; i++) {
        printf("%s\n", fruits[i]);
    }
    return 0;
}
```

### String Functions (from `<string.h>`)

```c
#include <string.h>

strlen(str)           // length of string
strcpy(dest, src)     // copy src into dest
strcat(dest, src)     // append src to dest
strcmp(s1, s2)        // compare; returns 0 if equal
strstr(haystack, needle) // find substring; returns NULL if not found
```

---

## 24. Ternary Operator

A compact shorthand for simple if-else expressions.

```c
// Syntax: condition ? value_if_true : value_if_false

int age = 20;
char *status = (age >= 18) ? "Adult" : "Minor";
printf("%s\n", status);   // Adult

int a = 10, b = 20;
int max = (a > b) ? a : b;
printf("Max: %d\n", max);  // 20
```

- Best used for simple, single-expression conditions
- Avoid nesting ternary operators as it reduces readability

---

## 25. Typedef

`typedef` creates an **alias** (alternate name) for an existing data type, improving code readability.

```c
typedef unsigned long long int ull;
typedef char String[50];

ull bigNumber = 9999999999ULL;
String greeting = "Hello";
```

- Commonly used with `struct` to avoid writing `struct` keyword every time
- Makes code more readable when dealing with complex types

```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {3, 4};
printf("(%d, %d)\n", p.x, p.y);
```

---

## 26. Enums

An **enum** (enumeration) defines a set of named integer constants, making code more readable than using raw numbers.

```c
#include <stdio.h>

typedef enum {
    SUN,    // 0
    MON,    // 1
    TUE,    // 2
    WED,    // 3
    THU,    // 4
    FRI,    // 5
    SAT     // 6
} Day;

int main() {
    Day today = WED;

    if (today == SAT || today == SUN) {
        printf("Weekend!\n");
    } else {
        printf("Weekday\n");
    }

    printf("Day number: %d\n", today);   // 3
    return 0;
}
```

### Key Points

- By default, values start from `0` and increment by `1`
- You can assign custom values: `enum { JAN = 1, FEB, MAR }` starts FEB at 2
- Enums improve code readability by replacing magic numbers with meaningful names

---

## 27. Structs

A **struct** (structure) groups variables of different data types under one name, representing a real-world entity.

```c
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Declare and initialize
    struct Student s1 = {"Aniketh", 20, 8.5};

    // Access members with dot operator
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("GPA: %.2f\n", s1.gpa);

    // Modify a member
    s1.age = 21;

    return 0;
}
```

### With typedef

```c
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

Student s1 = {"Aniketh", 20, 8.5};   // no "struct" keyword needed
```

---

## 28. Arrays of Structs

Store multiple struct instances in an array - useful for managing collections of records.

```c
#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    Student students[3] = {
        {"Alice", 20, 9.0},
        {"Bob",   21, 7.5},
        {"Carol", 19, 8.2}
    };

    for (int i = 0; i < 3; i++) {
        printf("Name: %-10s | Age: %d | GPA: %.2f\n",
               students[i].name, students[i].age, students[i].gpa);
    }
    return 0;
}
```

---

## 29. Pointers

A **pointer** is a variable that stores the **memory address** of another variable.

```c
int age = 25;
int *ptr = &age;   // ptr stores the address of age

printf("Value of age:    %d\n",  age);    // 25
printf("Address of age:  %p\n",  &age);   // memory address
printf("Value of ptr:    %p\n",  ptr);    // same memory address
printf("Dereferenced ptr:%d\n",  *ptr);   // 25 (the value at that address)

// Modify the original variable through the pointer
*ptr = 30;
printf("New age: %d\n", age);   // 30
```

### Key Operators

| Operator | Name | Meaning |
|----------|------|---------|
| `&` | Address-of | Gets the memory address of a variable |
| `*` | Dereference | Gets the value stored at a memory address |

### Pointers and Arrays

Array names act as pointers to the first element:

```c
int arr[] = {10, 20, 30};
int *p = arr;           // points to arr[0]

printf("%d\n", *p);     // 10
printf("%d\n", *(p+1)); // 20
printf("%d\n", *(p+2)); // 30
```

### Pointers and Functions (Pass by Reference)

```c
void doubleValue(int *n) {
    *n = *n * 2;   // modifies the original variable
}

int main() {
    int x = 5;
    doubleValue(&x);
    printf("%d\n", x);   // 10
    return 0;
}
```

- Passing by reference allows functions to modify the original variable
- This is how `scanf` works - it needs an address so it can write to the variable

---

## 30. File I/O - Write

Write data to a file using `fopen`, `fprintf`/`fputs`, and `fclose`.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("output.txt", "w");   // "w" = write (creates/overwrites)

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fptr, "Name: Aniketh\n");
    fprintf(fptr, "Age: %d\n", 20);
    fputs("Hello from C!\n", fptr);

    fclose(fptr);
    printf("File written successfully.\n");
    return 0;
}
```

### File Open Modes

| Mode | Meaning |
|------|---------|
| `"w"` | Write (creates new / overwrites existing) |
| `"a"` | Append (adds to end of existing file) |
| `"r"` | Read |
| `"w+"` | Write + Read |
| `"a+"` | Append + Read |

- Always check if `fopen` returned `NULL` (file could not be opened)
- Always call `fclose()` to flush the buffer and release the file

---

## 31. File I/O - Read

Read data from a file using `fopen`, `fscanf`/`fgets`, and `fclose`.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("output.txt", "r");

    if (fptr == NULL) {
        printf("File not found.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line);    // fgets keeps the \n character
    }

    fclose(fptr);
    return 0;
}
```

- `fgets(buffer, size, stream)` reads one line at a time, including `\n`
- Returns `NULL` when end-of-file (EOF) is reached
- `fscanf` works like `scanf` but reads from a file

---

## 32. Dynamic Memory - malloc

`malloc` (memory allocate) allocates a block of **uninitialized** memory on the **heap** at runtime.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*) malloc(n * sizeof(int));   // allocate 5 ints

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize manually (values are garbage otherwise)
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);   // always free allocated memory
    arr = NULL;  // good practice to prevent dangling pointer
    return 0;
}
```

### Key Points

- `malloc(bytes)` returns a `void*` pointer; cast to the required type
- Always check the return value for `NULL` (allocation failure)
- `malloc` does NOT initialize memory; values are garbage
- **Always call `free()`** when done to prevent memory leaks

---

## 33. Dynamic Memory - calloc

`calloc` (contiguous allocate) allocates memory for an array and **initializes all bytes to zero**.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    // calloc(number_of_elements, size_of_each_element)
    int *arr = (int*) calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // All values are 0 (already initialized)
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);   // 0 0 0 0 0
    }

    free(arr);
    return 0;
}
```

### malloc vs calloc

| Feature | `malloc` | `calloc` |
|---------|---------|---------|
| Syntax | `malloc(total_bytes)` | `calloc(n, size)` |
| Initializes memory | No (garbage values) | Yes (all zeros) |
| Performance | Slightly faster | Slightly slower (due to zeroing) |

---

## 34. Dynamic Memory - realloc

`realloc` (reallocate) **resizes** a previously allocated block of memory.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) arr[i] = i + 1;

    // Grow the array to hold 10 elements
    arr = (int*) realloc(arr, 10 * sizeof(int));

    if (arr == NULL) {
        printf("Reallocation failed.\n");
        return 1;
    }

    for (int i = 5; i < 10; i++) arr[i] = i + 1;

    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}
```

### Key Points

- `realloc(ptr, new_size)` returns a new pointer; the old block may be moved
- Existing data is preserved up to the minimum of old and new size
- If `realloc` returns `NULL`, the **original pointer is still valid**; do not overwrite it directly:

```c
// Safe realloc pattern
int *temp = (int*) realloc(arr, new_size * sizeof(int));
if (temp == NULL) {
    // arr is still valid, handle error
    free(arr);
    return 1;
}
arr = temp;
```

---

## Practice Projects in the Course

| Project | Key Concepts Used |
|---------|------------------|
| Shopping Cart | Variables, user input, arithmetic |
| Mad Libs Game | Strings, user input, printf |
| Circle Calculator | Math functions, floats |
| Compound Interest Calculator | Math functions, loops |
| Weight Converter | if-else, user input |
| Temperature Converter | if-else, floats |
| Calculator | switch, user input |
| Number Guessing Game | while loop, random numbers, if-else |
| Rock Paper Scissors | switch, random numbers, if-else |
| Banking Program | loops, if-else, functions |
| Quiz Game | arrays of strings, loops, scoring |
| Digital Clock | structs, loops, system time |

---

## Quick Reference

### Header Files

| Header | Purpose |
|--------|---------|
| `<stdio.h>` | `printf`, `scanf`, file I/O |
| `<stdlib.h>` | `malloc`, `calloc`, `realloc`, `free`, `rand`, `srand` |
| `<string.h>` | `strlen`, `strcpy`, `strcmp`, `strcat` |
| `<math.h>` | `sqrt`, `pow`, `ceil`, `floor`, `round` |
| `<time.h>` | `time()` for seeding random numbers |
| `<stdbool.h>` | `bool`, `true`, `false` |

### Common Compilation Commands

```bash
# Basic compile
gcc main.c -o main

# Compile with math library
gcc main.c -o main -lm

# Compile with warnings enabled (recommended)
gcc main.c -o main -Wall -Wextra

# Run
./main          # Linux/Mac
main.exe        # Windows
```

### Escape Characters

| Sequence | Meaning |
|----------|---------|
| `\n` | Newline |
| `\t` | Tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |
| `\0` | Null character (string terminator) |

---

*Notes based on Bro Code C Programming Full Course*

---

## Source

YouTube video: [C Programming Full Course for free - Bro Code](https://www.youtube.com/watch?v=xND0t1pr3KY)

## Note

This README was created with the help of Perplexity(Claude Sonnet 4.6 Thinking) because I was lazy.
