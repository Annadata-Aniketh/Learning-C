#include<stdio.h>
#include<ctype.h>
int main()
{
    char questions[][100] = {"\n1. What is the largest planet in our solar system?\n",
                             "\n2. What is the hottest planet in our solar system?\n",
                             "\n3. Which planet of our solar system has the most number of moons?\n",
                             "\n4. Is the Earth flat?\n"};
    char options[][100] = {"\nA. Mercury\nB. Jupiter\nC. Earth\nD. Saturn\n",
                           "\nA. Mercury\nB. Jupiter\nC. Earth\nD. Venus\n",
                           "\nA. Mercury\nB. Jupiter\nC. Earth\nD. Saturn\n",
                           "\nA. Yes\nB. No\nC. Maybe\nD. May not be\n"};
    char answerKey[] = {'B','D','D','B'};
    char guess = '\0';
    int score = 0;

    for(int i = 0; i < (sizeof(questions)/sizeof(questions[0])); i++)
    {
        printf("%s", questions[i]);
        printf("%s", options[i]);
        printf("Enter your choice: ");
        scanf(" %c", &guess);
        guess = toupper(guess);
        if(guess == answerKey[i])
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong!\n");
        }
    }
    printf("Your score is %d / %d.\n",score, (int)(sizeof(questions)/sizeof(questions[0])));
    return 0;
}