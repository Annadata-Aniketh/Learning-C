#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));
    int max = 100;
    int min = 1;
    int guess = 0;
    int tries = 0;
    printf("------------Number Guessing Game------------\n");
    printf("Enter minimum number for guess (other than 0): ");
    scanf("%d", &min);
    printf("Enter maximum number for guess: ");
    scanf("%d", &max);
    int answer = (rand() % (max - min +1)) + min;
    while(guess != answer)
    {
        printf("Guess a number between %d - %d: ", min, max);
        scanf("%d", &guess);
        tries++;
        if(guess<answer)
            printf("Try Higher\n");
        else if(guess>answer)
            printf("Try Lower\n");
        else    
            printf("Correct\n");
    }
    printf("The answer is %d.\n", answer);
    printf("Number of tries: %d\n", tries);
    printf("------------Thank You for Playing------------\n");
    return 0;
}