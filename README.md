⚙️ C Programming Full Course - Comprehensive Guide

Welcome to the ultimate reference guide for C Programming, based on Bro Code's full tutorial. This repository acts as a detailed encyclopedia of C syntax, paradigms, and memory management concepts, skipping the IDE setup and diving straight into the code.

📖 Table of Contents

Variables

Format Specifiers

Arithmetic Operators

User Input

Math Functions

If Statements & Switches

Logical Operators

Functions, Return & Variable Scope

Loops (While, For, Nested)

Break & Continue

Random Numbers

Arrays (1D, 2D, & Strings)

Ternary Operator

Typedef & Enums

Structs & Arrays of Structs

Pointers

File I/O (Read & Write)

Dynamic Memory (malloc, calloc, realloc)

Course Projects Directory

1. Variables

Variables are allocated memory blocks (reusable containers) used to store data. C is statically typed.

#include <stdio.h>       
#include <stdbool.h>     // Required for booleans

int main() {
    int age = 25;                  // Integer (Whole number)
    float gpa = 3.14f;             // Floating-point number (32-bit, single precision)
    double pi = 3.1415926535;      // Double precision float (64-bit, 15-16 digits)
    char grade = 'A';              // Single character (single quotes)
    char name[] = "Bro Code";      // String (Array of characters in double quotes)
    bool isStudent = true;         // Boolean (1 = true, 0 = false)
    
    return 0; // Return 0 indicates the program ran successfully
}


2. Format Specifiers

Used alongside printf() and scanf() to output or read formatted data.

%d or %i = Integer

%f = Float

%lf = Double (Long Float)

%c = Character

%s = String (Array of characters)

%p = Pointer (Memory Address)

Formatting Output:

%.2f: Decimal precision (e.g., 3.14).

%10d: Minimum width of 10 characters (Right-justified).

%-10d: Minimum width of 10 characters (Left-justified).

%05d: Zero-padding (e.g., 00042).

3. Arithmetic Operators

Basic: + (add), - (subtract), * (multiply), / (divide), % (modulus - returns the remainder).

Integer Division: 5 / 2 yields 2. To retain decimal portions, at least one number must be a float (5.0 / 2).

Increment/Decrement: ++ (adds 1), -- (subtracts 1). Useful for loop counters.

Augmented Assignment: x += 2, x -= 2, x *= 2, x /= 2.

4. User Input

scanf (For singular words or numbers)

Reads formatted input. Requires the address-of operator (&) for primitive data types.

int age;
printf("Enter your age: ");
scanf("%d", &age); // Inserts value at the memory address of 'age'


Trap: scanf leaves a newline character (\n) in the input buffer. When reading a character after a number, clear the buffer by adding a space before %c: scanf(" %c", &grade);

fgets (For strings with spaces)

Unlike scanf, fgets reads entire lines of text including whitespace.

#include <string.h>

char name[50];
printf("Enter your full name: ");
fgets(name, sizeof(name), stdin);

// fgets automatically includes the 'Enter' key (\n). Remove it:
name[strlen(name) - 1] = '\0'; 


5. Math Functions

Include the <math.h> header file to access advanced mathematical functions:

sqrt(x): Square root

pow(base, exp): Raises base to a given power

round(x): Rounds to nearest integer

ceil(x): Rounds up to nearest integer

floor(x): Rounds down to nearest integer

abs(x): Absolute value (distance from zero)

log(x): Natural logarithm

sin(x), cos(x), tan(x): Trigonometry (values in radians)

6. If Statements & Switches

Nested If Statements

Allows for basic decision-making branches based on conditions evaluating to true or false.

if (age >= 18) {
    printf("You are an adult");
} else if (age < 0) {
    printf("You haven't been born yet");
} else {
    printf("You are a child");
}


Switches

A cleaner and more efficient alternative to long else if chains when checking one variable against multiple fixed integers or characters.

switch(grade) {
    case 'A':
        printf("Perfect!");
        break; // MUST include 'break' to avoid executing subsequent cases
    case 'B':
        printf("Good job!");
        break;
    default: // Catch-all if no cases match
        printf("Invalid grade.");
}


7. Logical Operators

Used to combine or modify boolean expressions.

&& (AND): Both conditions must be true.

|| (OR): At least one condition must be true.

! (NOT): Reverses the boolean state (True becomes False).

8. Functions, Return & Variable Scope

Functions are reusable sections of code. This adheres to the DRY (Don't Repeat Yourself) principle.

Function Prototypes: Placed before main() to give the compiler information about the function's name, return type, and parameters. This enables type checking and allows the actual function to be defined after main().

Return Type: A function can send a value back (e.g., int, double) or send nothing (void).

Variable Scope: * Local: Variables defined inside a { scope } are only known inside that block.

Global: Defined outside functions. Any function can modify them, but they are discouraged as they make debugging difficult.

// Prototype
int square(int number); 

int main() {
    int result = square(5); // Sending an "Argument"
    return 0; // Return 0 = Success. Returning 1 = Error exit code.
}

// Definition
int square(int number) { // Receiving a "Parameter"
    return number * number;
}


9. Loops (While, For, Nested)

while Loop: Repeats code as long as the condition remains true. Checked at the start.

do-while Loop: Executes the code block at least once, and checks the condition at the end.

for Loop: Ideal for executing code a limited/known number of times. Structure: for(initialization; condition; update)

Nested Loops: A loop inside a loop (e.g., an outer loop for rows, an inner loop for columns).

10. Break & Continue

Used entirely within loops or switches to control flow.

break: Instantly breaks out of the loop completely (like a stop button).

continue: Skips the rest of the current cycle and jumps back to the top of the loop (like a skip button).

11. Random Numbers

C generates pseudo-random numbers using a seed value and an algorithm.

#include <stdlib.h>
#include <time.h>

// Set the seed based on current time (do this ONCE in main)
srand(time(NULL));

// Generate a random number between MIN and MAX
int min = 1;
int max = 100;
int answer = (rand() % max) + min; 


12. Arrays (1D, 2D, & Strings)

A fixed-size contiguous collection of identical data types.

1D Arrays

int prices[5] = {10, 20, 30, 40, 50};
prices[0] = 15; // Reassign index 0

// Dynamically calculating array size:
int size = sizeof(prices) / sizeof(prices[0]); 


Tip: If you declare an array without initializing its values, it holds "garbage" data. Clear it by initializing to zero: int scores[5] = {0};

2D Arrays (Matrices)

An array of arrays. Requires defining the maximum number of columns.

int matrix[2][3] = {
    {1, 2, 3}, // Row 0
    {4, 5, 6}  // Row 1
};


Arrays of Strings

Because a string is a 1D array of characters, an array of strings is technically a 2D array of characters.

// Holds 3 strings, each with a max of 20 characters
char cars[3][20] = {"Mustang", "Corvette", "Camaro"};


13. Ternary Operator

A shorthand if/else statement.
Syntax: (condition) ? return_if_true : return_if_false;

int max = (x > y) ? x : y;
printf("%s", (isOnline) ? "Online" : "Offline");


14. Typedef & Enums

Typedef

Assigns a nickname to an existing data type to simplify complex types or increase readability.

typedef char String[50]; // Creates a 'String' alias
String name = "Bro Code";


Enums (Enumerations)

Creates a user-defined data type representing a set of named integer constants. Great for readability.

enum Status {SUCCESS = 0, FAILURE = 1, PENDING = 2};
enum Status currentStatus = SUCCESS;


15. Structs & Arrays of Structs

Structs

A blueprint for custom containers that hold multiple pieces of related information (C's closest relative to Objects in OOP).

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

Student s1 = {"Spongebob", 30, 2.5f};
printf("%s has a %.2f GPA", s1.name, s1.gpa); // Access via dot operator (.)


Arrays of Structs

Group multiple struct instances into an array to cycle through them programmatically.

Student classRoster[] = {s1, s2, s3};


16. Pointers

Variables that store the memory address of another variable. Pointers are incredibly powerful for passing data by reference, which avoids making heavy copies of structs or arrays.

& = Address-of operator: Returns the physical hex address in memory.

* = Dereference operator: Acts as a "key" to unlock and access the value at the given address.

int age = 25;
int *pAge = &age; // pAge points to the memory address of age

printf("Address: %p\n", pAge);
printf("Value at address: %d\n", *pAge); // Dereferencing yields 25


17. File I/O (Read & Write)

Creating, reading, and writing files using pointers to a FILE struct.

Writing to a File ("w" overwrites, "a" appends)

FILE *pF = fopen("output.txt", "w");
if(pF != NULL) {
    fprintf(pF, "Booty booty booty rocking everywhere");
    fclose(pF); // ALWAYS close a file when finished to free the resource
}


Reading from a File ("r")

FILE *pF = fopen("input.txt", "r");
char buffer[1024]; // A temporary "waiting room" for text chunks

if(pF == NULL) {
    printf("Unable to open file!\n");
} else {
    while(fgets(buffer, 1024, pF) != NULL) {
        printf("%s", buffer); // Print line by line
    }
    fclose(pF);
}


18. Dynamic Memory (malloc, calloc, realloc)

Memory management functions found in <stdlib.h>. They allocate bytes in the heap at runtime, bypassing static array constraints.

malloc(size): Dynamically allocates memory without clearing it (contains garbage values until initialized).

calloc(elements, size): Dynamically allocates memory and automatically zeroes out all bytes (slower, but safer against bugs).

realloc(pointer, new_size): Resizes previously allocated memory block, keeping existing data intact.

CRITICAL: Allocated memory is like a rented apartment. When you're done, you MUST return it to the operating system using free(), and reset the pointer to NULL to avoid dangling pointers and segmentation faults.

#include <stdlib.h>

// Allocate space for 10 integers dynamically
int *scores = malloc(10 * sizeof(int)); 

if (scores == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
}

// Done using memory
free(scores);  
scores = NULL; // Prevent a dangling pointer


19. Course Projects Directory

Throughout the curriculum, all concepts are applied in hands-on practice projects. Below is the mapped project repository structure generated during this course:

📁 Banking_program (Banking_program.c)

📁 Calculator (Calculator.c)

📁 circle_calculator (circle_calculator.c)

📁 compound_interest (compound_interest.c)

📁 Digital_clock (Digital_clock.c)

📁 Happy_new_year_countdown (Happy_new_year_countdown.c)

📄 Madlibs_game.c

📁 Number_Guessing_game (Number_Guessing_game.c)

📁 Quiz_game (Quiz_game.c)

📁 Rock_paper-scissors_game (Rock_paper-scissors_game.c)

📄 Shopping_cart.c

📁 temperature_converter (temperature_converter.c)

📁 weight_converter (weight_converter.c)

Generated based on Bro Code's Comprehensive C Programming Video Course.