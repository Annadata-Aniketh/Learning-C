My first program -
#include <stdio.h>

int main()
{
    // This is my first program.
    /*
    I am learning C from BroCode
    on youtube. I am writing this in a
    multiline comment.
    */
    
    printf("This is my first C program.\n");
    printf("I hope I can learn this language.");
    return 0;
}

->  // use for single line comments and /* */ for multi line comments
->  #include <stdio.h> is a preprocessor directory, mainly tells the compiler to include library to the program
->  main() is the place where program execution starts. Without the main() the program compilation would show an error because there would be no starting point for the program. Some C compilers dont require you to write a return statement, but it is always a good practice to add it to the program. return 0; tells the system that its a succesful operation, and anything other than 0 would mean an unsuccessful operation.


Variable - name give to a storage location mainly to store some kind of data. 
Initialization - data_type variable_name;
Declaration - variable_name = some_value;
Initialization and declaration - data_type variable_name = some_value;

Data Types - tells the compiler the type of data.
int age = 25; - stores integer(whole numbers) value (size - 4 bytes(in modern systems))
float gpa = 7.75; - stores small decimal values(upto 6 decimal places) (size - 4 bytes)
double pi = 3.1415926535; - stores large decimal values(upto 15 decimal places) (size - 8 bytes)
char grade = 'A'; - stores a single character value (size - 1 bytes)
char laptop[] = "MacBook Pro"; - traditionally the is nothing like a string. It is just an array of characters.(collection of characters)
bool isOnline = true; - stores either true or false.(0-False, 1-True)(size - 1 byte). Before you use any boolean value, you need to include the stdbool library or header file.
